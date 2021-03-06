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

#include "model.hpp"
#include <iostream>

std::string u2d::model_t::play_mode_str() {
    switch (this->play_mode) {
    case play_mode_t::before_kick_off:
        return "before_kick_off";
        break;
    case play_mode_t::play_on:
        return "play_on";
        break;
    case play_mode_t::time_over:
        return "time_over";
        break;
    case play_mode_t::kick_off_l:
        return "kick_off_l";
        break;
    case play_mode_t::kick_off_r:
        return "kick_off_r";
        break;
    case play_mode_t::kick_in_l:
        return " kick_in_l";
        break;
    case play_mode_t::kick_in_r:
        return "kick_in_r";
        break;
    case play_mode_t::free_kick_l:
        return "free_kick_l";
        break;
    case play_mode_t::free_kick_r:
        return "free_kick_r";
        break;
    case play_mode_t::corner_kick_l:
        return "corner_kick_l";
        break;
    case play_mode_t::corner_kick_r:
        return "corner_kick_r";
        break;
    case play_mode_t::goal_kick_l:
        return "goal_kick_l";
        break;
    case play_mode_t::goal_kick_r:
        return "goal_kick_r";
        break;
    case play_mode_t::goal_l:
        return "goal_l";
        break;
    case play_mode_t::goal_r:
        return "goal_r";
        break;
    case play_mode_t::drop_ball:
        return "drop_ball";
        break;
    case play_mode_t::offside_l:
        return "offside_l";
        break;
    case play_mode_t::offside_r:
        return "offside_r";
        break;
    }
    return "unknown_mode";
}

// u2d::model::model() {
// }

