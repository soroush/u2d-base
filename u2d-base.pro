TEMPLATE = app
CONFIG += console
CONFIG -= qt
TARGET = agent

QMAKE_CXXFLAGS += -std=c++0x

DEPENDPATH = . src

HEADERS +=  parser/Parser.h \
            parser/Parser.ih \
            parser/Parserbase.h \
            parser/Scanner.h \
            parser/Scanner.ih \
            parser/Scannerbase.h \
            # model files
            model/server_param.h \
    src/agent.h \
    src/model/model.h \
    src/model/player_param.h

SOURCES +=  main.cpp \
            parser/lex.cc \
            parser/parse.cc \
            # model files:
    src/model/model.cpp \
    src/agent.cpp

OTHER_FILES +=  parser/scanner.l \
                parser/parser.y \
                parser/rcss.txt \
                parser/test.txt \
                parser/result.txt
