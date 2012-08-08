####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector --param=ssp-buffer-size=4 -D_FORTIFY_SOURCE=2 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -std=c++0x -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector --param=ssp-buffer-size=4 -D_FORTIFY_SOURCE=2 -Wall -W $(DEFINES)
INCPATH       = -I.
LINK          = g++
LFLAGS        = -Wl,-O1,--sort-common,--as-needed,-z,relro -Wl,-O1
LIBS          = $(SUBLIBS)    
AR            = ar cqs
RANLIB        = 
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = tmp
SOURCES_DIR = src
TARGET_DIR   = bin

####### Files

SOURCES       = $(SOURCES_DIR)/main.cpp \
		$(SOURCES_DIR)/parser/lex.cc \
		$(SOURCES_DIR)/parser/parse.cc \
		$(SOURCES_DIR)/model/model.cpp \
		$(SOURCES_DIR)/model/see.cpp \
		$(SOURCES_DIR)/agent.cpp \
		$(SOURCES_DIR)/geometry/types.cpp \
		$(SOURCES_DIR)/network/connection.cpp 
OBJECTS       = $(OBJECTS_DIR)/main.o \
		$(OBJECTS_DIR)/lex.o \
		$(OBJECTS_DIR)/parse.o \
		$(OBJECTS_DIR)/model.o \
		$(OBJECTS_DIR)/see.o \
		$(OBJECTS_DIR)/agent.o \
		$(OBJECTS_DIR)/types.o \
		$(OBJECTS_DIR)/connection.o

DESTDIR       = /usr/bin
TARGET        = agent

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET_DIR)/$(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

dist: 
	@$(CHK_DIR_EXISTS) .agent1.0.0 || $(MKDIR) .agent1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .agent1.0.0/ && (cd `dirname .agent1.0.0` && $(TAR) agent1.0.0.tar agent1.0.0 && $(COMPRESS) agent1.0.0.tar) && $(MOVE) `dirname .agent1.0.0`/agent1.0.0.tar.gz . && $(DEL_FILE) -r .agent1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

$(OBJECTS_DIR)/main.o: $(SOURCES_DIR)/main.cpp $(SOURCES_DIR)/agent.h \
		$(SOURCES_DIR)/model/model.h \
		$(SOURCES_DIR)/model/server_param.h \
		$(SOURCES_DIR)/model/player_param.h \
		$(SOURCES_DIR)/model/player_type.h \
		$(SOURCES_DIR)/model/sense_body.h \
		$(SOURCES_DIR)/geometry/types.h \
		$(SOURCES_DIR)/parser/Parser.h \
		$(SOURCES_DIR)/parser/Parserbase.h \
		$(SOURCES_DIR)/parser/Scanner.h \
		$(SOURCES_DIR)/parser/Scannerbase.h \
		$(SOURCES_DIR)/network/connection.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/main.o $(SOURCES_DIR)/main.cpp

$(OBJECTS_DIR)/lex.o: $(SOURCES_DIR)/parser/lex.cc $(SOURCES_DIR)/parser/Scanner.ih \
		$(SOURCES_DIR)/parser/Scanner.h \
		$(SOURCES_DIR)/parser/Scannerbase.h \
		$(SOURCES_DIR)/parser/Parser.h \
		$(SOURCES_DIR)/parser/Parserbase.h \
		$(SOURCES_DIR)/model/player_type.h \
		$(SOURCES_DIR)/model/model.h \
		$(SOURCES_DIR)/model/server_param.h \
		$(SOURCES_DIR)/model/player_param.h \
		$(SOURCES_DIR)/model/sense_body.h \
		$(SOURCES_DIR)/geometry/types.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/lex.o $(SOURCES_DIR)/parser/lex.cc

$(OBJECTS_DIR)/parse.o: $(SOURCES_DIR)/parser/parse.cc $(SOURCES_DIR)/parser/Parser.ih \
		$(SOURCES_DIR)/parser/Parser.h \
		$(SOURCES_DIR)/parser/Parserbase.h \
		$(SOURCES_DIR)/parser/Scanner.h \
		$(SOURCES_DIR)/parser/Scannerbase.h \
		$(SOURCES_DIR)/model/player_type.h \
		$(SOURCES_DIR)/agent.h \
		$(SOURCES_DIR)/model/model.h \
		$(SOURCES_DIR)/model/server_param.h \
		$(SOURCES_DIR)/model/player_param.h \
		$(SOURCES_DIR)/model/sense_body.h \
		$(SOURCES_DIR)/geometry/types.h \
		$(SOURCES_DIR)/network/connection.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/parse.o $(SOURCES_DIR)/parser/parse.cc

$(OBJECTS_DIR)/model.o: $(SOURCES_DIR)/model/model.cpp $(SOURCES_DIR)/model/model.h \
		$(SOURCES_DIR)/model/server_param.h \
		$(SOURCES_DIR)/model/player_param.h \
		$(SOURCES_DIR)/model/player_type.h \
		$(SOURCES_DIR)/model/sense_body.h \
		$(SOURCES_DIR)/geometry/types.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/model.o $(SOURCES_DIR)/model/model.cpp

$(OBJECTS_DIR)/see.o: $(SOURCES_DIR)/model/see.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/see.o $(SOURCES_DIR)/model/see.cpp

$(OBJECTS_DIR)/agent.o: $(SOURCES_DIR)/agent.cpp $(SOURCES_DIR)/agent.h \
		$(SOURCES_DIR)/model/model.h \
		$(SOURCES_DIR)/model/server_param.h \
		$(SOURCES_DIR)/model/player_param.h \
		$(SOURCES_DIR)/model/player_type.h \
		$(SOURCES_DIR)/model/sense_body.h \
		$(SOURCES_DIR)/geometry/types.h \
		$(SOURCES_DIR)/parser/Parser.h \
		$(SOURCES_DIR)/parser/Parserbase.h \
		$(SOURCES_DIR)/parser/Scanner.h \
		$(SOURCES_DIR)/parser/Scannerbase.h \
		$(SOURCES_DIR)/network/connection.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/agent.o $(SOURCES_DIR)/agent.cpp

$(OBJECTS_DIR)/types.o: $(SOURCES_DIR)/geometry/types.cpp $(SOURCES_DIR)/geometry/types.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/types.o $(SOURCES_DIR)/geometry/types.cpp

$(OBJECTS_DIR)/connection.o: $(SOURCES_DIR)/network/connection.cpp $(SOURCES_DIR)/network/connection.h \
		$(SOURCES_DIR)/agent.h \
		$(SOURCES_DIR)/model/model.h \
		$(SOURCES_DIR)/model/server_param.h \
		$(SOURCES_DIR)/model/player_param.h \
		$(SOURCES_DIR)/model/player_type.h \
		$(SOURCES_DIR)/model/sense_body.h \
		$(SOURCES_DIR)/geometry/types.h \
		$(SOURCES_DIR)/parser/Parser.h \
		$(SOURCES_DIR)/parser/Parserbase.h \
		$(SOURCES_DIR)/parser/Scanner.h \
		$(SOURCES_DIR)/parser/Scannerbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/connection.o $(SOURCES_DIR)/network/connection.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

