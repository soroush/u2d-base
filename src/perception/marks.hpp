/*
 libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

 Copyright (c) 2016 Soroush Rabiei <rabiei@tidm.net>

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

#ifndef U2D_MARKS_HPP
#define U2D_MARKS_HPP

#include "../geometry/geometry.hpp"
#include <ostream>

namespace u2d {
struct mark_t {
    mark_t(const std::string& name, const vector2df& position);
    mark_t(const std::string& name, float x, float y);
    std::string name;
    vector2df position;
    static mark_t c;
    static mark_t cb;
    static mark_t b0;
    static mark_t ct;
    static mark_t t0;
    static mark_t br10;
    static mark_t tr10;
    static mark_t br20;
    static mark_t tr20;
    static mark_t br30;
    static mark_t tr30;
    static mark_t br40;
    static mark_t tr40;
    static mark_t br50;
    static mark_t tr50;
    static mark_t rb;
    static mark_t rt;
    static mark_t prb;
    static mark_t prc;
    static mark_t prt;
    static mark_t grb;
    static mark_t gr;
    static mark_t grt;
    static mark_t rb30;
    static mark_t rb20;
    static mark_t rb10;
    static mark_t r0;
    static mark_t rt10;
    static mark_t rt20;
    static mark_t rt30;
    //
    static mark_t bl10;
    static mark_t tl10;
    static mark_t bl20;
    static mark_t tl20;
    static mark_t bl30;
    static mark_t tl30;
    static mark_t bl40;
    static mark_t tl40;
    static mark_t bl50;
    static mark_t tl50;
    static mark_t lb;
    static mark_t lt;
    static mark_t plb;
    static mark_t plc;
    static mark_t plt;
    static mark_t glb;
    static mark_t gl;
    static mark_t glt;
    static mark_t lb30;
    static mark_t lb20;
    static mark_t lb10;
    static mark_t l0;
    static mark_t lt10;
    static mark_t lt20;
    static mark_t lt30;
};
}

std::ostream& operator<<(std::ostream&, const u2d::mark_t&);

#endif // U2D_MARKS_HPP
