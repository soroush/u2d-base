/*
 libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

 Copyright (c) 2016-2022 Soroush Rabiei <soroush.rabiei@gmail.com>

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

#include <u2d/perception/server_param.hpp>

std::ostream& operator<<(std::ostream& os , const u2d::server_param_t& sp) {
    os << "Server Parameters:" << '\n';
    os << "    audio_cut_dist: " <<sp.audio_cut_dist << '\n';
    os << "    auto_mode: " <<sp.auto_mode << '\n';
    os << "    back_dash_rate: " <<sp.back_dash_rate << '\n';
    os << "    back_passes: " <<sp.back_passes << '\n';
    os << "    ball_accel_max: " <<sp.ball_accel_max << '\n';
    os << "    ball_decay: " <<sp.ball_decay << '\n';
    os << "    ball_rand: " <<sp.ball_rand << '\n';
    os << "    ball_size: " <<sp.ball_size << '\n';
    os << "    ball_speed_max: " <<sp.ball_speed_max << '\n';
    os << "    ball_stuck_area: " <<sp.ball_stuck_area << '\n';
    os << "    ball_weight: " <<sp.ball_weight << '\n';
    os << "    catch_ban_cycle: " <<sp.catch_ban_cycle << '\n';
    os << "    catch_probability: " <<sp.catch_probability << '\n';
    os << "    catchable_area_l: " <<sp.catchable_area_l << '\n';
    os << "    catchable_area_w: " <<sp.catchable_area_w << '\n';
    os << "    ckick_margin: " <<sp.ckick_margin << '\n';
    os << "    clang_advice_win: " <<sp.clang_advice_win << '\n';
    os << "    clang_define_win: " <<sp.clang_define_win << '\n';
    os << "    clang_del_win: " <<sp.clang_del_win << '\n';
    os << "    clang_info_win: " <<sp.clang_info_win << '\n';
    os << "    clang_mess_delay: " <<sp.clang_mess_delay << '\n';
    os << "    clang_mess_per_cycle: " <<sp.clang_mess_per_cycle
              << '\n';
    os << "    clang_meta_win: " <<sp.clang_meta_win << '\n';
    os << "    clang_rule_win: " <<sp.clang_rule_win << '\n';
    os << "    clang_win_size: " <<sp.clang_win_size << '\n';
    os << "    coach: " <<sp.coach << '\n';
    os << "    coach_port: " <<sp.coach_port << '\n';
    os << "    coach_w_referee: " <<sp.coach_w_referee << '\n';
    os << "    connect_wait: " <<sp.connect_wait << '\n';
    os << "    control_radius: " <<sp.control_radius << '\n';
    os << "    dash_angle_step: " <<sp.dash_angle_step << '\n';
    os << "    dash_power_rate: " <<sp.dash_power_rate << '\n';
    os << "    drop_ball_time: " <<sp.drop_ball_time << '\n';
    os << "    effort_dec: " <<sp.effort_dec << '\n';
    os << "    effort_dec_thr: " <<sp.effort_dec_thr << '\n';
    os << "    effort_inc: " <<sp.effort_inc << '\n';
    os << "    effort_inc_thr: " <<sp.effort_inc_thr << '\n';
    os << "    effort_init: " <<sp.effort_init << '\n';
    os << "    effort_min: " <<sp.effort_min << '\n';
    os << "    extra_half_time: " <<sp.extra_half_time << '\n';
    os << "    extra_stamina: " <<sp.extra_stamina << '\n';
    os << "    forbid_kick_off_offside: " <<sp.forbid_kick_off_offside
              << '\n';
    os << "    foul_cycles: " <<sp.foul_cycles << '\n';
    os << "    foul_detect_probability: " <<sp.foul_detect_probability
              << '\n';
    os << "    foul_exponent: " <<sp.foul_exponent << '\n';
    os << "    free_kick_faults: " <<sp.free_kick_faults << '\n';
    os << "    freeform_send_period: " <<sp.freeform_send_period
              << '\n';
    os << "    freeform_wait_period: " <<sp.freeform_wait_period
              << '\n';
    os << "    fullstate_l: " <<sp.fullstate_l << '\n';
    os << "    fullstate_r: " <<sp.fullstate_r << '\n';
    os << "    game_log_compression: " <<sp.game_log_compression
              << '\n';
    os << "    game_log_dated: " <<sp.game_log_dated << '\n';
    os << "    game_log_dir: " <<sp.game_log_dir << '\n';
    os << "    game_log_fixed: " <<sp.game_log_fixed << '\n';
    os << "    game_log_fixed_name: " <<sp.game_log_fixed_name << '\n';
    os << "    game_log_version: " <<sp.game_log_version << '\n';
    os << "    game_logging: " <<sp.game_logging << '\n';
    os << "    game_over_wait: " <<sp.game_over_wait << '\n';
    os << "    goal_width: " <<sp.goal_width << '\n';
    os << "    goalie_max_moves: " <<sp.goalie_max_moves << '\n';
    os << "    golden_goal: " <<sp.golden_goal << '\n';
    os << "    half_time: " <<sp.half_time << '\n';
    os << "    hear_decay: " <<sp.hear_decay << '\n';
    os << "    hear_inc: " <<sp.hear_inc << '\n';
    os << "    hear_max: " <<sp.hear_max << '\n';
    os << "    inertia_moment: " <<sp.inertia_moment << '\n';
    os << "    keepaway: " <<sp.keepaway << '\n';
    os << "    keepaway_length: " <<sp.keepaway_length << '\n';
    os << "    keepaway_log_dated: " <<sp.keepaway_log_dated << '\n';
    os << "    keepaway_log_dir: " <<sp.keepaway_log_dir << '\n';
    os << "    keepaway_log_fixed: " <<sp.keepaway_log_fixed << '\n';
    os << "    keepaway_log_fixed_name: " <<sp.keepaway_log_fixed_name
              << '\n';
    os << "    keepaway_logging: " <<sp.keepaway_logging << '\n';
    os << "    keepaway_start: " <<sp.keepaway_start << '\n';
    os << "    keepaway_width: " <<sp.keepaway_width << '\n';
    os << "    kick_off_wait: " <<sp.kick_off_wait << '\n';
    os << "    kick_power_rate: " <<sp.kick_power_rate << '\n';
    os << "    kick_rand: " <<sp.kick_rand << '\n';
    os << "    kick_rand_factor_l: " <<sp.kick_rand_factor_l << '\n';
    os << "    kick_rand_factor_r: " <<sp.kick_rand_factor_r << '\n';
    os << "    kickable_margin: " <<sp.kickable_margin << '\n';
    os << "    landmark_file: " <<sp.landmark_file << '\n';
    os << "    log_date_format: " <<sp.log_date_format << '\n';
    os << "    log_times: " <<sp.log_times << '\n';
    os << "    max_back_tackle_power: " <<sp.max_back_tackle_power
              << '\n';
    os << "    max_dash_angle: " <<sp.max_dash_angle << '\n';
    os << "    max_dash_power: " <<sp.max_dash_power << '\n';
    os << "    max_goal_kicks: " <<sp.max_goal_kicks << '\n';
    os << "    max_tackle_power: " <<sp.max_tackle_power << '\n';
    os << "    maxmoment: " <<sp.maxmoment << '\n';
    os << "    maxneckang: " <<sp.maxneckang << '\n';
    os << "    maxneckmoment: " <<sp.maxneckmoment << '\n';
    os << "    maxpower: " <<sp.maxpower << '\n';
    os << "    min_dash_angle: " <<sp.min_dash_angle << '\n';
    os << "    min_dash_power: " <<sp.min_dash_power << '\n';
    os << "    minmoment: " <<sp.minmoment << '\n';
    os << "    minneckang: " <<sp.minneckang << '\n';
    os << "    minneckmoment: " <<sp.minneckmoment << '\n';
    os << "    minpower: " <<sp.minpower << '\n';
    os << "    nr_extra_halfs: " <<sp.nr_extra_halfs << '\n';
    os << "    nr_normal_halfs: " <<sp.nr_normal_halfs << '\n';
    os << "    offside_active_area_size "
              <<sp.offside_active_area_size << '\n';
    os << "    offside_kick_margin: " <<sp.offside_kick_margin << '\n';
    os << "    olcoach_port: " <<sp.olcoach_port << '\n';
    os << "    old_coach_hear: " <<sp.old_coach_hear << '\n';
    os << "    pen_allow_mult_kicks: " <<sp.pen_allow_mult_kicks
              << '\n';
    os << "    pen_before_setup_wait: " <<sp.pen_before_setup_wait
              << '\n';
    os << "    pen_coach_moves_players: " <<sp.pen_coach_moves_players
              << '\n';
    os << "    pen_dist_x: " <<sp.pen_dist_x << '\n';
    os << "    pen_max_extra_kicks: " <<sp.pen_max_extra_kicks << '\n';
    os << "    pen_max_goalie_dist_x: " <<sp.pen_max_goalie_dist_x
              << '\n';
    os << "    pen_nr_kicks: " <<sp.pen_nr_kicks << '\n';
    os << "    pen_random_winner: " <<sp.pen_random_winner << '\n';
    os << "    pen_ready_wait: " <<sp.pen_ready_wait << '\n';
    os << "    pen_setup_wait: " <<sp.pen_setup_wait << '\n';
    os << "    pen_taken_wait: " <<sp.pen_taken_wait << '\n';
    os << "    penalty_shoot_outs: " <<sp.penalty_shoot_outs << '\n';
    os << "    player_accel_max: " <<sp.player_accel_max << '\n';
    os << "    player_decay: " <<sp.player_decay << '\n';
    os << "    player_rand: " <<sp.player_rand << '\n';
    os << "    player_size: " <<sp.player_size << '\n';
    os << "    player_speed_max: " <<sp.player_speed_max << '\n';
    os << "    player_speed_max_min: " <<sp.player_speed_max_min
              << '\n';
    os << "    player_weight: " <<sp.player_weight << '\n';
    os << "    point_to_ban: " <<sp.point_to_ban << '\n';
    os << "    point_to_duration: " <<sp.point_to_duration << '\n';
    os << "    port: " <<sp.port << '\n';
    os << "    prand_factor_l: " <<sp.prand_factor_l << '\n';
    os << "    prand_factor_r: " <<sp.prand_factor_r << '\n';
    os << "    profile: " <<sp.profile << '\n';
    os << "    proper_goal_kicks: " <<sp.proper_goal_kicks << '\n';
    os << "    quantize_step: " <<sp.quantize_step << '\n';
    os << "    quantize_step_l: " <<sp.quantize_step_l << '\n';
    os << "    record_messages: " <<sp.record_messages << '\n';
    os << "    recover_dec: " <<sp.recover_dec << '\n';
    os << "    recover_dec_thr: " <<sp.recover_dec_thr << '\n';
    os << "    recover_init: " <<sp.recover_init << '\n';
    os << "    recover_min: " <<sp.recover_min << '\n';
    os << "    recv_step: " <<sp.recv_step << '\n';
    os << "    red_card_probability: " <<sp.red_card_probability << '\n';
    os << "    say_coach_cnt_max: " <<sp.say_coach_cnt_max << '\n';
    os << "    say_coach_msg_size: " <<sp.say_coach_msg_size << '\n';
    os << "    say_msg_size: " <<sp.say_msg_size << '\n';
    os << "    send_comms: " <<sp.send_comms << '\n';
    os << "    send_step: " <<sp.send_step << '\n';
    os << "    send_vi_step: " <<sp.send_vi_step << '\n';
    os << "    sense_body_step: " <<sp.sense_body_step << '\n';
    os << "    side_dash_rate: " <<sp.side_dash_rate << '\n';
    os << "    simulator_step: " <<sp.simulator_step << '\n';
    os << "    slow_down_factor: " <<sp.slow_down_factor << '\n';
    os << "    slowness_on_top_for_left_team " << sp.slowness_on_top_for_left_team << '\n';
    os << "    slowness_on_top_for_right_team " <<sp.slowness_on_top_for_right_team << '\n';
    os << "    stamina_capacity: " <<sp.stamina_capacity << '\n';
    os << "    stamina_inc_max: " <<sp.stamina_inc_max << '\n';
    os << "    stamina_max: " <<sp.stamina_max << '\n';
    os << "    start_goal_l: " <<sp.start_goal_l << '\n';
    os << "    start_goal_r: " <<sp.start_goal_r << '\n';
    os << "    stopped_ball_vel: " <<sp.stopped_ball_vel << '\n';
    os << "    synch_micro_sleep: " <<sp.synch_micro_sleep << '\n';
    os << "    synch_mode: " <<sp.synch_mode << '\n';
    os << "    synch_offset: " <<sp.synch_offset << '\n';
    os << "    synch_see_offset: " <<sp.synch_see_offset << '\n';
    os << "    tackle_back_dist: " <<sp.tackle_back_dist << '\n';
    os << "    tackle_cycles: " <<sp.tackle_cycles << '\n';
    os << "    tackle_dist: " <<sp.tackle_dist << '\n';
    os << "    tackle_exponent: " <<sp.tackle_exponent << '\n';
    os << "    tackle_power_rate: " <<sp.tackle_power_rate << '\n';
    os << "    tackle_rand_factor: " <<sp.tackle_rand_factor << '\n';
    os << "    tackle_width: " <<sp.tackle_width << '\n';
    os << "    team_actuator_noise: " <<sp.team_actuator_noise << '\n';
    os << "    team_l_start: " <<sp.team_l_start << '\n';
    os << "    team_r_start: " <<sp.team_r_start << '\n';
    os << "    text_log_compression: " <<sp.text_log_compression << '\n';
    os << "    text_log_dated: " <<sp.text_log_dated << '\n';
    os << "    text_log_dir: " <<sp.text_log_dir << '\n';
    os << "    text_log_fixed: " <<sp.text_log_fixed << '\n';
    os << "    text_log_fixed_name: " <<sp.text_log_fixed_name << '\n';
    os << "    text_logging: " <<sp.text_logging << '\n';
    os << "    use_offside: " <<sp.use_offside << '\n';
    os << "    verbose: " <<sp.verbose << '\n';
    os << "    visible_angle: " <<sp.visible_angle << '\n';
    os << "    visible_distance: " <<sp.visible_distance << '\n';
    os << "    wind_ang: " <<sp.wind_ang << '\n';
    os << "    wind_dir: " <<sp.wind_dir << '\n';
    os << "    wind_force: " <<sp.wind_force << '\n';
    os << "    wind_none: " <<sp.wind_none << '\n';
    os << "    wind_rand: " <<sp.wind_rand << '\n';
    os << "    wind_random: " <<sp.wind_random << std::endl;
    return os;
}
