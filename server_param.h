#ifndef SERVER_PARAM_H
#define SERVER_PARAM_H
#include <QtCore>

struct server_param
{
    int audio_cut_dist;
    bool auto_mode;
    double back_dash_rate;
    int back_passes;
    double ball_accel_max;
    double ball_decay;
    double ball_rand;
    double ball_size;
    double ball_speed_max;
    double ball_stuck_area;
    double ball_weight;
    double catch_ban_cycle;
    double catch_probability;
    double catchable_area_l;
    double catchable_area_w;
    double ckick_margin;
    int clang_advice_win; // ?
    int clang_define_win; // ?
    int clang_info_win; // ?
    int clang_mess_delay; // ?
    int clang_mess_per_cycle;
    int clang_meta_win;
    int clang_rule_win;
    int clang_win_size;
    bool coach;
    int coach_port;
    bool coach_w_referee;
    int connect_wait;
    int control_radius;
    int dash_angle_step;
    double dash_power_rate;
    int drop_ball_time;
    int effort_dec;
    int effort_dec_thr;
    int effort_inc;
    int effort_inc_thr;
    int effort_init;
    double effort_min;
    int extra_half_time;
    double extra_stamina;
    int forbid_kick_off_offside;
    int foul_cycles;
};

#endif // SERVER_PARAM_H
