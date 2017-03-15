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

#ifndef U2D_PLAYER_PARAM_HPP
#define U2D_PLAYER_PARAM_HPP

#include <ostream>

namespace u2d {

struct player_param_t {
    bool allow_mult_default_type;
    float catchable_area_l_stretch_max;
    float catchable_area_l_stretch_min;
    float dash_power_rate_delta_max;
    float dash_power_rate_delta_min;
    float effort_max_delta_factor;
    float effort_min_delta_factor;
    float extra_stamina_delta_max;
    float extra_stamina_delta_min;
    float foul_detect_probability_delta_factor;
    float inertia_moment_delta_factor;
    float kick_power_rate_delta_max;
    float kick_power_rate_delta_min;
    float kick_rand_delta_factor;
    float kickable_margin_delta_max;
    float kickable_margin_delta_min;
    float new_dash_power_rate_delta_max;
    float new_dash_power_rate_delta_min;
    float new_stamina_inc_max_delta_factor;
    float player_decay_delta_max;
    float player_decay_delta_min;
    float player_size_delta_factor;
    float player_speed_max_delta_max;
    float player_speed_max_delta_min;
    uint8_t player_types;
    uint8_t pt_max;
    float random_seed;
    float stamina_inc_max_delta_factor;
    uint8_t subs_max;
};

}

std::ostream& operator<<(std::ostream&, const u2d::player_param_t&);

#endif // PLAYER_PARAM_HPP
