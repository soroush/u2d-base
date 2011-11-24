#include "parserbase.h"
#include <iostream>
#include <QString>

void ParserBase::sp_read()
{
    i++;
    if(input[i]=='(')
    {
        sp_readParameterName();
    }
}

void ParserBase::sp_readParameterName()
{
    i++;
    switch(input[i])
    {
    case 'a':
        i++; // skip 'u' in 'au'
        sp_au();
        break;
    case 'b':
        i++; // skip 'a' in 'ba'
        sp_ba();
        break;
    case 'c':
        // cat't skip :(
        sp_c();
        break;
    case 'd':
        sp_d();
        break;
    case 'e':
        i++;
        switch(input[i])
        {
        case 'f':
            i+=6;
            sp_effort_();
            break;
        case 'x':
            i+=5;
            sp_extra_();
            break;
        }
        break;
    case 'f':
        i++;
        switch(input[i])
        {
        case 'o':
            sp_fo();
            break;
        case 'r':
            i+=3;
            sp_free();
            break;
        case 'u':
            i+=9;
            sp_fullstate_();
            break;
        }
        break;
    case 'g':
        sp_g();
        break;
    case 'h':
        i++;
        switch(input[i])
        {
        case 'a':
            sp_half_time();
            break;
        case 'e':
            sp_hear_();
            break;
        }
    case 'i':
        sp_inertia_moment();
        break;
    case 'k':
        i++;
        switch(input[i])
        {
        case 'e':
            sp_keepaway();
            break;
        case 'i':
            sp_kick();
            break;
        }
        break;
    }
}

void ParserBase::sp_au()
{
    i++;
    QString value;
    switch(input[i])
    {
    case 'd':
        i+=12;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "audio_cut_dist: " << value.toInt() << std::endl;
        break;
    case 't':
        i+=8;
        std::cout << "auto_mode: " << input[i] << std::endl;
        i++;
        break;
    }
    sp_read();
}

void ParserBase::sp_ba()
{
    i++;
    QString value("");
    switch(input[i])
    {
    case 'c':
        i+=3;
        switch(input[i])
        {
        case 'd':
            i+=9;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "back_dash_rate: " << value.toDouble() << std::endl;
            break;
        case 'p':
            i+=7;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "back_passes: " << value.toInt() << std::endl;
            break;
        }
        break;
    case 'l':
        i+=2;
        sp_ball_();
        // no neet to call sp_read() !
        break;
    }
    sp_read();
}

void ParserBase::sp_ball_()
{
    i++;
    QString value("");
    switch(input[i])
    {
    case 'a':
        i+=10;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "ball_accel_max: " << value.toDouble() << std::endl;
        break;
    case 'd':
        i+=6;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "ball_decay: " << value.toDouble() << std::endl;
        break;
    case 'r':
        i+=5;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "ball_rand: " << value.toDouble() << std::endl;
        break;
    case 's':
        i++;
        switch(input[i])
        {
        case 'i':
            i+=4;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "ball_size: " << value.toDouble() << std::endl;
            sp_read();
            break;
        case 'p':
            i+=9;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "ball_speed_max: " << value.toInt() << std::endl;
            break;
        case 't':
            i+=10;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "ball_stuck_area: " << value.toInt() << std::endl;
            break;
        }
        break;
    case 'w':
        i+=7;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "ball_weight: " << value.toDouble() << std::endl;
        break;
    }
}

void ParserBase::sp_c()
{
    i++;
    QString value("");
    switch(input[i])
    {
    case 'a':
        i+=3;
        sp_catch();
        break;
    case 'k':
        i+=12;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "ckick_margin: " << value.toDouble() << std::endl;
        sp_read();
        break;
    case 'l':
        i+=4;
        sp_clang_();
        break;
    case 'o':
        i++;
        switch(input[i])
        {
        case 'a':
            // std::cout<<"seen: sp_coa"<<std::endl;
            i+=3;
            switch(input[i])
            {
            case '_':
                // std::cout<<"seen: sp_coach_"<<std::endl;
                i++;
                switch(input[i])
                {
                case 'p':
                    i+=5;
                    while(input[i]!=')')
                    {
                        value+=input[i];
                        i++;
                    }
                    std::cout << "coach_port: " << value.toInt() << std::endl;
                    sp_read();
                    break;
                case 'w':
                    i+=10;
                    while(input[i]!=')')
                    {
                        value+=input[i];
                        i++;
                    }
                    std::cout << "coach_w_referee: " << value.toInt() << std::endl;
                    sp_read();
                    break;
                }
                break;
            case ' ':
                i++;
                // std::cout<<"seen: sp_coach "<<std::endl;
                while(input[i]!=')')
                {
                    value+=input[i];
                    i++;
                }
                std::cout << "coach: " << value.toInt()<< std::endl;
                sp_read();
                break;
            }
            break;
        case 'n':
            i++;
            switch(input[i])
            {
            case 'n':
                i+=10;
                while(input[i]!=')')
                {
                    value+=input[i];
                    i++;
                }
                std::cout << "connect_wait: " << value.toInt() << std::endl;
                sp_read();
                break;
            case 't':
                i+=12;
                while(input[i]!=')')
                {
                    value+=input[i];
                    i++;
                }
                std::cout << "control_radius: " << value.toDouble() << std::endl;
                sp_read();
                break;
            }
            break;
        }
        break;
    }
}

