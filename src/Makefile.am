AUTOMAKE_OPTIONS = subdir-objects
AM_CPPFLAGS = -pipe
lib_LTLIBRARIES = libu2d.la
libu2d_la_SOURCES = \
	parser/parse.cc \
	parser/temporary_data.cpp \
	parser/lex.cc \
	network/connection.cpp \
	model/server_param.cpp \
	model/field.cpp \
	model/see.cpp \
	model/model.cpp \
	model/visual-objects/player.cpp \
	model/visual-objects/base-objects.cpp \
	model/visual-objects/ball.cpp \
	model/visual-objects/flag.cpp \
	model/visual-objects/line.cpp \
	geometry/types.cpp \
	agent.cpp
libu2d_la_LDFLAGS = -version-info $(U2D_SO_VERSION)
u2d_includedir = $(includedir)/u2d
u2d_libincludedir = $(libdir)/u2d/include
u2d_include_HEADERS =  \
	parser/temporary_data.h \
	parser/Parserbase.h \
	parser/Parser.h \
	parser/Parser.ih \
	parser/Scanner.ih \
	parser/Scanner.h \
	parser/Scannerbase.h \
	network/connection.h \
	agent.h \
	model/model.h \
	model/field.h \
	model/server_param.h \
	model/player_param.h \
	model/see.h \
	model/sense_body.h \
	model/player_type.h \
	model/visual-objects/ball.h \
	model/visual-objects/base-objects.h \
	model/visual-objects/line.h \
	model/visual-objects/flag.h \
	model/visual-objects/player.h \
	geometry/types.h
