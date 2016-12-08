WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = -Wall -fexceptions
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC) -Iheaders -Isources
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/cs333project

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/cs333project

OBJ_DEBUG = $(OBJDIR_DEBUG)/src/book.o \
	$(OBJDIR_DEBUG)/src/bookApplication.o \
	$(OBJDIR_DEBUG)/src/index.o \
	$(OBJDIR_DEBUG)/src/indexConstants.o \
	$(OBJDIR_DEBUG)/src/page.o \
	$(OBJDIR_DEBUG)/src/words.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/src/book.o \
	$(OBJDIR_RELEASE)/src/bookApplication.o \
	$(OBJDIR_RELEASE)/src/index.o \
	$(OBJDIR_RELEASE)/src/indexConstants.o \
	$(OBJDIR_RELEASE)/src/page.o \
	$(OBJDIR_RELEASE)/src/words.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG)/src || mkdir -p $(OBJDIR_DEBUG)/src

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LDFLAGS_DEBUG) $(LIBDIR_DEBUG) $(OBJ_DEBUG) $(LIB_DEBUG) -o $(OUT_DEBUG)

$(OBJDIR_DEBUG)/src/book.o: src/book.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/book.cpp -o $(OBJDIR_DEBUG)/src/book.o

$(OBJDIR_DEBUG)/src/bookApplication.o: src/bookApplication.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/bookApplication.cpp -o $(OBJDIR_DEBUG)/src/bookApplication.o

$(OBJDIR_DEBUG)/src/index.o: src/index.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/index.cpp -o $(OBJDIR_DEBUG)/src/index.o

$(OBJDIR_DEBUG)/src/indexConstants.o: src/indexConstants.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/indexConstants.cpp -o $(OBJDIR_DEBUG)/src/indexConstants.o

$(OBJDIR_DEBUG)/src/page.o: src/page.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/page.cpp -o $(OBJDIR_DEBUG)/src/page.o

$(OBJDIR_DEBUG)/src/words.o: src/words.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/words.cpp -o $(OBJDIR_DEBUG)/src/words.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)/src

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE)/src || mkdir -p $(OBJDIR_RELEASE)/src

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LDFLAGS_RELEASE) $(LIBDIR_RELEASE) $(OBJ_RELEASE) $(LIB_RELEASE) -o $(OUT_RELEASE)

$(OBJDIR_RELEASE)/src/book.o: src/book.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/book.cpp -o $(OBJDIR_RELEASE)/src/book.o

$(OBJDIR_RELEASE)/src/bookApplication.o: src/bookApplication.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/bookApplication.cpp -o $(OBJDIR_RELEASE)/src/bookApplication.o

$(OBJDIR_RELEASE)/src/index.o: src/index.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/index.cpp -o $(OBJDIR_RELEASE)/src/index.o

$(OBJDIR_RELEASE)/src/indexConstants.o: src/indexConstants.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/indexConstants.cpp -o $(OBJDIR_RELEASE)/src/indexConstants.o

$(OBJDIR_RELEASE)/src/page.o: src/page.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/page.cpp -o $(OBJDIR_RELEASE)/src/page.o

$(OBJDIR_RELEASE)/src/words.o: src/words.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/words.cpp -o $(OBJDIR_RELEASE)/src/words.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)/src

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release