// void u2d::model::testServer() {
//  cout << "server.audio_cut_dist " << server.audio_cut_dist << endl;
//  cout << "server.auto_mode " << server.auto_mode << endl;
//  cout << "server.back_dash_rate " << server.back_dash_rate << endl;
//  cout << "server.back_passes " << server.back_passes << endl;
//  cout << "server.ball_accel_max " << server.ball_accel_max << endl;
//  cout << "server.ball_decay " << server.ball_decay << endl;
//  cout << "server.ball_rand " << server.ball_rand << endl;
//  cout << "server.ball_size " << server.ball_size << endl;
//  cout << "server.ball_speed_max " << server.ball_speed_max << endl;
//  cout << "server.ball_stuck_area " << server.ball_stuck_area << endl;
//  cout << "server.ball_weight " << server.ball_weight << endl;
//  cout << "server.catch_ban_cycle " << server.catch_ban_cycle << endl;
//  cout << "server.catch_probability " << server.catch_probability << endl;
//  cout << "server.catchable_area_l " << server.catchable_area_l << endl;
//  cout << "server.catchable_area_w " << server.catchable_area_w << endl;
//  cout << "server.ckick_margin " << server.ckick_margin << endl;
//  cout << "server.clang_advice_win " << server.clang_advice_win << endl;
//  cout << "server.clang_define_win " << server.clang_define_win << endl;
//  cout << "server.clang_del_win " << server.clang_del_win << endl;
//  cout << "server.clang_info_win " << server.clang_info_win << endl;
//  cout << "server.clang_mess_delay " << server.clang_mess_delay << endl;
//  cout << "server.clang_mess_per_cycle " << server.clang_mess_per_cycle
//          << endl;
//  cout << "server.clang_meta_win " << server.clang_meta_win << endl;
//  cout << "server.clang_rule_win " << server.clang_rule_win << endl;
//  cout << "server.clang_win_size " << server.clang_win_size << endl;
//  cout << "server.coach " << server.coach << endl;
//  cout << "server.coach_port " << server.coach_port << endl;
//  cout << "server.coach_w_referee " << server.coach_w_referee << endl;
//  cout << "server.connect_wait " << server.connect_wait << endl;
//  cout << "server.control_radius " << server.control_radius << endl;
//  cout << "server.dash_angle_step " << server.dash_angle_step << endl;
//  cout << "server.dash_power_rate " << server.dash_power_rate << endl;
//  cout << "server.drop_ball_time " << server.drop_ball_time << endl;
//  cout << "server.effort_dec " << server.effort_dec << endl;
//  cout << "server.effort_dec_thr " << server.effort_dec_thr << endl;
//  cout << "server.effort_inc " << server.effort_inc << endl;
//  cout << "server.effort_inc_thr " << server.effort_inc_thr << endl;
//  cout << "server.effort_init " << server.effort_init << endl;
//  cout << "server.effort_min " << server.effort_min << endl;
//  cout << "server.extra_half_time " << server.extra_half_time << endl;
//  cout << "server.extra_stamina " << server.extra_stamina << endl;
//  cout << "server.forbid_kick_off_offside " << server.forbid_kick_off_offside
//          << endl;
//  cout << "server.foul_cycles " << server.foul_cycles << endl;
//  cout << "server.foul_detect_probability " << server.foul_detect_probability
//          << endl;
//  cout << "server.foul_exponent " << server.foul_exponent << endl;
//  cout << "server.free_kick_faults " << server.free_kick_faults << endl;
//  cout << "server.freeform_send_period " << server.freeform_send_period
//          << endl;
//  cout << "server.freeform_wait_period " << server.freeform_wait_period
//          << endl;
//  cout << "server.fullstate_l " << server.fullstate_l << endl;
//  cout << "server.fullstate_r " << server.fullstate_r << endl;
//  cout << "server.game_log_compression " << server.game_log_compression
//          << endl;
//  cout << "server.game_log_dated " << server.game_log_dated << endl;
//  cout << "server.game_log_dir " << server.game_log_dir << endl;
//  cout << "server.game_log_fixed " << server.game_log_fixed << endl;
//  cout << "server.game_log_fixed_name " << server.game_log_fixed_name << endl;
//  cout << "server.game_log_version " << server.game_log_version << endl;
//  cout << "server.game_logging " << server.game_logging << endl;
//  cout << "server.game_over_wait " << server.game_over_wait << endl;
//  cout << "server.goal_width " << server.goal_width << endl;
//  cout << "server.goalie_max_moves " << server.goalie_max_moves << endl;
//  cout << "server.golden_goal " << server.golden_goal << endl;
//  cout << "server.half_time " << server.half_time << endl;
//  cout << "server.hear_decay " << server.hear_decay << endl;
//  cout << "server.hear_inc " << server.hear_inc << endl;
//  cout << "server.hear_max " << server.hear_max << endl;
//  cout << "server.inertia_moment " << server.inertia_moment << endl;
//  cout << "server.keepaway " << server.keepaway << endl;
//  cout << "server.keepaway_length " << server.keepaway_length << endl;
//  cout << "server.keepaway_log_dated " << server.keepaway_log_dated << endl;
//  cout << "server.keepaway_log_dir " << server.keepaway_log_dir << endl;
//  cout << "server.keepaway_log_fixed " << server.keepaway_log_fixed << endl;
//  cout << "server.keepaway_log_fixed_name " << server.keepaway_log_fixed_name
//          << endl;
//  cout << "server.keepaway_logging " << server.keepaway_logging << endl;
//  cout << "server.keepaway_start " << server.keepaway_start << endl;
//  cout << "server.keepaway_width " << server.keepaway_width << endl;
//  cout << "server.kick_off_wait " << server.kick_off_wait << endl;
//  cout << "server.kick_power_rate " << server.kick_power_rate << endl;
//  cout << "server.kick_rand " << server.kick_rand << endl;
//  cout << "server.kick_rand_factor_l " << server.kick_rand_factor_l << endl;
//  cout << "server.kick_rand_factor_r " << server.kick_rand_factor_r << endl;
//  cout << "server.kickable_margin " << server.kickable_margin << endl;
//  cout << "server.landmark_file " << server.landmark_file << endl;
//  cout << "server.log_date_format " << server.log_date_format << endl;
//  cout << "server.log_times " << server.log_times << endl;
//  cout << "server.max_back_tackle_power " << server.max_back_tackle_power
//          << endl;
//  cout << "server.max_dash_angle " << server.max_dash_angle << endl;
//  cout << "server.max_dash_power " << server.max_dash_power << endl;
//  cout << "server.max_goal_kicks " << server.max_goal_kicks << endl;
//  cout << "server.max_tackle_power " << server.max_tackle_power << endl;
//  cout << "server.maxmoment " << server.maxmoment << endl;
//  cout << "server.maxneckang " << server.maxneckang << endl;
//  cout << "server.maxneckmoment " << server.maxneckmoment << endl;
//  cout << "server.maxpower " << server.maxpower << endl;
//  cout << "server.min_dash_angle " << server.min_dash_angle << endl;
//  cout << "server.min_dash_power " << server.min_dash_power << endl;
//  cout << "server.minmoment " << server.minmoment << endl;
//  cout << "server.minneckang " << server.minneckang << endl;
//  cout << "server.minneckmoment " << server.minneckmoment << endl;
//  cout << "server.minpower " << server.minpower << endl;
//  cout << "server.nr_extra_halfs " << server.nr_extra_halfs << endl;
//  cout << "server.nr_normal_halfs " << server.nr_normal_halfs << endl;
//  cout << "server.offside_active_area_size "
//          << server.offside_active_area_size << endl;
//  cout << "server.offside_kick_margin " << server.offside_kick_margin << endl;
//  cout << "server.olcoach_port " << server.olcoach_port << endl;
//  cout << "server.old_coach_hear " << server.old_coach_hear << endl;
//  cout << "server.pen_allow_mult_kicks " << server.pen_allow_mult_kicks
//          << endl;
//  cout << "server.pen_before_setup_wait " << server.pen_before_setup_wait
//          << endl;
//  cout << "server.pen_coach_moves_players " << server.pen_coach_moves_players
//          << endl;
//  cout << "server.pen_dist_x " << server.pen_dist_x << endl;
//  cout << "server.pen_max_extra_kicks " << server.pen_max_extra_kicks << endl;
//  cout << "server.pen_max_goalie_dist_x " << server.pen_max_goalie_dist_x
//          << endl;
//  cout << "server.pen_nr_kicks " << server.pen_nr_kicks << endl;
//  cout << "server.pen_random_winner " << server.pen_random_winner << endl;
//  cout << "server.pen_ready_wait " << server.pen_ready_wait << endl;
//  cout << "server.pen_setup_wait " << server.pen_setup_wait << endl;
//  cout << "server.pen_taken_wait " << server.pen_taken_wait << endl;
//  cout << "server.penalty_shoot_outs " << server.penalty_shoot_outs << endl;
//  cout << "server.player_accel_max " << server.player_accel_max << endl;
//  cout << "server.player_decay " << server.player_decay << endl;
//  cout << "server.player_rand " << server.player_rand << endl;
//  cout << "server.player_size " << server.player_size << endl;
//  cout << "server.player_speed_max " << server.player_speed_max << endl;
//  cout << "server.player_speed_max_min " << server.player_speed_max_min
//          << endl;
//  cout << "server.player_weight " << server.player_weight << endl;
//  cout << "server.point_to_ban " << server.point_to_ban << endl;
//  cout << "server.point_to_duration " << server.point_to_duration << endl;
//  cout << "server.port " << server.port << endl;
//  cout << "server.prand_factor_l " << server.prand_factor_l << endl;
//  cout << "server.prand_factor_r " << server.prand_factor_r << endl;
//  cout << "server.profile " << server.profile << endl;
//  cout << "server.proper_goal_kicks " << server.proper_goal_kicks << endl;
//  cout << "server.quantize_step " << server.quantize_step << endl;
//  cout << "server.quantize_step_l " << server.quantize_step_l << endl;
//  cout << "server.record_messages " << server.record_messages << endl;
//  cout << "server.recover_dec " << server.recover_dec << endl;
//  cout << "server.recover_dec_thr " << server.recover_dec_thr << endl;
//  cout << "server.recover_init " << server.recover_init << endl;
//  cout << "server.recover_min " << server.recover_min << endl;
//  cout << "server.recv_step " << server.recv_step << endl;
//  cout << "server.red_card_probability " << server.red_card_probability
//          << endl;
//  cout << "server.say_coach_cnt_max " << server.say_coach_cnt_max << endl;
//  cout << "server.say_coach_msg_size " << server.say_coach_msg_size << endl;
//  cout << "server.say_msg_size " << server.say_msg_size << endl;
//  cout << "server.send_comms " << server.send_comms << endl;
//  cout << "server.send_step " << server.send_step << endl;
//  cout << "server.send_vi_step " << server.send_vi_step << endl;
//  cout << "server.sense_body_step " << server.sense_body_step << endl;
//  cout << "server.side_dash_rate " << server.side_dash_rate << endl;
//  cout << "server.simulator_step " << server.simulator_step << endl;
//  cout << "server.slow_down_factor " << server.slow_down_factor << endl;
//  cout << "server.slowness_on_top_for_left_team "
//          << server.slowness_on_top_for_left_team << endl;
//  cout << "server.slowness_on_top_for_right_team "
//          << server.slowness_on_top_for_right_team << endl;
//  cout << "server.stamina_capacity " << server.stamina_capacity << endl;
//  cout << "server.stamina_inc_max " << server.stamina_inc_max << endl;
//  cout << "server.stamina_max " << server.stamina_max << endl;
//  cout << "server.start_goal_l " << server.start_goal_l << endl;
//  cout << "server.start_goal_r " << server.start_goal_r << endl;
//  cout << "server.stopped_ball_vel " << server.stopped_ball_vel << endl;
//  cout << "server.synch_micro_sleep " << server.synch_micro_sleep << endl;
//  cout << "server.synch_mode " << server.synch_mode << endl;
//  cout << "server.synch_offset " << server.synch_offset << endl;
//  cout << "server.synch_see_offset " << server.synch_see_offset << endl;
//  cout << "server.tackle_back_dist " << server.tackle_back_dist << endl;
//  cout << "server.tackle_cycles " << server.tackle_cycles << endl;
//  cout << "server.tackle_dist " << server.tackle_dist << endl;
//  cout << "server.tackle_exponent " << server.tackle_exponent << endl;
//  cout << "server.tackle_power_rate " << server.tackle_power_rate << endl;
//  cout << "server.tackle_rand_factor " << server.tackle_rand_factor << endl;
//  cout << "server.tackle_width " << server.tackle_width << endl;
//  cout << "server.team_actuator_noise " << server.team_actuator_noise << endl;
//  cout << "server.team_l_start " << server.team_l_start << endl;
//  cout << "server.team_r_start " << server.team_r_start << endl;
//  cout << "server.text_log_compression " << server.text_log_compression
//          << endl;
//  cout << "server.text_log_dated " << server.text_log_dated << endl;
//  cout << "server.text_log_dir " << server.text_log_dir << endl;
//  cout << "server.text_log_fixed " << server.text_log_fixed << endl;
//  cout << "server.text_log_fixed_name " << server.text_log_fixed_name << endl;
//  cout << "server.text_logging " << server.text_logging << endl;
//  cout << "server.use_offside " << server.use_offside << endl;
//  cout << "server.verbose " << server.verbose << endl;
//  cout << "server.visible_angle " << server.visible_angle << endl;
//  cout << "server.visible_distance " << server.visible_distance << endl;
//  cout << "server.wind_ang " << server.wind_ang << endl;
//  cout << "server.wind_dir " << server.wind_dir << endl;
//  cout << "server.wind_force " << server.wind_force << endl;
//  cout << "server.wind_none " << server.wind_none << endl;
//  cout << "server.wind_rand " << server.wind_rand << endl;
//  cout << "server.wind_random " << server.wind_random << endl;
// }





