#  libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.
#
# Copyright (c) 2016 Soroush Rabiei <rabiei@tidm.ir>
#
# libaraxes is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
# See the file COPYING included with this distribution for more
# information.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

AM_CPPFLAGS = -I$(srcdir)/../src
check_PROGRAMS = \
    geometry \
    positioning
geometry_SOURCES = \
    geometry.cpp \
    cc-intersect.h
positioning_SOURCES = \
    positioning.cpp
LDADD = \
    ../src/libu2d.la \
    -lpthread
dist_data_DATA = \
    circle_intersection.m \
    positioning_error_model.m
TESTS = $(check_PROGRAMS)
