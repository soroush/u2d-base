#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "server_param.h"
#include "player_param.h"
#include "player_type.h"
#include "sense_body.h"

class Model
{
public:
    Model();
    enum play_mode_type
    {
        before_kick_off,
        play_on,
        time_over,
        kick_off_l,
        kick_off_r,
        kick_in_l,
        kick_in_r,
        free_kick_l,
        free_kick_r,
        corner_kick_l,
        corner_kick_r,
        goal_kick_l,
        goal_kick_r,
        goal_l,
        goal_r,
        drop_ball,
        offside_l,
        offside_r
    };

    t_server_param server;
    t_player_param player;
    play_mode_type play_mode;
    std::vector<t_player_type> player_types;
    t_sense_body body;

    void testServer();
};


#endif // MODEL_H
