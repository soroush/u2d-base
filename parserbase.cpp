#include "parserbase.h"
#include <iostream>


ParserBase::ParserBase(QObject *parent) :
    QObject(parent)
{
}

void ParserBase::start()
{
    switch(input[i])
    {
    case '(':
        //valid
        readSensorName();
        break;
    }
}

void ParserBase::readSensorName()
{
    i++;
    switch(input[i])
    {
    case 'i':
        i+=4;
        i_startRead();
        break;
    case 's':
        i++;
        switch(input[i])
        {
        case 'e':
            i++;
            switch(input[i])
            {
            case 'e': // see
                ss_startRead();
                break;
            case 'n': // sense_body
                i+=9;
                sb_startRead();
                break;
            case 'r':
                i+=10;
                sp_startRead();
                break;
            }
            break;
        case 'c': // score
            break;
        }
        break;
    case 'p': // player_
        i+=7;
        switch(input[i])
        {
        case 't':
            i+=6;
            pt_startRead();
            break;
        case 'p':
            i+=6;
            pp_startRead();
            break;
        }
        break;
    case 'h': // hear
        break;
    case 'e': // error
        break;
    case 'o': // ok_say
        break;
    }
}
