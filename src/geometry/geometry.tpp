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

#include <cmath>

namespace u2d {
typedef vector2d<float> vector2df;
}

template <typename T>
u2d::vector2d<T>::vector2d():
    x {T()},
    y {T()} {
}

template <typename T>
u2d::vector2d<T>::vector2d(const T& _x, const T& _y):
    x {_x},
    y {_y} {
}


template <typename T>
u2d::vector2d<T> operator+(const u2d::vector2d<T>& lhs, const u2d::vector2d<T>& rhs) {
    u2d::vector2d<T> result;
    result.x = lhs.x + rhs.x;
    result.y = lhs.y + rhs.y;
    return result;
}

template <typename T>
u2d::vector2d<T> operator-(const u2d::vector2d<T>& lhs, const u2d::vector2d<T>& rhs) {
    u2d::vector2d<T> result;
    result.x = lhs.x - rhs.x;
    result.y = lhs.y - rhs.y;
    return result;
}

template <typename T>
T u2d::vector2d<T>::length() const {
    return sqrt(x*x + y*y);
}
