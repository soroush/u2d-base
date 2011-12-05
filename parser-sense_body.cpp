#include <iostream>
#include <QString>
#include "parserbase.h"
#include "agent.h"

void ParserBase::sb_startRead()
{
    // reading time:
    char value[5];
    int j = 0;
    while(input[i]!=' ')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.time = atoi(value);
    //std::cout << "agent->sensors.body.time: " << agent->sensors.body.time << std::endl;
    // reading parameters by order
    sb_view_mode();
    sb_stamina();
    sb_speed();
    sb_head_angle();
    sb_kick();
    sb_dash();
    sb_turn();
    sb_say();
    sb_turn_neck();
    sb_catch();
    sb_move();
    sb_change_view();
    sb_arm();
    sb_focus();
    sb_tackle();
    sb_collision();
    sb_foul();
}

void ParserBase::sb_view_mode()
{
    i+=12; // pas first '(', go to '[h]igh normal'...
    switch(input[i])
    {
    case 'h':
        i+=5;
        agent->sensors.body.view_mode.type = high;
        //std::cout << "view_mode: high ";
        break;
    case 'l':
        i+=4;
        agent->sensors.body.view_mode.type = low;
        //std::cout << "view_mode: low ";
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
            agent->sensors.body.view_mode.width = narrow;
            //std::cout << "narrow " << std::endl;
            break;
        case 'o':
            i+=6;
            agent->sensors.body.view_mode.width = normal_w;
            //std::cout << "normal " << std::endl;
            break;
        }
        break;
    case 'w':
        i+=5;
        agent->sensors.body.view_mode.width = wide;
        //std::cout << "wide " << std::endl;
        break;
    }
    ++i;
    // Go to the start of next parameter
    // this could be a bad idea, i know :-/
}

void ParserBase::sb_stamina()
{
    i+=9;
    char value[10];
    int k=0;
    while(input[i]!=' ')
    {
        value[k] = input[i];
        ++i;
        ++k;
    }
    value[i] = '\0';
    //agent->sensors.body.stamina = t_stamina();
    double z=atof(value);
    agent->sensors.body.stamina.stamina = z;
    //std::cout << "agent->sensors.body.stamina.stamina: " << agent->sensors.body.stamina.stamina << std::endl;
    ++i;
    k=0;
    while(input[i]!=' ')
    {
        value[k] = input[i];
        ++i;
        ++k;
    }
    value[k]='\0';
    z=atof(value);
    agent->sensors.body.stamina.effort = z;
    //std::cout << "agent->sensors.body.stamina.effort: " << agent->sensors.body.stamina.effort << std::endl;
    ++i;
    k=0;
    while(input[i]!=')')
    {
        value[k] = input[i];
        ++i;
        ++k;
    }
    value[k]='\0';
    z=atof(value);
    agent->sensors.body.stamina.capacity = z;
    //std::cout << "agent->sensors.body.stamina.capacity: " << agent->sensors.body.stamina.capacity << std::endl;
    ++i;
}

void ParserBase::sb_speed()
{
    i+=8;
    char value[10];
    int j=0;
    while(input[i]!=' ')
    {
        value[j] = input[i];
        ++i; ++j;
    }
    value[j]=0;
    double distance = atof(value);
    //std::cout << "speed: " << value.toDouble();
    ++i;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
    }
    value[j]=0;
    double direction = atof(value);
    agent->sensors.body.speed = QPointF(distance,direction);
    //std::cout << "agent->sensors.body.speed: " << agent->sensors.body.speed.x() << agent->sensors.body.speed.y() << std::endl;
    ++i;
}

