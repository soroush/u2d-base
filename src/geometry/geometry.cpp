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

#include "geometry.hpp"
#include <cmath>
#include <ostream>

u2d::point::point():
    x {float()},
    y {float()} {
}

u2d::point::point(float _x, float _y):
    x {_x},
    y {_y} {
}


// u2d::vector2df operator+(const u2d::vector2d<T>& lhs, const u2d::vector2d<T>& rhs) {
//     u2d::vector2d<T> result;
//     result.x = lhs.x + rhs.x;
//     result.y = lhs.y + rhs.y;
//     return result;
// }

// template <typename T>
// u2d::vector2d<T> operator-(const u2d::vector2d<T>& lhs, const u2d::vector2d<T>& rhs) {
//     u2d::vector2d<T> result;
//     result.x = lhs.x - rhs.x;
//     result.y = lhs.y - rhs.y;
//     return result;
// }

float u2d::vector2df::length() const {
    return std::sqrt(x*x + y*y);
}

u2d::circle::circle(const u2d::point& center_, float radius_):
    center(center_),
    radius(radius_) {
}


u2d::circle::circle(float x, float y, float radius_):
    center(x, y),
    radius(radius_) {
}


const u2d::point u2d::midpoint(const u2d::point& a, const u2d::point& b) {
    return u2d::point((a.x+b.x)/2, (a.y+b.y)/2);
}

const float u2d::distance(const u2d::point& a, const u2d::point& b) {
    return std::sqrt(squared_distance(a,b));
}

const float u2d::squared_distance(const u2d::point& a, const u2d::point& b) {
    return std::pow(a.x-b.x,2) + std::pow(a.y-b.y,2);
}

const std::array<u2d::point,2> u2d::intersect(const u2d::circle& a, const u2d::circle& b) {
    std::array<u2d::point,2> intersect_points;
    const float d2 = squared_distance(a.center, b.center);
    const float d = std::sqrt(d2);
    const float r12 = std::pow(a.radius, 2);
    const float r22 = std::pow(b.radius, 2);
    const float l = (r12 - r22 + d2) / (2*d);
    const float h = std::sqrt(r12 - std::pow(l,2));
    const float termx1 = (1.0/d) * (b.center.x - a.center.x) + a.center.x;
    const float termx2 = (h/d)*(b.center.y - a.center.y);
    const float termy1 = (1.0/d) * (b.center.y - a.center.y) + a.center.y;
    const float termy2 = (h/d)*(b.center.x - a.center.x);
    intersect_points[0].x = termx1 + termx2;
    intersect_points[0].y = termy1 - termy2;
    intersect_points[1].x = termx1 - termx2;
    intersect_points[1].y = termy1 + termy2;
    return intersect_points;
}


std::ostream& operator<<(std::ostream& os, const u2d::vector2df& v) {
    os << '(' << v.x << ',' << v.y << ')';
    return os;
}

