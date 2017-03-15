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

#ifndef U2D_VISUAL_OBJECT_HPP
#define U2D_VISUAL_OBJECT_HPP

namespace u2d {
class visual_object {
    public:
        visual_object(float distance, float direction);
        float distance() const;
        float direction() const;
        void set_distance(float distance);
        void set_direction(float direction);
    protected:
        float m_distance;
        float m_direction;
};
}

#endif // U2D_VISUAL_OBJECT_HPP
