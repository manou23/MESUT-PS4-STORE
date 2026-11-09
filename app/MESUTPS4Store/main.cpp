#include <SDL.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>

static const int W=1920, H=1080;
struct Tile { const char* title; const char* category; SDL_Color color; };
static Tile games[] = {
 {"GAMES","PS4 RETAIL CATALOG",{20,94,170,255}},
 {"HOMEBREW","FREE COMMUNITY",{30,125,155,255}},
 {"TOOLS","UTILITIES",{93,65,160,255}},
 {"MY PACKAGES","LOCAL FILES",{45,105,85,255}},
 {"FAVORITES","SAVED ITEMS",{150,88,30,255}}
};
#include "catalog_generated.h"
static int selected=0, section=0, item=0;
static bool detail=false;

struct CatalogEntry { std::string id, title, type, description, url; };
static std::vector<CatalogEntry> retailCatalog, homebrewCatalog, favoriteCatalog;
static std::vector<std::string> favoriteIds;
static const char* FAVORITES_FILE="/data/mesut_ps4_store_favorites.txt";
static std::string jsonString(const std::string& obj,const char* key){
 std::string needle(1,char(34)); needle+=key; needle+=char(34);
 size_t p=obj.find(needle); if(p==std::string::npos)return "";
 p=obj.find(':',p+needle.size()); if(p==std::string::npos)return "";
 p=obj.find('"',p+1); if(p==std::string::npos)return "";
 std::string out;
 for(++p;p<obj.size();++p){char ch=obj[p];if(ch=='"')break;if(ch==char(92)&&p+1<obj.size()){char e=obj[++p];if(e=='n')out+=' ';else out+=e;}else out+=ch;}
 return out;
}
static void loadCatalog(){
 std::ifstream file("/app0/catalog.json");
 if(!file)return;
 std::string json((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
 std::string itemsKey(1,char(34)); itemsKey+="items"; itemsKey+=char(34);
 size_t p=json.find(itemsKey); if(p==std::string::npos)return;
 p=json.find('[',p); if(p==std::string::npos)return;
 bool quoted=false,escaped=false; int depth=0; size_t start=0;
 for(size_t i=p+1;i<json.size();++i){char ch=json[i];
  if(quoted){if(escaped)escaped=false;else if(ch==char(92))escaped=true;else if(ch=='"')quoted=false;continue;}
  if(ch=='"'){quoted=true;continue;}
  if(ch=='{'){if(depth++==0)start=i;}
  else if(ch=='}'&&depth>0&&--depth==0){
   std::string obj=json.substr(start,i-start+1);
   CatalogEntry e; e.id=jsonString(obj,"id");e.title=jsonString(obj,"title");e.type=jsonString(obj,"type");
   e.description=jsonString(obj,"description");e.url=jsonString(obj,"listing_url");
   if(!e.title.empty()&&e.type=="commercial_game")retailCatalog.push_back(e);
   else if(!e.title.empty()&&e.type=="game")homebrewCatalog.push_back(e);
  }
  else if(ch==']'&&depth==0)break;
 }
}
static void loadFavorites(){
 favoriteIds.clear(); std::ifstream in(FAVORITES_FILE); std::string id;
 while(std::getline(in,id)) if(!id.empty()&&std::find(favoriteIds.begin(),favoriteIds.end(),id)==favoriteIds.end()) favoriteIds.push_back(id);
}
static void saveFavorites(){
 std::ofstream out(FAVORITES_FILE,std::ios::trunc);
 if(!out)return;
 for(const auto& id:favoriteIds) out<<id<<"\\n";
}
static bool isFavorite(const std::string& id){return std::find(favoriteIds.begin(),favoriteIds.end(),id)!=favoriteIds.end();}
static void rebuildFavorites(){
 favoriteCatalog.clear();
 for(const auto& e:retailCatalog) if(isFavorite(e.id)) favoriteCatalog.push_back(e);
 for(const auto& e:homebrewCatalog) if(isFavorite(e.id)) favoriteCatalog.push_back(e);
}
static void toggleFavorite(const CatalogEntry& e){
 if(e.id.empty())return;
 auto it=std::find(favoriteIds.begin(),favoriteIds.end(),e.id);
 if(it==favoriteIds.end())favoriteIds.push_back(e.id);else favoriteIds.erase(it);
 saveFavorites(); rebuildFavorites();
}
static const std::vector<CatalogEntry>& catalogFor(int sec){return sec==1?retailCatalog:(sec==5?favoriteCatalog:homebrewCatalog);}
static int countForSection(int sec){
 if(sec==1)return retailCatalog.empty()?12:(int)retailCatalog.size();
 if(sec==5)return (int)favoriteCatalog.size();
 return homebrewCatalog.empty()?7:(int)homebrewCatalog.size();
}

static SDL_Color white={245,248,255,255}, muted={160,176,198,255}, blue={0,112,209,255};
static void rect(SDL_Renderer*r,int x,int y,int w,int h,SDL_Color c){
 SDL_Rect q={x,y,w,h}; SDL_SetRenderDrawColor(r,c.r,c.g,c.b,c.a); SDL_RenderFillRect(r,&q);
}
static void line(SDL_Renderer*r,int x,int y,int w,int h,SDL_Color c){
 SDL_SetRenderDrawColor(r,c.r,c.g,c.b,c.a); SDL_RenderDrawLine(r,x,y,x+w,y+h);
}
// Compact built-in 5x7 font: no external font asset required for the first preview.
static const unsigned char* glyph(char c){
 static const unsigned char blank[7]={0,0,0,0,0,0,0};
 static const unsigned char A[7]={14,17,17,31,17,17,17},B[7]={30,17,17,30,17,17,30},C[7]={14,17,16,16,16,17,14},D[7]={30,17,17,17,17,17,30},E[7]={31,16,16,30,16,16,31},F[7]={31,16,16,30,16,16,16},G[7]={14,17,16,23,17,17,15},Hh[7]={17,17,17,31,17,17,17},I[7]={14,4,4,4,4,4,14},J[7]={7,2,2,2,18,18,12},K[7]={17,18,20,24,20,18,17},L[7]={16,16,16,16,16,16,31},M[7]={17,27,21,21,17,17,17},N[7]={17,25,21,19,17,17,17},O[7]={14,17,17,17,17,17,14},P[7]={30,17,17,30,16,16,16},Q[7]={14,17,17,17,21,18,13},R[7]={30,17,17,30,20,18,17},S[7]={15,16,16,14,1,1,30},T[7]={31,4,4,4,4,4,4},U[7]={17,17,17,17,17,17,14},V[7]={17,17,17,17,17,10,4},W[7]={17,17,17,21,21,21,10},X[7]={17,17,10,4,10,17,17},Y[7]={17,17,10,4,4,4,4},Z[7]={31,1,2,4,8,16,31},zero[7]={14,17,19,21,25,17,14},one[7]={4,12,4,4,4,4,14},two[7]={14,17,1,2,4,8,31},three[7]={30,1,1,14,1,1,30},four[7]={2,6,10,18,31,2,2},five[7]={31,16,16,30,1,1,30},six[7]={14,16,16,30,17,17,14},seven[7]={31,1,2,4,8,8,8},eight[7]={14,17,17,14,17,17,14},nine[7]={14,17,17,15,1,1,14},dash[7]={0,0,0,31,0,0,0};
 switch(c){case 'A':return A;case 'B':return B;case 'C':return C;case 'D':return D;case 'E':return E;case 'F':return F;case 'G':return G;case 'H':return Hh;case 'I':return I;case 'J':return J;case 'K':return K;case 'L':return L;case 'M':return M;case 'N':return N;case 'O':return O;case 'P':return P;case 'Q':return Q;case 'R':return R;case 'S':return S;case 'T':return T;case 'U':return U;case 'V':return V;case 'W':return W;case 'X':return X;case 'Y':return Y;case 'Z':return Z;case '0':return zero;case '1':return one;case '2':return two;case '3':return three;case '4':return four;case '5':return five;case '6':return six;case '7':return seven;case '8':return eight;case '9':return nine;case '-':return dash;default:return blank;}
}
static void text(SDL_Renderer*r,int x,int y,const char*s,int scale,SDL_Color c){
 SDL_SetRenderDrawColor(r,c.r,c.g,c.b,c.a);
 for(;*s;s++,x+=6*scale){char ch=*s;if(ch>='a'&&ch<='z')ch-=32;const auto*g=glyph(ch);
  for(int yy=0;yy<7;yy++)for(int xx=0;xx<5;xx++)if(g[yy]&(1<<(4-xx))){SDL_Rect p={x+xx*scale,y+yy*scale,scale,scale};SDL_RenderFillRect(r,&p);}
 }
}
static void render(SDL_Renderer*r){
 rect(r,0,0,W,H,{9,15,28,255});
 rect(r,0,0,W,7,blue);
 text(r,82,52,"MESUT PS4 STORE",5,white);
 text(r,84,105,"PS4 GAME DISCOVERY AND HOME LIBRARY",2,muted);
 rect(r,1500,58,330,58,{22,35,54,255}); text(r,1530,78,"DUALSHOCK READY",2,white);
 if(section==5){
  const auto& entries=favoriteCatalog;
  text(r,84,185,"YOUR FAVORITES",3,white);
  text(r,86,232,"SAVED ON THIS CONSOLE",2,muted);
  if(entries.empty()){
   rect(r,90,310,1740,220,{17,39,67,255});
   text(r,145,380,"NO FAVORITES SAVED YET",3,white);
   text(r,145,455,"OPEN A GAME AND PRESS TRIANGLE OR F TO SAVE IT",2,muted);
  }else if(detail&&item<(int)entries.size()){
   rect(r,80,300,1760,430,{17,39,67,255});rect(r,80,300,10,430,blue);
   text(r,135,365,entries[item].title.c_str(),4,white);
   text(r,138,455,"SAVED FAVORITE",2,{167,205,240,255});
   text(r,138,520,"PRESS TRIANGLE OR F TO REMOVE FROM FAVORITES",2,muted);
   text(r,138,625,"O / BACK RETURNS TO THE FAVORITES LIST",2,muted);
  }else{
   int first=item>=10?item-9:0;
   for(int i=0;i<10&&first+i<(int)entries.size();i++){
    int idx=first+i; int y=292+i*62; rect(r,90,y,1740,52,idx==item?SDL_Color{18,75,130,255}:SDL_Color{17,27,43,255});
    text(r,122,y+17,entries[idx].title.c_str(),2,white);
    text(r,1500,y+18,entries[idx].type=="commercial_game"?"RETAIL TITLE":"HOMEBREW",1,{167,205,240,255});
   }
  }
  text(r,85,990,"UP DOWN SELECT     X DETAILS     TRIANGLE REMOVE     O BACK",2,muted);
  return;
 }
 if(section>=3){
  const char* heading=section==3?"TOOLS":(section==4?"MY PACKAGES":"FAVORITES");
  const char* note=section==3?"SYSTEM UTILITIES WILL BE ADDED AFTER API VALIDATION":(section==4?"LOCAL PKG SCANNING AND USB IMPORT ARE NEXT": "SAVE AND MANAGE YOUR FAVORITE CATALOG ITEMS");
  text(r,84,185,heading,3,white);
  rect(r,80,285,1760,430,{17,39,67,255}); rect(r,80,285,10,430,blue);
  text(r,135,365,"MESUT STORE",4,white);
  text(r,138,455,"SECTION INITIALIZED",2,{167,205,240,255});
  text(r,138,520,note,2,muted);
  text(r,138,625,"THIS FEATURE IS NOT ACTIVE IN BUILD 1.0.0 YET",2,muted);
  text(r,85,990,"O BACK TO CATEGORIES",2,muted);
  return;
 }
 if(section>0){
  const bool retail=(section==1);
  const std::vector<CatalogEntry>& entries=catalogFor(section);
  const int fallbackCount=retail?(int)(sizeof(retailGames)/sizeof(retailGames[0])):(int)(sizeof(homebrewGames)/sizeof(homebrewGames[0]));
  const int count=entries.empty()?fallbackCount:(int)entries.size();
  auto titleAt=[&](int idx)->const char*{return entries.empty()?(retail?retailGames[idx]:homebrewGames[idx]):entries[idx].title.c_str();};
  text(r,84,185,retail?"POPULAR PS4 GAMES":"PS4 HOMEBREW GAMES",3,white);
  text(r,86,232,retail?"COMMERCIAL TITLES - OFFICIAL STORE REFERENCES":"COMMUNITY PORTS - CHECK GAME DATA REQUIREMENTS",2,muted);
  if(detail){
   rect(r,80,300,1760,560,{17,39,67,255}); rect(r,80,300,10,560,blue);
   text(r,135,365,titleAt(item),4,white);
   if(retail){
    text(r,138,455,"COMMERCIAL PS4 TITLE",2,{167,205,240,255});
    text(r,138,510,item==1?"FREE LIMITED PREVIEW - OFFICIAL STORE":"OFFICIAL STORE REFERENCE ONLY",2,white);
    text(r,138,585,"NO UNAUTHORIZED PKG MIRRORS ARE INCLUDED",2,muted);
    text(r,138,635,"USE YOUR OWN LEGITIMATE COPY OR OFFICIAL STORE",2,muted);
   }else{
    text(r,138,455,"COMMUNITY-MADE PS4 PORT",2,{167,205,240,255});
    text(r,138,510,"OPEN THE SOURCE LISTING FOR PACKAGE DETAILS",2,white);
    text(r,138,585,"SOME TITLES REQUIRE ORIGINAL GAME DATA",2,muted);
    text(r,138,635,"CHECK LICENSE AND RELEASE STATUS BEFORE INSTALL",2,muted);
   }
   text(r,138,730,"PRESS TRIANGLE OR F TO TOGGLE FAVORITE",2,{167,205,240,255});
   text(r,138,790,"PRESS O / BACK TO RETURN TO THE LIST",2,muted);
  }else{
   int first=item>=10?item-9:0;
   for(int i=0;i<10&&first+i<count;i++){
    int idx=first+i;
    int y=292+i*62;
    SDL_Color c=(idx==item)?SDL_Color{18,75,130,255}:SDL_Color{17,27,43,255};
    rect(r,90,y,1740,52,c);
    text(r,122,y+17,titleAt(idx),2,white);
    if(!entries.empty()&&isFavorite(entries[idx].id))text(r,1370,y+18,"SAVED",1,{255,190,80,255});
    if(retail) text(r,1470,y+18,idx==1?"FREE PREVIEW":"RETAIL TITLE",1,{167,205,240,255});
    else text(r,1470,y+18,"HOMEBREW",1,{167,205,240,255});
   }
  }
  text(r,85,990,"UP DOWN SELECT     X DETAILS     TRIANGLE / F FAVORITE     O BACK",2,muted);
  text(r,1580,990,"MESUT STORE 1.0.1",2,{90,145,205,255});
  return;
 }
 text(r,84,190,"DISCOVER",3,white);
 text(r,84,245,"BROWSE RETAIL GAMES, HOMEBREW AND YOUR OWN PACKAGES",2,muted);
 rect(r,80,310,1760,285,{17,39,67,255}); rect(r,80,310,12,285,blue);
 text(r,135,365,"YOUR PS4 GAME LIBRARY",4,white);
 text(r,138,430,"RETAIL CATALOG  /  HOMEBREW  /  LOCAL PKG",2,{167,205,240,255});
 text(r,138,490,"DISCOVER GAMES AND ORGANIZE YOUR COLLECTION",2,muted);
 rect(r,1460,360,280,180,{0,91,174,255});
 text(r,1515,425,"PS4",6,white); text(r,1510,510,"STORE",2,white);
 text(r,85,655,"BROWSE CATEGORIES",3,white);
 for(int i=0;i<5;i++){
  int x=82+i*354; SDL_Color c=games[i].color;
  rect(r,x,720,322,205,{17,27,43,255});
  rect(r,x,720,322,9,c);
  rect(r,x+20,750,282,95,c);
  rect(r,x+42,782,50,28,{255,255,255,45});
  text(r,x+22,865,games[i].title,2,white);
  text(r,x+22,895,games[i].category,1,muted);
  if(i==selected){rect(r,x-4,716,330,4,blue);rect(r,x-4,925,330,4,blue);rect(r,x-4,716,4,213,blue);rect(r,x+322,716,4,213,blue);}
 }
 text(r,85,990,"D-PAD SELECT     X OPEN     O BACK",2,muted);
 text(r,1580,990,"VERSION 1.0.1",2,{90,145,205,255});
}
int main(int argc,char**argv){
 setvbuf(stdout,nullptr,_IONBF,0);
 if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK|SDL_INIT_GAMECONTROLLER)!=0){std::printf("SDL init error: %s\n",SDL_GetError());return 1;}
 SDL_Window*w=SDL_CreateWindow("MESUT PS4 STORE",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,W,H,0);
 if(!w){SDL_Quit();return 2;}
 SDL_Renderer*r=SDL_CreateRenderer(w,-1,SDL_RENDERER_SOFTWARE);
 if(!r){r=SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(w));}
 if(!r){SDL_DestroyWindow(w);SDL_Quit();return 3;}
 SDL_Joystick*joy=nullptr;
 if(SDL_NumJoysticks()>0)joy=SDL_JoystickOpen(0);
 loadCatalog();
 loadFavorites(); rebuildFavorites();
 bool running=true; Uint32 lastMove=0;
 while(running){
  SDL_Event e;
  while(SDL_PollEvent(&e)){
   if(e.type==SDL_QUIT)running=false;
   if(e.type==SDL_KEYDOWN){
    switch(e.key.keysym.sym){
     case SDLK_ESCAPE:if(section>0){section=0;detail=false;item=0;}else running=false;break; case SDLK_BACKSPACE:if(section>0){if(detail)detail=false;else{section=0;item=0;}}else running=false;break;
     case SDLK_LEFT:case SDLK_a:if(section>0&&!detail){int n=countForSection(section);item=(item+n-1)%n;}else if(section==0)selected=(selected+4)%5;break;
     case SDLK_RIGHT:case SDLK_d:if(section>0&&!detail){int n=countForSection(section);if(n>0)item=(item+1)%n;}else if(section==0)selected=(selected+1)%5;break;
     case SDLK_UP:if(section>0&&!detail){int n=countForSection(section);if(n>0)item=(item+n-1)%n;}break;
     case SDLK_DOWN:if(section>0&&!detail){int n=countForSection(section);if(n>0)item=(item+1)%n;}break;
     case SDLK_RETURN:case SDLK_x:if(section==0){section=selected+1;item=0;detail=false;}else if(section==5){if(item<(int)favoriteCatalog.size())detail=!detail;}else detail=!detail;break;
     case SDLK_f:case SDLK_y:if(section==1||section==2){const auto& list=catalogFor(section);if(item<(int)list.size())toggleFavorite(list[item]);}else if(section==5&&item<(int)favoriteCatalog.size()){toggleFavorite(favoriteCatalog[item]);if(item>=(int)favoriteCatalog.size())item=(int)favoriteCatalog.size()-1;if(item<0)item=0;}break;

    }
   }
   if(e.type==SDL_JOYBUTTONDOWN){
    if(e.jbutton.button==0){if(section==0){section=selected+1;item=0;detail=false;}else detail=!detail;}
    if(e.jbutton.button==3){if(section==1||section==2){const auto& list=catalogFor(section);if(item<(int)list.size())toggleFavorite(list[item]);}else if(section==5&&item<(int)favoriteCatalog.size()){toggleFavorite(favoriteCatalog[item]);if(item>=(int)favoriteCatalog.size())item=(int)favoriteCatalog.size()-1;if(item<0)item=0;}}
    if(e.jbutton.button==1){if(section>0){if(detail)detail=false;else{section=0;item=0;}}}
    if(e.jbutton.button==4){if(section>0&&!detail){int n=countForSection(section);if(n>0)item=(item+n-1)%n;}else if(section==0)selected=(selected+4)%5;}
    if(e.jbutton.button==5){if(section>0&&!detail){int n=section==1?(retailCatalog.empty()?12:(int)retailCatalog.size()):(homebrewCatalog.empty()?7:(int)homebrewCatalog.size());item=(item+1)%n;}else if(section==0)selected=(selected+1)%5;}

   }
   if(e.type==SDL_JOYAXISMOTION&&SDL_GetTicks()-lastMove>180){
    if(e.jaxis.axis==0&&e.jaxis.value>16000){selected=(selected+1)%5;lastMove=SDL_GetTicks();}
    if(e.jaxis.axis==0&&e.jaxis.value< -16000){selected=(selected+4)%5;lastMove=SDL_GetTicks();}
   }
  }
  render(r);
  SDL_RenderPresent(r);
  SDL_Delay(16);
 }
 if(joy)SDL_JoystickClose(joy);
 SDL_DestroyRenderer(r);SDL_DestroyWindow(w);SDL_Quit();return 0;
}
