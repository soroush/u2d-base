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

#ifndef U2D_BODY_HPP
#define U2D_BODY_HPP

#include <stdint.h>
#include <ostream>
#include "../geometry/geometry.hpp"

namespace u2d {

struct body_t {

    struct view_mode_t {
        enum class quality_t: uint8_t {
            high,
            low,
        };
        enum class width_t: uint8_t {
            wide,
            narrow,
            normal
        };
        quality_t quality;
        width_t width;
    };
    struct stamina_t {
        uint32_t stamina;
        uint32_t effort;
        uint32_t capacity;
    };
    struct arm_t {
        bool movable;
        uint32_t expires;
        vector2df target;
        uint32_t count;
    };
    struct focus_t {
        enum class target_t : uint8_t {
            left,
            right,
            none,
        };
        target_t type;
        uint32_t count;
    };
    struct tackle_t {
        uint32_t expires;
        uint32_t count;
    };
    enum class collision_t : uint8_t {
        none,
        ball,
        player,
        post,
    };
    struct foul_t {
        enum class card_t : uint8_t {
            none,
            yellow,
        };
        bool charged;
        card_t card;
    };
    uint16_t sequence;
    view_mode_t view_mode;
    stamina_t stamina;
    u2d::vector2df speed;
    float head_angle;
    uint32_t kick;
    uint32_t dash;
    uint32_t turn;
    uint32_t say;
    uint32_t turn_neck;
    uint32_t catch_;
    uint32_t move;
    uint32_t change_view;
    arm_t arm;
    focus_t focus;
    tackle_t tackle;
    collision_t collision;
    foul_t foul;
};
}

std::ostream& operator<<(std::ostream&, const u2d::body_t&);

#endif // U2D_BODY_HPP
