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

#include <src/geometry/geometry.hpp>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <assert.h>
#include <stdlib.h>

#include "cc-intersect.h"

int main() {
    const size_t count = sizeof(intersects)/sizeof(float);
    static_assert(count%10==0, "Invalid number of elements in data vector.");

    for(size_t i = 0; i < count; i += 10) {
        u2d::circle c1(u2d::point(intersects[i+0], intersects[i+1]), intersects[i+2]);
        u2d::circle c2(u2d::point(intersects[i+3], intersects[i+4]), intersects[i+5]);
        bool found = false;
        auto calculated_intersects = u2d::intersect(c1, c2, found);
        assert(found);
        float error[] = {
            u2d::distance(calculated_intersects[0], u2d::point(intersects[i+6], intersects[i+7])),
            u2d::distance(calculated_intersects[1], u2d::point(intersects[i+8], intersects[i+9])),
        };
        assert(error[0] < 0.01);
        assert(error[1] < 0.01);
    }
    exit(EXIT_SUCCESS);
}

