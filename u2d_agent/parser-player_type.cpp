#include <iostream>
#include <stdlib.h>
#include <QString>
#include "parserbase.h"
#include "player_type.h"

void ParserBase::pt_startRead()
{
    double catchable_area_l_stretch = 0;
    double dash_power_rate = 0;
    double effort_max = 0;
    double effort_min = 0;
    double extra_stamina = 0;
    double foul_detect_probability = 0;
    double id = 0;
    double inertia_moment = 0;
    double kick_power_rate = 0;
    double kick_rand = 0;
    double kickable_margin = 0;
    double player_decay = 0;
    double player_size = 0;
    double player_speed_max = 0;
    double stamina_inc_max= 0;
    char value[10];
    int j;
    while(input[i]!=')')
    {
        ++i;
        switch(input[i])
        {
        case 'c':
            i+=25;
            j=0;
            while(input[i]!=')')
            {
                value[j] = input[i];
                ++i;
            }
            value[j]='\0';
            catchable_area_l_stretch = atof(value);
            break;
        case 'd':
            i+=16;
            j=0;
            while(input[i]!=')')
            {
                value[j] = input[i];
                ++i;
            }
            value[j]='\0';
            dash_power_rate = atof(value);
            break;
        case 'e':
            ++i;
            switch(input[i])
            {
            case 'f':
                i+=7;
                switch(input[i])
                {
                case 'a':
                    i+=4;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                    }
                    value[j]='\0';
                    effort_max = atof(value);
                    break;
                case 'i':
                    i+=4;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                    }
                    value[j]='\0';
                    effort_min = atof(value);
                    break;
                }
                break;
            case 'x':
                i+=13;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                }
                value[j]='\0';
                extra_stamina = atof(value);
                break;
            }
            break;
        case 'f':
            i+=24;
            j=0;
            while(input[i]!=')')
            {
                value[j] = input[i];
                ++i;
            }
            value[j]='\0';
            foul_detect_probability = atof(value);
            break;
        case 'i':
            ++i;
            switch(input[i])
            {
            case 'd':
                i+=2;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                }
                value[j]='\0';
                id = atof(value);
                break;
            case 'n':
                i+=14;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                }
                value[j]='\0';
                inertia_moment = atof(value);
                break;
            }
            break;
        case 'k':
            i+=5;
            switch(input[i])
            {
            case 'p':
                i+=11;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                }
                value[j]='\0';
                kick_power_rate = atof(value);
                break;
            case 'r':
                i+=5;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                }
                value[j]='\0';
                kick_rand = atof(value);
                break;
            case 'b':
                i+=11;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                }
                value[j]='\0';
                kickable_margin = atof(value);
                break;
            }
            break;
        case 'p':
            i+=8;
            switch(input[i])
            {
            case 'e':
                i+=5;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                }
                value[j]='\0';
                player_decay = atof(value);
                break;
            case 'i':
                i+=4;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                }
                value[j]='\0';
                player_size = atof(value);
                break;
            case 'p':
                i+=9;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                }
                value[j]='\0';
                player_speed_max = atof(value);
                break;
            }
            break;
        case 's':
            i+=16;
            j=0;
            while(input[i]!=')')
            {
                value[j] = input[i];
                ++i;
            }
            value[j]='\0';
            stamina_inc_max = atof(value);
            break;
        }
        ++i;
    }
    player_type* type = new player_type(catchable_area_l_stretch,
                                        dash_power_rate,
                                        effort_max,
                                        effort_min,
                                        extra_stamina,
                                        foul_detect_probability,
                                        id,
                                        inertia_moment,
                                        kick_power_rate,
                                        kick_rand,
                                        kickable_margin,
                                        player_decay,
                                        player_size,
                                        player_speed_max,
                                        stamina_inc_max);
    player_type::players.append(type);
}
