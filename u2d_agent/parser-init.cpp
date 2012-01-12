#include "parserbase.h"
#include "init.h"
#include <iostream>
#include <stdlib.h>

void ParserBase::i_startRead()
{
    // temporary data holders:
    char value[10];
    int j=0;
    // Reading side of field:
    ++i;
    switch(input[i])
    {
    case'l':
        init::side = init::Left;
        break;
    case'r':
        init::side = init::Right;
        break;
    }
    i+=2;
    while(input[i]!=' ')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    j=0;
    init::formNumber = atoi(value);
    ++i;
    switch(input[i])
    {
    case 'b':
        ++i;
        switch(input[i])
        {
        case 'a':
            i+=9;
            switch(input[i])
            {
            case 'l':
                init::playMode = init::back_pass_l;
                break;
            case 'r':
                init::playMode = init::back_pass_r;
                break;
            }
            break;
        case 'e':
            i+=13;
            init::playMode = init::before_kick_off;
            break;
        }
        break;
    case 'c':
        i+=12;
        switch(input[i])
        {
        case 'l':
            init::playMode = init::corner_kick_l;
            break;
        case 'r':
            init::playMode = init::corner_kick_r;
            break;
        }
        break;
    case 'f':
        ++i;
        switch(input[i])
        {
        case 'o':
            i+=4;
            switch(input[i])
            {
            case 'c':
                i+=7;
                switch(input[i])
                {
                case 'l':
                    init::playMode = init::foul_charge_l;
                    break;
                case 'r':
                    init::playMode = init::foul_charge_r;
                    break;
                }
                break;
            case 'l':
                init::playMode = init::foul_l;
                break;
            case 'r':
                init::playMode = init::foul_r;
                break;
            }
            break;
        case 'r':
            i+=9;
            switch(input[i])
            {
            case 'l':
                init::playMode = init::free_kick_l;
                break;
            case 'r':
                init::playMode = init::free_kick_r;
                break;
            }
            break;
        }
        break;
    case 'g':
        i+=10;
        switch(input[i])
        {
        case 'l':
            init::playMode = init::goal_kick_l;
            break;
        case 'r':
            init::playMode = init::goal_kick_r;
            break;
        }
        break;
    case 'i':
        i+=19;
        switch(input[i])
        {
        case 'l':
            init::playMode = init::indirect_free_kick_l;
            break;
        case 'r':
            init::playMode = init::indirect_free_kick_r;
            break;
        }
        break;
    case 'k':
        i+=8;
        switch(input[i])
        {
        case 'l':
            init::playMode = init::kick_in_l;
            break;
        case 'r':
            init::playMode = init::kick_in_r;
            break;
        }
        break;
    case 'p':
        i+=6;
        init::playMode = init::play_on;
        break;
    }
    i+=2;
}
