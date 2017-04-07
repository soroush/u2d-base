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

#include "algebra.hpp"
#include <cmath>

size_t u2d::quadratic_roots(float a, float b, float c, float& x1, float& x2) {
    const float determinant = b*b - 4*a*c;
    if(determinant > 0) {
        x1 = (-b + std::sqrt(determinant)) / (2*a);
        x2 = (-b - std::sqrt(determinant)) / (2*a);
        return 2;
    }
    if(determinant == 0) {
        x1 = x2 = (-b + std::sqrt(determinant)) / (2*a);
        return 1;
    } else {
        // We are not interested in imaginary roots
        return 0;
    }
}