void ParserBase::sp_catch()
{
    i++;
    QString value("");
    switch(input[i])
    {
    case 'a':
        i+=10;
        switch(input[i])
        {
        case 'l':
            i+=2;
            value="";
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "catchable_area_l: " << value.toDouble() << std::endl;
            sp_read();
            break;
        case 'w':
            i+=2;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "catchable_area_w: " << value.toInt() << std::endl;
            sp_read();
            break;
        }
        break;
    case '_':
        i++;
        switch(input[i])
        {
        case 'b':
            i+=10;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "catch_ban_cycle: " << value.toInt() << std::endl;
            sp_read();
            break;
        case 'p':
            i+=12;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "catch_probability: " << value.toDouble() << std::endl;
            sp_read();
            break;
        }
        break;
    }
}

void ParserBase::sp_clang_()
{
    i++;
    QString value("");
    switch(input[i])
    {
    case 'a':
        i+=11;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "clang_advice_win: " << value.toDouble() << std::endl;
        sp_read();
        break;
    case 'd':
        i+=2;
        switch(input[i])
        {
        case 'f':
            i+=9;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "clang_define_win: " << value.toDouble() << std::endl;
            break;
        case 'l':
            i+=6;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "clang_del_win: " << value.toDouble() << std::endl;
            break;
        }
        sp_read();
        break;
    case 'i':
        i+=9;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "clang_info_win: " << value.toDouble() << std::endl;
        sp_read();
        break;
    case 'm':
        i+=5;
        switch(input[i])
        {
        case 'd':
            i+=6;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "clang_mess_delay: " << value.toDouble() << std::endl;
            break;
        case 'p':
            i+=10;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "clang_mess_per_cycle: " << value.toDouble() << std::endl;
            break;
        case 'w':
            i+=4;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "clang_meta_win: " << value.toDouble() << std::endl;
            break;
        }
        sp_read();
        break;
    case 'r':
        i+=9;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "clang_rule_win: " << value.toDouble() << std::endl;
        sp_read();
        break;
    case 'w':
        i+=9;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "clang_win_size: " << value.toDouble() << std::endl;
        sp_read();
        break;
    }
}

void ParserBase::sp_d()
{
    i++;
    // std::cout<<"seen: sp_da"<<std::endl;
    switch(input[i])
    {
    case 'a':
        sp_dash_();
        break;
    case 'r':
        i+=14;
        QString value("");
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "drop_ball_time: " << value.toInt() << std::endl;
        sp_read();
        break;
    }
}

void ParserBase::sp_dash_()
{
    i+=4;
    QString value("");
    switch(input[i])
    {
    case 'a':
        i+=11;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "dash_angle_step: " << value.toDouble() << std::endl;
        sp_read();
        break;
    case 'p':
        i+=11;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "dash_power_rate: " << value.toDouble() << std::endl;
        sp_read();
        break;
    }
}

void ParserBase::sp_effort_()
{
    QString value("");
    switch(input[i])
    {
    case 'd':
        i+=3;
        switch(input[i])
        {
        case ' ':
            i++;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "effort_dec: " << value.toDouble() << std::endl;
            sp_read();
            break;
        case '_':
            i+=5;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "effort_dec_thr: " << value.toDouble() << std::endl;
            sp_read();
            break;
        }
        break;
    case 'i':
        i+=3;
        switch(input[i])
        {
        case ' ':
            i++;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "effort_inc: " << value.toDouble() << std::endl;
            sp_read();
            break;
        case '_':
            i+=5;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "effort_inc_thr: " << value.toDouble() << std::endl;
            sp_read();
            break;
        case 't':
            i+=2;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "effort_init: " << value.toInt()/*?*/ << std::endl;
            sp_read();
            break;
        }
        break;
    case 'm':
        i+=4;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "effort_min: " << value.toDouble() << std::endl;
        sp_read();
        break;
    }
}

