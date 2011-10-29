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
        sp_read();
        break;
    case 't':
        i+=8;
        std::cout << "auto_mode: " << input[i] << std::endl;
        i++;
        sp_read();
        break;
    }
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
            sp_read();
            break;
        case 'p':
            i+=7;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "back_passes: " << value.toInt() << std::endl;
            sp_read();
            break;
        }
        break;
    case 'l':
        i+=2;
        sp_ball_();
        // no neet to call sp_read() !
        break;
    }
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
        sp_read();
        break;
    case 'd':
        i+=6;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "ball_decay: " << value.toDouble() << std::endl;
        sp_read();
        break;
    case 'r':
        i+=5;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "ball_rand: " << value.toDouble() << std::endl;
        sp_read();
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
            sp_read();
            break;
        case 't':
            i+=10;
            while(input[i]!=')')
            {
                value+=input[i];
                i++;
            }
            std::cout << "ball_stuck_area: " << value.toInt() << std::endl;
            sp_read();
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
        sp_read();
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
