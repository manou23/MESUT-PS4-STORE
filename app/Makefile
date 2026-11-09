TITLE       := MESUT PS4 STORE
VERSION     := 1.00
TITLE_ID    := MSTP00001
CONTENT_ID  := IV0000-MSTP00001_00-MESUTPS4STORE001
LIBS        := -lc -lkernel -lc++ -lSceUserService -lSceVideoOut -lScePad -lSceSysmodule -lSDL2
TOOLCHAIN   := $(OO_PS4_TOOLCHAIN)
PROJDIR     := MESUTPS4Store
INTDIR      := $(PROJDIR)/build
CXX         := clang++
LD          := ld.lld
CXXFLAGS    := --target=x86_64-pc-freebsd12-elf -fPIC -funwind-tables -c -isysroot $(TOOLCHAIN) -isystem $(TOOLCHAIN)/include -isystem $(TOOLCHAIN)/include/c++/v1 -I../SDL-PS4/include
LDFLAGS     := -m elf_x86_64 -pie --script $(TOOLCHAIN)/link.x --eh-frame-hdr -L$(TOOLCHAIN)/lib $(LIBS) $(TOOLCHAIN)/lib/crt1.o
all: $(CONTENT_ID).pkg
$(INTDIR):
	mkdir -p $(INTDIR)
$(INTDIR)/main.o: $(PROJDIR)/main.cpp | $(INTDIR)
	$(CXX) $(CXXFLAGS) -o $@ $<
eboot.bin: $(INTDIR)/main.o
	$(LD) $^ -o $(INTDIR)/MESUTPS4Store.elf $(LDFLAGS)
	$(TOOLCHAIN)/bin/linux/create-fself -in=$(INTDIR)/MESUTPS4Store.elf -out=$(INTDIR)/MESUTPS4Store.oelf --eboot eboot.bin --paid 0x3800000000000011
$(CONTENT_ID).pkg: eboot.bin
	$(TOOLCHAIN)/bin/linux/PkgTool.Core sfo_new sce_sys/param.sfo
	$(TOOLCHAIN)/bin/linux/PkgTool.Core sfo_setentry sce_sys/param.sfo APP_TYPE --type Integer --maxsize 4 --value 1
	$(TOOLCHAIN)/bin/linux/PkgTool.Core sfo_setentry sce_sys/param.sfo APP_VER --type Utf8 --maxsize 8 --value '$(VERSION)'
	$(TOOLCHAIN)/bin/linux/PkgTool.Core sfo_setentry sce_sys/param.sfo CATEGORY --type Utf8 --maxsize 4 --value gd
	$(TOOLCHAIN)/bin/linux/PkgTool.Core sfo_setentry sce_sys/param.sfo CONTENT_ID --type Utf8 --maxsize 48 --value '$(CONTENT_ID)'
	$(TOOLCHAIN)/bin/linux/PkgTool.Core sfo_setentry sce_sys/param.sfo TITLE --type Utf8 --maxsize 128 --value '$(TITLE)'
	$(TOOLCHAIN)/bin/linux/PkgTool.Core sfo_setentry sce_sys/param.sfo TITLE_ID --type Utf8 --maxsize 12 --value '$(TITLE_ID)'
	$(TOOLCHAIN)/bin/linux/create-gp4 -out pkg.gp4 --content-id=$(CONTENT_ID) --files eboot.bin sce_sys/param.sfo
	$(TOOLCHAIN)/bin/linux/PkgTool.Core pkg_build pkg.gp4 .
clean:
	rm -rf $(INTDIR) eboot.bin pkg.gp4 $(CONTENT_ID).pkg sce_sys/param.sfo
