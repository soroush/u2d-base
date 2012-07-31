#include "agent.h"
#include <sstream>
using namespace std;

Agent::Agent()
{
    this->parser.setParent(this);
}

void Agent::start()
{
//    inputStream << "(server_param (audio_cut_dist 50)(auto_mode 0)(back_dash_rate 0.6)(back_passes 1)"
//                   "(ball_accel_max 2.7)(ball_decay 0.94)(ball_rand 0.05)(ball_size 0.085)(ball_speed_max 3)"
//                   "(ball_stuck_area 3)(ball_weight 0.2)(catch_ban_cycle 5)(catch_probability 1)"
//                   "(catchable_area_l 2.2)(catchable_area_w 13)(ckick_margin 11)(clang_advice_win 12)"
//                   "(clang_define_win 13)(clang_del_win 14)(clang_info_win 15)(clang_mess_delay 50)(clang_mess_per_cycle 16)"
//                   "(clang_meta_win 17)(clang_rule_win 18)(clang_win_size 300))"
//                   "(coach 0)";
//                   //"(coach_port 6001)(coach_w_referee 0)(connect_wait 300)(control_radius 2)";
//    this->parser.setIstream(inputStream);
    this->parser.setIstream(std::cin);
    this->parser.parse();
    this->model.testServer();
}
