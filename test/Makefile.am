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
LDADD = \
    ../src/libu2d.la
check_PROGRAMS = \
    agent_test
#    parser_test
#    perception_test
#    geometry_test
#   connection_test \
# connection_test_SOURCES = \
#    connection.cpp
# geometry_test_SOURCES = \
#    geometry.cpp
#perception_test_SOURCES = \
#    perception.cpp
agent_test_SOURCES = \
    agent.cpp
#parser_test_SOURCES = \
#    parser.cpp
TESTS = $(check_PROGRAMS)
