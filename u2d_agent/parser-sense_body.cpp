#include <iostream>
#include <QString>
#include "parserbase.h"
#include "agent.h"
#include "sense_body.h"

void ParserBase::sb_startRead()
{
    // Data:
    double x=0, y=0, z=0;
    int c=0;
    // reading time:
    char value[10];
    int j = 0;
    while(input[i]!=' ')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    int time = atoi(value);
    agent->body.time = time;
    i+=12; // pas first '(', go to '[h]igh normal'...
    switch(input[i])
    {
    case 'h':
        i+=5;
        agent->body.view_mode.type = high;
        break;
    case 'l':
        i+=4;
        agent->body.view_mode.type = low;
        break;
    }
    switch(input[i])
    {
    case 'n':
        ++i;
        switch(input[i])
        {
        case 'a':
            i+=6;
            agent->body.view_mode.width = narrow;
            break;
        case 'o':
            i+=6;
            agent->body.view_mode.width = normal_w;
            break;
        }
        break;
    case 'w':
        i+=5;
        agent->body.view_mode.width = wide;
        break;
    }
    // Go to the start of next parameter
    // this could be a bad idea, i know :-/
    i+=10;
    j=0;
    while(input[i]!=' ')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j] = '\0';
    z=atof(value);
    agent->body.stamina.stamina = z;
    ++i;
    j=0;
    while(input[i]!=' ')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    z=atof(value);
    agent->body.stamina.effort = z;
    ++i;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    z=atof(value);
    agent->body.stamina.capacity = z;
    i+=9;
    j=0;
    while(input[i]!=' ')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]=0;
    x = atof(value);
    ++i;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    y = atof(value);
    agent->body.speed = QPointF(x,y);
    i+=14;
    j=0;
    while(input[i]!=')')
    {
        value [j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.head_angle = atof(value);
    i+=8;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.kick = atoi(value);
    i+=8;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.dash = atoi(value);
    i+=8;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';

    agent->body.turn = atoi(value);
    i+=7;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.say = atoi(value);
    i+=13;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.turn_neck = atoi(value);
    i+=9;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.catch_ = atoi(value);
    i+=8;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.move = atoi(value);
    i+=8;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.change_view = atoi(value);
    i+=16;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.arm.movable = atoi(value);
    i+=11;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.arm.expires = atoi(value);
    i+=10;
    j=0;
    while(input[i]!=' ')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    x = atof(value);
    ++i;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    y = atof(value);
    agent->body.arm.target = QPointF(x,y);
    i+=9;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.arm.count = atoi(value);
    i+=18;
    j=0;
    switch(input[i])
    {
    case 'n':
        i+=4;
        agent->body.focus.type = t_focus::none;
        break;
    case 'l':
        i+=2;
        j=0;
        while(input[i]!=')')
        {
            value[j] = input[i];
            ++i;
            ++j;
        }
        value[j]='\0';
        agent->body.focus.type = t_focus::l;
        c = atoi(value);
        agent->body.focus.unum = c;
        break;
    case 'r':
        j=0;
        i+=2;
        while(input[i]!=')')
        {
            value[j] = input[i];
            ++i;
            ++j;
        }
        value[j]='\0';
        agent->body.focus.type = t_focus::l;
        c = atoi(value);
        agent->body.focus.unum = c;
        break;
    }
    i+=9;
    j=0;
    while(input[i]!=')')
    {
        value[j]=input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    c = atoi(value);
    agent->body.focus.count = c;
    i+=20;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    c = atoi(value);
    agent->body.tackle.expires = c;
    i+=9;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.tackle.count = atoi(value);
    i+=13;
    while(input[i]!=')')
    {
        ++i;
        switch(input[i])
        {
        case 'n':
            agent->body.collition.type |= t_collition::none;
            i+=5;
            break;
        case '(':
            ++i;
            switch(input[i])
            {
            case 'b':
                i+=5;
                agent->body.collition.type |= t_collition::ball;
            case 'p':
                ++i;
                switch(input[i])
                {
                case 'l':
                    i+=6;
                    agent->body.collition.type |= t_collition::player;
                case 'o':
                    i+=5;
                    agent->body.collition.type |= t_collition::post;
                }
                break;
            }
            break;
        }
    }
    i+=17;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->body.foul.charged = atoi(value);
    i+=8;
    switch(input[i])
    {
    case 'n':
        i+=4;
        agent->body.foul.card = t_foul::none;
        break;
    case 'y':
        i+=6;
        agent->body.foul.card = t_foul::yellow;
        break;
        // TODO: Not red card?
        // Do I need to know red cards?
    }
    i+=2;
}
