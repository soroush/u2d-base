#ifndef SERVER_PARAM_H
#define SERVER_PARAM_H
#include <QtCore>
#include <QString>

class server_param
{
public:
    server_param();
    static double audio_cut_dist;
    static bool auto_mode;
    static double back_dash_rate;
    static int back_passes;
    static double ball_accel_max;
    static double ball_decay;
    static double ball_rand;
    static double ball_size;
    static double ball_speed_max;
    static double ball_stuck_area;
    static double ball_weight;
    static double catch_ban_cycle;
    static double catch_probability;
    static double catchable_area_l;
    static double catchable_area_w;
    static double ckick_margin;
    static int clang_advice_win; // ?
    static int clang_del_win; // ?
    static int clang_define_win; // ?
    static int clang_info_win; // ?
    static int clang_mess_delay; // ?
    static int clang_mess_per_cycle;
    static int clang_meta_win;
    static int clang_rule_win;
    static int clang_win_size;
    static bool coach;
    static int coach_port;
    static bool coach_w_referee;
    static int connect_wait;
    static int control_radius;
    static int dash_angle_step;
    static double dash_power_rate;
    static int drop_ball_time;
    static int effort_dec;
    static int effort_dec_thr;
    static int effort_inc;
    static int effort_inc_thr;
    static int effort_init;
    static double effort_min;
    static int extra_half_time;
    static double extra_stamina;
    static int forbid_kick_off_offside;
    static int foul_cycles;
    static double foul_detect_probability;
    static int foul_exponent;
    static int free_kick_faults;
    static int freeform_send_period;
    static int freeform_wait_period;
    static int fullstate_l;
    static int fullstate_r;
    static bool game_log_compression;
    static bool game_log_dated;
    static QString game_log_dir;
    static bool game_log_fixed;
    static QString game_log_fixed_name;
    static int game_log_version;
    static int game_over_wait;
    static double goal_width;
    static int goalie_max_moves;
    static bool golden_goal;
    static int half_time;
    static int hear_decay;
    static int hear_inc;
    static int hear_max;
    static int inertia_moment;
};

#endif // SERVER_PARAM_H
