AUTOMAKE_OPTIONS = subdir-objects
SUBDIRS = network geometry perception parser
AM_CPPFLAGS = -pipe -Wall -Werror --pedantic
lib_LTLIBRARIES = libu2d.la

libu2d_la_SOURCES = \
	agent.cpp
libu2d_la_LDFLAGS = -version-info $(U2D_SO_VERSION)
libu2d_la_LIBADD = \
	network/libu2d_network.la \
	geometry/libu2d_geometry.la \
	parser/libu2d_parser.la \
	perception/libu2d_perception.la

u2d_includedir = $(includedir)/u2d
u2d_libincludedir = $(libdir)/u2d/include
u2d_include_HEADERS =  \
	agent.hpp
