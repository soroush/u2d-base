/*
 libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

 Copyright (c) 2016-2022 Soroush Rabiei <soroush.rabiei@gmail.com>

 U2D is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 See the file COPYING included with this distribution for more
 information.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <u2d/perception//marks.hpp>

u2d::mark_t u2d::mark_t::c   ("c",    +00,   +00);
u2d::mark_t u2d::mark_t::cb  ("cb",   +00,   +34);
u2d::mark_t u2d::mark_t::b0  ("b0",   +00,   +39);
u2d::mark_t u2d::mark_t::ct  ("ct",   +00,   -34);
u2d::mark_t u2d::mark_t::t0  ("t0",   +00,   -39);
u2d::mark_t u2d::mark_t::br10("br10", +10,   +39);
u2d::mark_t u2d::mark_t::tr10("tr10", +10,   -39);
u2d::mark_t u2d::mark_t::br20("br20", +20,   +39);
u2d::mark_t u2d::mark_t::tr20("tr20", +20,   -39);
u2d::mark_t u2d::mark_t::br30("br30", +30,   +39);
u2d::mark_t u2d::mark_t::tr30("tr30", +30,   -39);
u2d::mark_t u2d::mark_t::br40("br40", +40,   +39);
u2d::mark_t u2d::mark_t::tr40("tr40", +40,   -39);
u2d::mark_t u2d::mark_t::br50("br50", +50,   +39);
u2d::mark_t u2d::mark_t::tr50("tr50", +50,   -39);
u2d::mark_t u2d::mark_t::rb  ("rb",   +52.5, +34);
u2d::mark_t u2d::mark_t::rt  ("rt",   +52.5, -34);
u2d::mark_t u2d::mark_t::prb ("prb",  +36,   +20);
u2d::mark_t u2d::mark_t::prc ("prc",  +36,   +00);
u2d::mark_t u2d::mark_t::prt ("prt",  +36,   -20);
u2d::mark_t u2d::mark_t::grb ("grb",  +52.5, +07);
u2d::mark_t u2d::mark_t::gr  ("gr",   +52.5, +00);
u2d::mark_t u2d::mark_t::grt ("grt",  +52.5, -07);
u2d::mark_t u2d::mark_t::rb30("rb30", +57.5, -30);
u2d::mark_t u2d::mark_t::rb20("rb20", +57.5, -20);
u2d::mark_t u2d::mark_t::rb10("rb10", +57.5, -10);
u2d::mark_t u2d::mark_t::r0  ("r0"  , +57.5, +00);
u2d::mark_t u2d::mark_t::rt10("rt10", +57.5, +10);
u2d::mark_t u2d::mark_t::rt20("rt20", +57.5, +20);
u2d::mark_t u2d::mark_t::rt30("rt30", +57.5, +30);
u2d::mark_t u2d::mark_t::bl10("bl10", -10,   +39);
u2d::mark_t u2d::mark_t::tl10("tl10", -10,   -39);
u2d::mark_t u2d::mark_t::bl20("bl20", -20,   +39);
u2d::mark_t u2d::mark_t::tl20("tl20", -20,   -39);
u2d::mark_t u2d::mark_t::bl30("bl30", -30,   +39);
u2d::mark_t u2d::mark_t::tl30("tl30", -30,   -39);
u2d::mark_t u2d::mark_t::bl40("bl40", -40,   +39);
u2d::mark_t u2d::mark_t::tl40("tl40", -40,   -39);
u2d::mark_t u2d::mark_t::bl50("bl50", -50,   +39);
u2d::mark_t u2d::mark_t::tl50("tl50", -50,   -39);
u2d::mark_t u2d::mark_t::lb  ("lb",   -52.5, +34);
u2d::mark_t u2d::mark_t::lt  ("lt",   -52.5, -34);
u2d::mark_t u2d::mark_t::plb ("plb",  -36,   +20);
u2d::mark_t u2d::mark_t::plc ("plc",  -36,   +00);
u2d::mark_t u2d::mark_t::plt ("plt",  -36,   -20);
u2d::mark_t u2d::mark_t::glb ("glb",  -52.5, +07);
u2d::mark_t u2d::mark_t::gl  ("gl",   -52.5, +00);
u2d::mark_t u2d::mark_t::glt ("glt",  -52.5, -07);
u2d::mark_t u2d::mark_t::lb30("lb30", -57.5, -30);
u2d::mark_t u2d::mark_t::lb20("lb20", -57.5, -20);
u2d::mark_t u2d::mark_t::lb10("lb10", -57.5, -10);
u2d::mark_t u2d::mark_t::l0  ("l0"  , -57.5, +00);
u2d::mark_t u2d::mark_t::lt10("lt10", -57.5, +10);
u2d::mark_t u2d::mark_t::lt20("lt20", -57.5, +20);
u2d::mark_t u2d::mark_t::lt30("lt30", -57.5, +30);

u2d::mark_t::mark_t(const std::string& _name, const vector& _position):
    name(_name),
    position(_position) {
}

u2d::mark_t::mark_t(const std::string& _name, float x, float y):
    name(_name),
    position(x, y) {
}

std::ostream& operator<<(std::ostream& os, const u2d::mark_t& f) {
    os << f.name << ' ' << f.position ;
    return os;
}
