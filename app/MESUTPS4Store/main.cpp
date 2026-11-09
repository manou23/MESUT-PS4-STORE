#include <SDL.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

static const int W=1920, H=1080;
struct Tile { const char* title; const char* category; SDL_Color color; };
static Tile games[] = {
 {"HOME BREW","COMMUNITY",{20,94,170,255}},
 {"TOOLS","UTILITIES",{30,125,155,255}},
 {"THEMES","PERSONALIZE",{93,65,160,255}},
 {"MY PACKAGES","LOCAL FILES",{45,105,85,255}},
 {"FAVORITES","SAVED ITEMS",{150,88,30,255}}
};
static int selected=0, section=0;

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
 text(r,84,105,"HOME BREW AND COMMUNITY LIBRARY",2,muted);
 rect(r,1500,58,330,58,{22,35,54,255}); text(r,1530,78,"ENGLISH PREVIEW",2,white);
 text(r,84,190,"DISCOVER",3,white);
 text(r,84,245,"A STORE EXPERIENCE BUILT FOR YOUR CONSOLE",2,muted);
 // Featured banner
 rect(r,80,310,1760,285,{17,39,67,255}); rect(r,80,310,12,285,blue);
 text(r,135,365,"WELCOME TO MESUT",4,white);
 text(r,138,430,"HOME BREW  /  TOOLS  /  THEMES",2,{167,205,240,255});
 text(r,138,490,"YOUR LIBRARY. YOUR CONSOLE.",2,muted);
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
 text(r,85,990,"D-PAD SELECT     X OPEN     O BACK     OPTIONS SETTINGS",2,muted);
 text(r,1580,990,"VERSION 1.0.0",2,{90,145,205,255});
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
 bool running=true; Uint32 lastMove=0;
 while(running){
  SDL_Event e;
  while(SDL_PollEvent(&e)){
   if(e.type==SDL_QUIT)running=false;
   if(e.type==SDL_KEYDOWN){
    switch(e.key.keysym.sym){
     case SDLK_ESCAPE:case SDLK_BACKSPACE:running=false;break;
     case SDLK_LEFT:case SDLK_a:selected=(selected+4)%5;break;
     case SDLK_RIGHT:case SDLK_d:selected=(selected+1)%5;break;
     case SDLK_RETURN:case SDLK_x:section=selected+1;break;

    }
   }
   if(e.type==SDL_JOYBUTTONDOWN){
    if(e.jbutton.button==0)section=selected+1;
    if(e.jbutton.button==1)section=0;
    if(e.jbutton.button==4)selected=(selected+4)%5;
    if(e.jbutton.button==5)selected=(selected+1)%5;

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
