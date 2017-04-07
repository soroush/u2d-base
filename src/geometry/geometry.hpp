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

#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <ostream>
#include <array>

namespace u2d {

struct point  {
    point();
    point(float x, float y);
    float x;
    float y;
};

struct vector : point  {
    vector();
    vector(float x, float y);
    float length() const;
    vector unit() const;
};

struct circle {
    circle(const point& center, float radius);
    circle(float x, float y, float radius);
    point center;
    float radius;
};

const point midpoint(const point& a, const point& b);
const float distance(const point& a, const point& b);
const float squared_distance(const point& a, const point& b);
std::array<u2d::point,2> intersect(const circle& a, const circle& b, bool& i);

}

u2d::vector operator+(const u2d::point& a, const u2d::point& b);
u2d::vector operator-(const u2d::point& a, const u2d::point& b);
u2d::vector operator+(const u2d::vector& a, const u2d::vector& b);
u2d::vector operator-(const u2d::vector& a, const u2d::vector& b);
u2d::vector operator*(const u2d::vector& v, float s);
u2d::vector operator*(float s, const u2d::vector& v);
u2d::vector operator/(const u2d::vector& v, float s);
u2d::point operator+(const u2d::point& a, const u2d::vector& b);
u2d::point operator-(const u2d::point& a, const u2d::vector& b);

std::ostream& operator<<(std::ostream& os, const u2d::vector& v);
std::ostream& operator<<(std::ostream& os, const u2d::point& v);

#endif // GEOMETRY_HPP