void ParserBase::sp_extra_()
{
    QString value("");
    switch(input[i])
    {
    case 'h':
        i+=10;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "extra_half_time: " << value.toInt() << std::endl;
        break;
    case 's':
        i+=8;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "extra_stamina: " << value.toDouble()/*?*/ << std::endl;
    }
    sp_read();
}

void ParserBase::sp_fo()
{
    QString value("");
//    std::cout << "fo";
    i+=1;
    switch(input[i])
    {
    case 'r':
        i+=22;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "forbid_kick_off_offside: " << value.toInt() << std::endl;
        break;
    case 'u':
        i+=3;
        switch(input[i])
        {
        case 'c':
            i+=7;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "foul_cycles: " << value.toInt() << std::endl;
            break;
        case 'd':
            i+=19;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "foul_detect_probability: " << value.toDouble() << std::endl;
            break;
        case 'e':
            i+=9;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "foul_exponent: " << value.toInt() << std::endl;
            break;
        }
        break;
    }
    sp_read();
}

void ParserBase::sp_free()
{
    QString value("");
    switch(input[i])
    {
    case '_':
        i+=13;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "free_kick_faults: " << value.toInt() << std::endl;
        break;
    case 'f':
        i+=5;
        switch(input[i])
        {
        case 's':
            i+=12;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "freeform_send_period: " << value.toInt() << std::endl;
            break;
        case 'w':
            i+=12;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "freeform_wait_period: " << value.toInt() << std::endl;
            break;
        }
        break;
    }
    sp_read();
}

void ParserBase::sp_fullstate_()
{
    QString value("");
    switch(input[i])
    {
    case 'l':
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "fullstate_l: " << value.toInt() << std::endl;
        break;
    case 'r':
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "fullstate_r: " << value.toInt() << std::endl;
        break;
    }
    sp_read();
}

void ParserBase::sp_g()
{
    i++;
    switch(input[i])
    {
    case 'a':
        i+=4;
        sp_game_();
        break;
    case 'o':
        sp_go();
        break;
    }
}

void ParserBase::sp_game_()
{
    QString value("");
    switch(input[i])
    {
    case 'l':
        i+=4;
        sp_game_log_();
        break;
    case 'o':
        i+=10;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "game_over_wait: " << value.toInt() << std::endl;
        break;
    }
    sp_read();
}

void ParserBase::sp_game_log_()
{
    QString value("");
    switch(input[i])
    {
    case 'c':
        i+=12;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "game_log_compression: " << value.toInt() << std::endl;
        break;
    case 'd':
        i++;
        switch(input[i])
        {
        case 'a':
            i+=5;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "game_log_dated: " << value.toInt() << std::endl;
            break;
        case 'i':
            // TODO : write a string reader
            i+=3;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "game_log_dir: " << value.toAscii().data() << std::endl;
            break;
        }
        break;
    case 'f':
        i+=5;
        switch(input[i])
        {
        case ' ':
            i++;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "game_log_fixed: " << value.toInt() << std::endl;
            break;
        case '_':
            i+=6;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "game_log_fixed_name: " << value.toAscii().data() << std::endl;
            break;
        }
        break;
    case 'v':
        i+=8;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "game_log_version: " << value.toInt() << std::endl;
        break;
    }
    sp_read();
}

void ParserBase::sp_go()
{
    QString value("");
    i++;
    switch(input[i])
    {
    case 'a':
        i+=2;
        switch(input[i])
        {
        case '_':
            i+=7;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "goal_width: " << value.toDouble() << std::endl;
            break;
        case 'i':
            i+=13;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "goalie_max_moves: " << value.toInt() << std::endl;

            break;
        }
        break;
    case 'l':
        i+=10;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "golden_goal: " << value.toInt() << std::endl;
        break;
    }
    sp_read();
}

void ParserBase::sp_half_time()
{
    i+=9;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "half_time: " << value.toInt() << std::endl;
    sp_read();
}