void ParserBase::sb_head_angle()
{
    i+=13;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value [j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.head_angle = atof(value);
    //std::cout << "agent->sensors.body.head_angle: " << agent->sensors.body.head_angle << std::endl;
    ++i;
}

void ParserBase::sb_kick()
{
    i+=7;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.kick = atoi(value);
    //std::cout << "agent->sensors.body.kick: " << agent->sensors.body.kick << std::endl;
    ++i;
}

void ParserBase::sb_dash()
{
    i+=7;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.dash = atoi(value);
    //std::cout << "agent->sensors.body.dash: " << agent->sensors.body.dash << std::endl;
    ++i;
}

void ParserBase::sb_turn()
{
    i+=7;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.turn = atoi(value);
    //std::cout << "agent->sensors.body.turn: " << agent->sensors.body.turn << std::endl;
    ++i;
}

void ParserBase::sb_say()
{
    i+=6;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.say = atoi(value);
    //std::cout << "agent->sensors.body.say: " << agent->sensors.body.say << std::endl;
    ++i;
}

void ParserBase::sb_turn_neck()
{
    i+=12;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.turn_neck = atoi(value);
    //std::cout << "agent->sensors.body.turn_neck: " << agent->sensors.body.turn_neck << std::endl;
    ++i;
}

void ParserBase::sb_catch()
{
    i+=8;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.catch_ = atoi(value);
    //std::cout << "agent->sensors.body.catch_: " << agent->sensors.body.catch_ << std::endl;
    ++i;
}

void ParserBase::sb_move()
{
    i+=7;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.move = atoi(value);
    //std::cout << "agent->sensors.body.move: " << agent->sensors.body.move << std::endl;
    ++i;
}

void ParserBase::sb_change_view()
{
    i+=7;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.change_view = atoi(value);
    //std::cout << "agent->sensors.body.change_view: " << agent->sensors.body.change_view << std::endl;
    ++i;
}

void ParserBase::sb_arm()
{
    // Go to the first ' ' before '('
    i+=5;
    // TODO: These functions could be merged due to
    // gain more performance and reduce instruction count
    sb_arm_movable();
    sb_arm_expires();
    sb_arm_target();
    sb_arm_count();
    ++i;
}

void ParserBase::sb_arm_movable()
{
    i+=10;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.arm.movable = atoi(value);
    //std::cout << "agent->sensors.body.movable: " << agent->sensors.body.arm.movable << std::endl;
    ++i;
}

void ParserBase::sb_arm_expires()
{
    i+=10;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.arm.expires = atoi(value);
    //std::cout << "agent->sensors.body.expires: " << agent->sensors.body.arm.expires << std::endl;
    ++i;
}

void ParserBase::sb_arm_target()
{
    i+=9;
    char value[10];
    int j=0;
    while(input[i]!=' ')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    double distance = atof(value);
    ++i;
    j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    double direction = atof(value);
    agent->sensors.body.arm.target = QPointF(distance,direction);
    //std::cout << "agent->sensors.body.arm.target: " << agent->sensors.body.arm.target.x() << '-' << agent->sensors.body.arm.target.y() << std::endl;
    ++i;
}

void ParserBase::sb_arm_count()
{
    i+=8;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.arm.count = atoi(value);
    //std::cout << "agent->sensors.body.expires: " << agent->sensors.body.arm.count << std::endl;
    ++i;
}

void ParserBase::sb_focus()
{
    i+=7;
    sb_focus_target();
    sb_focus_count();
    ++i;
}

void ParserBase::sb_focus_target()
{
    i+=9;
    char value[3];
    int j=0;
    switch(input[i])
    {
    case 'n':
        i+=4;
        agent->sensors.body.focus.type = t_focus::none;
        //std::cout << "agent->sensors.body.focus.type: none" << std::endl;
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
        agent->sensors.body.focus.type = t_focus::l;
        agent->sensors.body.focus.unum = atoi(value);
        //std::cout << "focus::target: l - " << agent->sensors.body.focus.unum << std::endl;
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
        agent->sensors.body.focus.type = t_focus::l;
        agent->sensors.body.focus.unum = atoi(value);
        //std::cout << "focus::target: r - " << agent->sensors.body.focus.unum << std::endl;
        break;
    }
    ++i;
}

void ParserBase::sb_focus_count()
{
    i+=8;
    char value[8];
    int j=0;
    while(input[i]!=')')
    {
        value[j]=input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.focus.count = atoi(value);
    //std::cout << "agent->sensors.body.focus.count: " << agent->sensors.body.focus.count << std::endl;
    ++i;
}

void ParserBase::sb_tackle()
{
    i+=8;
    sb_tackle_expires();
    sb_tackle_count();
    ++i;
}

void ParserBase::sb_tackle_expires()
{
    i+=10;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.tackle.expires = atoi(value);
    //std::cout << "agent->sensors.body.tackle.expires: " << agent->sensors.body.tackle.expires << std::endl;
    ++i;
}

void ParserBase::sb_tackle_count()
{
    i+=8;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.tackle.count = atoi(value);
    //std::cout << "agent->sensors.body.tackle.count: " << agent->sensors.body.tackle.count << std::endl;
    ++i;
}

void ParserBase::sb_collision()
{
    i+=11;
    while(input[i]!=')')
    {
        ++i;
        switch(input[i])
        {
        case 'n': // none
            agent->sensors.body.collition.type |= t_collition::none;
            //std::cout << "agent->sensors.body.collition.type: " << agent->sensors.body.collition.type << std::endl;
            i+=5;
            break;
        case '(':
            ++i;
            switch(input[i])
            {
            case 'b':
                i+=5;
                agent->sensors.body.collition.type |= t_collition::ball;
                //std::cout << "agent->sensors.body.collition.type: " << agent->sensors.body.collition.type << std::endl;                break;
            case 'p':
                ++i;
                switch(input[i])
                {
                case 'l':
                    i+=6;
                    agent->sensors.body.collition.type |= t_collition::player;
                    //std::cout << "agent->sensors.body.collition.type: " << agent->sensors.body.collition.type << std::endl;                    break;
                case 'o':
                    i+=5;
                    agent->sensors.body.collition.type |= t_collition::post;
                    //std::cout << "agent->sensors.body.collition.type: " << agent->sensors.body.collition.type << std::endl;                    break;
                }
                break;
            }
            break;
        }
    }
    ++i;
}

void ParserBase::sb_foul()
{
    i+=6;
    sb_foul_charged();
    sb_foul_card();
    ++i;
}

void ParserBase::sb_foul_charged()
{
    i+=10;
    char value[10];
    int j=0;
    while(input[i]!=')')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    agent->sensors.body.foul.charged = atoi(value);
    //std::cout << "agent->sensors.body.foul.charged: " << agent->sensors.body.foul.charged << std::endl;
    ++i;
}

void ParserBase::sb_foul_card()
{
    i+=7;
    switch(input[i])
    {
    case 'n':
        i+=4;
        agent->sensors.body.foul.card = t_foul::none;
        //std::cout << "agent->sensors.body.foul.card: " << agent->sensors.body.foul.card << std::endl;
        break;
    case 'y':
        i+=6;
        agent->sensors.body.foul.card = t_foul::yellow;
        //std::cout << "agent->sensors.body.foul.card: " << agent->sensors.body.foul.card << std::endl;
        break;
    }
    ++i;
}
