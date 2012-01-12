#include "parserbase.h"
#include "server_param.h"
#include <iostream>
#include <stdlib.h>

void ParserBase::sp_startRead()
{
    ++i;
    while(input[i]=='(')
    {
        ++i;
        int j=0;
        char value[10];
        switch(input[i])
        {
        case 'a':
            i+=2;
            switch(input[i])
            {
            case 'd':
                i+=12;
                j=0;
                while(input[i]!=')')
                {
                    value[j]=input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                server_param::audio_cut_dist = atof(value);
                std::cout << "audio_cut_dist: " << value << std::endl;
                break;
            case 't':
                i+=8;
                server_param::auto_mode = (input[i]=='0'?false:true);
                std::cout << "auto_mode: " << input[i] << std::endl;
                ++i;
                break;
            }
            break;
        case 'b':
            i+=2;
            switch(input[i])
            {
            case 'c':
                i+=3;
                switch(input[i])
                {
                case 'd':
                    i+=9;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::back_dash_rate = atof(value);
                    std::cout << "back_dash_rate: " << value << std::endl;
                    break;
                case 'p':
                    i+=7;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::back_passes = atoi(value);
                    std::cout << "back_passes: " << value << std::endl;
                    break;
                }
                break;
            case 'l':
                i+=3;
                switch(input[i])
                {
                case 'a':
                    i+=10;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::ball_accel_max = atof(value);
                    std::cout << "ball_accel_max: " << value << std::endl;
                    break;
                case 'd':
                    i+=6;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::ball_decay = atof(value);
                    std::cout << "ball_decay: " << value << std::endl;
                    break;
                case 'r':
                    i+=5;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::ball_rand = atof(value);
                    std::cout << "ball_rand: " << value << std::endl;
                    break;
                case 's':
                    ++i;
                    switch(input[i])
                    {
                    case 'i':
                        i+=4;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::ball_size = atof(value);
                        std::cout << "ball_size: " << value << std::endl;
                        break;
                    case 'p':
                        i+=9;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::ball_speed_max = atof(value);
                        std::cout << "ball_speed_max: " << value << std::endl;
                        break;
                    case 't':
                        i+=10;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::ball_stuck_area = atof(value);
                        std::cout << "ball_stuck_area: " << value << std::endl;
                        break;
                    }
                    break;
                case 'w':
                    i+=7;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    server_param::ball_weight = atof(value);
                    std::cout << "ball_weight: " << value << std::endl;
                    break;
                }
                break;
            }
            break;
        case 'c':
            ++i;
            switch(input[i])
            {
            case 'a':
                i+=4;
                switch(input[i])
                {
                case 'a':
                    i+=10;
                    switch(input[i])
                    {
                    case 'l':
                        i+=2;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::catchable_area_l = atof(value);
                        std::cout << "catchable_area_l: " << value << std::endl;
                        break;
                    case 'w':
                        i+=2;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::catchable_area_w = atof(value);
                        std::cout << "catchable_area_w: " << value << std::endl;
                        break;
                    }
                    break;
                case '_':
                    ++i;
                    switch(input[i])
                    {
                    case 'b':
                        i+=10;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::catch_ban_cycle = atof(value);
                        std::cout << "catch_ban_cycle: " << value << std::endl;
                        break;
                    case 'p':
                        i+=12;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::catch_probability = atof(value);
                        std::cout << "catch_probability: " << value << std::endl;
                        break;
                    }
                    break;
                }
                break;
            case 'k':
                i+=12;
                j=0;
                while(input[i]!=')')
                {
                    value[j]=input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                server_param::ckick_margin = atof(value);
                std::cout << "ckick_margin: " << value << std::endl;
                break;
            case 'l':
                i+=5;
                switch(input[i])
                {
                case 'a':
                    i+=11;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::clang_advice_win = atof(value);
                    std::cout << "clang_advice_win: " << value << std::endl;
                    break;
                case 'd':
                    i+=2;
                    switch(input[i])
                    {
                    case 'f':
                        i+=9;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::clang_define_win = atof(value);
                        std::cout << "clang_define_win: " << value << std::endl;
                        break;
                    case 'l':
                        i+=6;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::clang_del_win = atof(value);
                        std::cout << "clang_del_win: " << value << std::endl;
                        break;
                    }
                    break;
                case 'i':
                    i+=9;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::clang_info_win = atof(value);
                    std::cout << "clang_info_win: " << value << std::endl;
                    break;
                case 'm':
                    i+=5;
                    switch(input[i])
                    {
                    case 'd':
                        i+=6;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::clang_mess_delay = atof(value);
                        std::cout << "clang_mess_delay: " << value << std::endl;
                        break;
                    case 'p':
                        i+=10;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::clang_mess_per_cycle = atof(value);
                        std::cout << "clang_mess_per_cycle: " << value << std::endl;
                        break;
                    case 'w':
                        i+=4;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::clang_meta_win = atof(value);
                        std::cout << "clang_meta_win: " << value << std::endl;
                        break;
                    }
                    break;
                case 'r':
                    i+=9;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    server_param::clang_rule_win = atof(value);
                    std::cout << "clang_rule_win: " << value << std::endl;
                    break;
                case 'w':
                    i+=9;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::clang_win_size = atoi(value);
                    std::cout << "clang_win_size: " << value << std::endl;
                    break;
                }
                break;
            case 'o':
                ++i;
                switch(input[i])
                {
                case 'a':
                    i+=3;
                    switch(input[i])
                    {
                    case '_':
                        ++i;
                        switch(input[i])
                        {
                        case 'p':
                            i+=5;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j]=input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            server_param::coach_port = atoi(value);
                            std::cout << "coach_port: " << value << std::endl;
                            break;
                        case 'w':
                            i+=10;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j]=input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            server_param::coach_w_referee = atof(value);
                            std::cout << "coach_w_referee: " << value << std::endl;
                            break;
                        }
                        break;
                    case ' ':
                        ++i;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::coach = (input[i]=='0'?false:true);
                        std::cout << "coach: " << value<< std::endl;
                        break;
                    }
                    break;
                case 'n':
                    ++i;
                    switch(input[i])
                    {
                    case 'n':
                        i+=10;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::connect_wait = atof(value);
                        std::cout << "connect_wait: " << value << std::endl;
                        break;
                    case 't':
                        i+=12;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::control_radius = atof(value);
                        std::cout << "control_radius: " << value << std::endl;
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 'd':
            ++i;
            switch(input[i])
            {
            case 'a':
                i+=4;
                switch(input[i])
                {
                case 'a':
                    i+=11;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::dash_angle_step = atof(value);
                    std::cout << "dash_angle_step: " << value << std::endl;
                    break;
                case 'p':
                    i+=11;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::dash_power_rate = atof(value);
                    std::cout << "dash_power_rate: " << value << std::endl;
                    break;
                }
                break;
            case 'r':
                i+=14;
                j=0;
                while(input[i]!=')')
                {
                    value[j]=input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                server_param::drop_ball_time = atof(value);
                std::cout << "drop_ball_time: " << value << std::endl;
                break;
            }
            break;
        case 'e':
            ++i;
            switch(input[i])
            {
            case 'f':
                i+=6;
                switch(input[i])
                {
                case 'd':
                    i+=3;
                    switch(input[i])
                    {
                    case ' ':
                        ++i;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::effort_dec = atof(value);
                        std::cout << "effort_dec: " << value << std::endl;
                        break;
                    case '_':
                        i+=5;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::effort_dec_thr = atof(value);
                        std::cout << "effort_dec_thr: " << value << std::endl;
                        break;
                    }
                    break;
                case 'i':
                    i+=3;
                    switch(input[i])
                    {
                    case ' ':
                        ++i;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::effort_inc = atof(value);
                        std::cout << "effort_inc: " << value << std::endl;
                        break;
                    case '_':
                        i+=5;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::effort_inc_thr = atof(value);
                        std::cout << "effort_inc_thr: " << value << std::endl;
                        break;
                    case 't':
                        i+=2;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::effort_init = atof(value);
                        std::cout << "effort_init: " << value/*?*/ << std::endl;
                        break;
                    }
                    break;
                case 'm':
                    i+=4;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::effort_min = atof(value);
                    std::cout << "effort_min: " << value << std::endl;
                    break;
                }
                break;
            case 'x':
                i+=5;
                switch(input[i])
                {
                case 'h':
                    i+=10;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::extra_half_time = atof(value);
                    std::cout << "extra_half_time: " << value << std::endl;
                    break;
                case 's':
                    i+=8;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::extra_stamina = atof(value);
                    std::cout << "extra_stamina: " << value/*?*/ << std::endl;
                }
                break;
            }
            break;
        case 'f':
            ++i;
            switch(input[i])
            {
            case 'o':
                ++i;
                switch(input[i])
                {
                case 'r':
                    i+=22;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::forbid_kick_off_offside = atof(value);
                    std::cout << "forbid_kick_off_offside: " << value << std::endl;
                    break;
                case 'u':
                    i+=3;
                    switch(input[i])
                    {
                    case 'c':
                        i+=7;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::foul_cycles = atof(value);
                        std::cout << "foul_cycles: " << value << std::endl;
                        break;
                    case 'd':
                        i+=19;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::foul_detect_probability = atof(value);
                        std::cout << "foul_detect_probability: " << value << std::endl;
                        break;
                    case 'e':
                        i+=9;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::foul_exponent = atoi(value);
                        std::cout << "foul_exponent: " << value << std::endl;
                        break;
                    }
                    break;
                }
                break;
            case 'r':
                i+=3;
                switch(input[i])
                {
                case '_':
                    i+=13;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::free_kick_faults = atoi(value);
                    std::cout << "free_kick_faults: " << value << std::endl;
                    break;
                case 'f':
                    i+=5;
                    switch(input[i])
                    {
                    case 's':
                        i+=12;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::freeform_send_period = atoi(value);
                        std::cout << "freeform_send_period: " << value << std::endl;
                        break;
                    case 'w':
                        i+=12;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::freeform_wait_period = atoi(value);
                        std::cout << "freeform_wait_period: " << value << std::endl;
                        break;
                    }
                    break;
                }
                break;
            case 'u':
                i+=9;
                switch(input[i])
                {
                case 'l':
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::fullstate_l = atoi(value);
                    std::cout << "fullstate_l: " << value << std::endl;
                    break;
                case 'r':
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::fullstate_r = atof(value);
                    std::cout << "fullstate_r: " << value << std::endl;
                    break;
                }
                break;
            }
            break;
        case 'g':
            ++i;
            switch(input[i])
            {
            case 'a':
                i+=4;
                switch(input[i])
                {
                case 'l':
                    i+=4;
                    switch(input[i])
                    {
                    case 'c':
                        i+=12;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::game_log_compression = (input[i]=='0'?false:true);
                        std::cout << "game_log_compression: " << value << std::endl;
                        break;
                    case 'd':
                        ++i;
                        switch(input[i])
                        {
                        case 'a':
                            i+=5;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j]=input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            server_param::game_log_dated = atof(value);
                            std::cout << "game_log_dated: " << value << std::endl;
                            break;
                        case 'i':
                            // TODO : write a string reader
                            i+=3;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j]=input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            server_param::game_log_dir = QString(value);
                            std::cout << "game_log_dir: " << value << std::endl;
                            break;
                        }
                        break;
                    case 'f':
                        i+=5;
                        switch(input[i])
                        {
                        case ' ':
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j]=input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            server_param::game_log_fixed = (input[i]='0'?false:true);
                            std::cout << "game_log_fixed: " << value << std::endl;
                            break;
                        case '_':
                            i+=6;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j]=input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            server_param::game_log_fixed_name = QString(value);
                            std::cout << "game_log_fixed_name: " << value << std::endl;
                            break;
                        }
                        break;
                    case 'v':
                        i+=8;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::game_log_version = atoi(value);
                        std::cout << "game_log_version: " << value << std::endl;
                        break;
                    }
                    break;
                case 'o':
                    i+=10;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::game_over_wait = atoi(value);
                    std::cout << "game_over_wait: " << value << std::endl;
                    break;
                }
                break;
            case 'o':
                ++i;
                switch(input[i])
                {
                case 'a':
                    i+=2;
                    switch(input[i])
                    {
                    case '_':
                        i+=7;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::goal_width = atof(value);
                        std::cout << "goal_width: " << value << std::endl;
                        break;
                    case 'i':
                        i+=13;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        server_param::goalie_max_moves = atoi(value);
                        std::cout << "goalie_max_moves: " << value << std::endl;
                        break;
                    }
                    break;
                case 'l':
                    i+=10;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::golden_goal = (input[i]=='0'?false:true);
                    std::cout << "golden_goal: " << value << std::endl;
                    break;
                }
                break;
            }
            break;
        case 'h':
            ++i;
            switch(input[i])
            {
            case 'a':
                i+=9;
                j=0;
                while(input[i]!=')')
                {
                    value[j]=input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                server_param::half_time = atoi(value);
                std::cout << "half_time: " << value << std::endl;
                break;
            case 'e':
                i+=4;
                switch(input[i])
                {
                case 'd':
                    i+=6;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    //here
                    server_param::hear_decay = atoi(value);
                    std::cout << "hear_decay: " << value << std::endl;
                    break;
                case 'i':
                    i+=4;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::hear_inc = atoi(value);
                    std::cout << "hear_inc: " << value << std::endl;
                    break;
                case 'm':
                    i+=4;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    server_param::hear_max = atoi(value);
                    std::cout << "hear_max: " << value << std::endl;
                    break;
                }
                break;
            }
        case 'i':
            i+=15;
            j=0;
            while(input[i]!=')')
            {
                value[j]=input[i];
                ++i;
                ++j;
            }
            value[j]='\0';
            server_param::inertia_moment = atoi(value);
            std::cout << "inertia_moment: " << value << std::endl;
            break;
        case 'k':
            ++i;
            switch(input[i])
            {
            case 'e':
                i+=7;
                switch(input[i])
                {
                case ' ':
                    ++i;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    std::cout << "keepaway: " << value << std::endl;

                    break;
                case '_':
                    ++i;
                    switch(input[i])
                    {
                    case 'l': // keepaway_[l].*
                        ++i;
                        switch(input[i])
                        {
                        case 'e':
                            i+=6;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j]=input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            std::cout << "keepaway_length: " << value <<std::endl;
                            break;
                        case 'o':
                            i+=2;
                            switch(input[i])
                            {
                            case '_':
                                ++i;
                                switch(input[i])
                                {
                                case 'd':
                                    ++i;
                                    switch(input[i])
                                    {
                                    case 'i': // keepaway_log_d[i]r
                                        i+=2;
                                        j=0;
                                        while(input[i]!=')')
                                        {
                                            value[j]=input[i];
                                            ++i;
                                            ++j;
                                        }
                                        value[j]='\0';
                                        std::cout << "keepaway_log_dir: " << value << std::endl;
                                        break;
                                    case 'a': // keepaway_log_d[a]ted
                                        i+=5;
                                        j=0;
                                        while(input[i]!=')')
                                        {
                                            value[j]=input[i];
                                            ++i;
                                            ++j;
                                        }
                                        value[j]='\0';

                                        std::cout << "keepaway_log_dated: " << value << std::endl;
                                        break;
                                    }
                                    break;
                                case 'f': // keepaway_log_[f]ixed
                                    i+=5;
                                    switch(input[i])
                                    {
                                    case ' ':
                                        ++i;
                                        j=0;
                                        while(input[i]!=')')
                                        {
                                            value[j]=input[i];
                                            ++i;
                                            ++j;
                                        }
                                        value[j]='\0';
                                        std::cout << "keepaway_log_fixed: " << value << std::endl;
                                        break;
                                    case '_':
                                        i+=6;
                                        j=0;
                                        while(input[i]!=')')
                                        {
                                            value[j]=input[i];
                                            ++i;
                                            ++j;
                                        }
                                        value[j]='\0';
                                        std::cout << "keepaway_log_fixed_name: " << value << std::endl;
                                        break;
                                    }
                                    break;
                                }
                            case 'g':
                                i+=5;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j]=input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                std::cout << "keepaway_logging: " << value << std::endl;
                                break;
                            }
                            break;
                        }
                        break;
                    case 's':
                        i+=6;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        std::cout << "keepaway_start: " << value << std::endl;
                        break;
                    case 'w':
                        i+=6;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        std::cout << "keepaway_width: " << value << std::endl;
                        break;
                    }
                    break;
                }
                break;
            case 'i':
                i+=3;
                switch(input[i])
                {
                case '_':
                    ++i;
                    switch(input[i])
                    {
                    case 'o':
                        i+=9;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        std::cout << "kick_off_wait: " << value << std::endl;
                        break;
                    case 'p':
                        i+=11;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        std::cout << "kick_power_rate: " << value << std::endl;
                        break;
                    case 'r':
                        i+=4;
                        switch(input[i])
                        {
                        case ' ':
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j]=input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            std::cout << "kick_rand: " << value << std::endl;
                            break;
                        case '_':
                            i+=8;
                            switch(input[i])
                            {
                            case 'l':
                                i+=2;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j]=input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                std::cout << "kick_rand_factor_l: " << value << std::endl;
                                break;
                            case 'r':
                                i+=2;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j]=input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                std::cout << "kick_rand_factor_r: " << value << std::endl;
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'a':
                    i+=12;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    std::cout << "kickable_margin: " << value << std::endl;
                    break;
                }
                break;
            }
            break;
        }
        ++i;
    }
}