void ParserBase::sp_hear_()
{
    i+=4;
    QString value("");
    switch(input[i])
    {
    case 'd':
        i+=6;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "hear_decay: " << value.toInt() << std::endl;
        break;
    case 'i':
        i+=4;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "hear_inc: " << value.toInt() << std::endl;
        break;
    case 'm':
        i+=4;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "hear_max: " << value.toInt() << std::endl;
        break;
    }
    sp_read();
}

void ParserBase::sp_inertia_moment()
{
    QString value("");
    i+=15;
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "inertia_moment: " << value.toInt() << std::endl;
    sp_read();
}

void ParserBase::sp_keepaway()
{
    QString value("");
    i+=7;
    switch(input[i])
    {
    case ' ':
        i++;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "keepaway: " << value.toDouble() << std::endl;
        sp_read();
        break;
    case '_':
        i++;
        switch(input[i])
        {
        case 'l': // keepaway_[l].*
            i++;
            switch(input[i])
            {
            case 'e':
                i+=6;
                while(input[i]!=')')
                {
                    value+=input[i];
                    i++;
                }
                std::cout << "keepaway_length: " << value.toDouble() <<std::endl;
                sp_read();
                break;
            case 'o':
                i+=2;
                switch(input[i])
                {
                case '_':
                    i++;
                    switch(input[i])
                    {
                    case 'd':
                        i++;
                        sp_keepaway_log_d();
                      break;
                    case 'f': // keepaway_log_[f]ixed
                        i+=5;
                        switch(input[i])
                        {
                        case ' ':
                            i++;
                            while(input[i]!=')')
                            {
                                value+=input[i];
                                i++;
                            }
                            std::cout << "keepaway_log_fixed: " << value.toInt() << std::endl;
                            sp_read();
                            break;
                        case '_':
                            i+=6;
                            while(input[i]!=')')
                            {
                                value+=input[i];
                                i++;
                            }
                            std::cout << "keepaway_log_fixed_name: " << value.toAscii().data() << std::endl;
                            sp_read();
                            break;
                        }
                        break;
                    }
                case 'g':
                    i+=5;
                    while(input[i]!=')')
                    {
                        value+=input[i];
                        i++;
                    }
                    std::cout << "keepaway_logging: " << value.toAscii().data() << std::endl;
                    sp_read();
                    break;
                }
                break;
            }
            break;
        case 's':
            i+=6;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "keepaway_start: " << value.toInt() << std::endl;
            sp_read();
            break;
        case 'w':
            i+=6;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "keepaway_width: " << value.toInt() << std::endl;
            sp_read();
            break;
        }
        break;
    }
}

void ParserBase::sp_keepaway_log_d()
{
    QString value("");
    switch(input[i])
    {
    case 'i': // keepaway_log_d[i]r
        i+=2;
        value = "";
        std::cout << "I'm here!" << std::endl;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "keepaway_log_dir: " << value.toAscii().data() << std::endl;
        sp_read();
        break;
    case 'a': // keepaway_log_d[a]ted
        i+=5;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "keepaway_log_dated: " << value.toInt() << std::endl;
        sp_read();
        break;
    }
}

void ParserBase::sp_kick()
{
    QString value("");
    i+=3;
    switch(input[i])
    {
    case '_':
        i++;
        switch(input[i])
        {
        case 'o':
            i+=9;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "kick_off_wait: " << value.toDouble() << std::endl;
            break;
        case 'p':
            i+=11;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "kick_power_rate: " << value.toDouble() << std::endl;
            break;
        case 'r':
            i+=4;
            switch(input[i])
            {
            case ' ':
                i++;
                while(input[i]!=')')
                {
                    value+=input[i];
                    i++;
                }
                std::cout << "kick_rand: " << value.toDouble() << std::endl;
                break;
            case '_':
                i+=8;
                switch(input[i])
                {
                case 'l':
                    value="";
                    i+=2;
                    while(input[i]!=')')
                    {
                        value+=input[i];
                        i++;
                    }
                    std::cout << "kick_rand_factor_l: " << value.toDouble() << std::endl;
                    break;
                case 'r':
                    value="";
                    i+=2;
                    while(input[i]!=')')
                    {
                        value+=input[i];
                        i++;
                    }
                    std::cout << "kick_rand_factor_r: " << value.toDouble() << std::endl;
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 'a':
        i+=12;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "kickable_margin: " << value.toDouble() << std::endl;
        break;
    }
    sp_read();
}
