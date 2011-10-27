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
