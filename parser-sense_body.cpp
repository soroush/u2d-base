#include "parserbase.h"
#include <iostream>
#include <QString>

void ParserBase::sb_startRead()
{
    // reading time number:
    QString value("");
    while(input[i]!=' ')
    {
        value+=input[i];
        i++;
    }
    std::cout << "time: " << value.toAscii().data()<< std::endl;
    // Parameters of this sensor are ordered.
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
//    sb_tackle();
//    sb_collision();
//    sb_foul();
}

void ParserBase::sb_readParameter()
{
    /*
    i++; // skip first '('
    switch(input[i])
    {
    case 'a': // [a]rm
        break;
    case 'c':
        i++;
        switch(input[i])
        {
        case 'a': // [c]atch
            break;
        case 'h': // c[h]ange_view
            break;
        case 'o': // c[o]llision
            break;
        }
        break;
    case 'd': // [d]ash
        break;
    case 'f':
        i+=2;
        switch(input[i])
        {
        case 'c': // fo[c]us
            break;
        case 'u': // fo[u]l
            break;
        }
        break;
    case 'h': // [h]ead_angle
        break;
    case 'k': // [k]ick
        break;
    case 'm': // [m]ove
        break;
    case 's':
        i++;
        switch(input[i])
        {
        case 'a': // s[a]y
            break;
        case 'p': // s[p]eed
            break;
        case 't': // s[t]amina
            break;
        }
        break;
    case 't':
        i+=4;
        switch(input[i])
        {
        case ' ': // turn[ ]
            break;
        case '_': // turn[_]neck
            break;
        }
        break;
    case 'v': // [v]iew_mode
        break;
    }
*/
}

void ParserBase::sb_view_mode()
{
    i+=12; // pas first '(', go to '[h]igh normal'...
    switch(input[i])
    {
    case 'h':
        i+=5;
        std::cout << "view_mode: high ";
        break;
    case 'l':
        i+=4;
        std::cout << "view_mode: low ";
        break;
    }
    switch(input[i])
    {
    case 'n':
        i++;
        switch(input[i])
        {
        case 'a':
            i+=6;
            std::cout << "narrow " << std::endl;
            break;
        case 'o':
            i+=6;
            std::cout << "normal " << std::endl;
            break;
        }
        break;
    case 'w':
        i+=5;
        std::cout << "wide " << std::endl;
        break;
    }
    i++; // Go to the start of next parameter
    // this could be a bad idea, i know :-/
}

void ParserBase::sb_stamina()
{
    i+=9;
    QString value("");
    while(input[i]!=' ')
    {
        value+=input[i];
        i++;
    }
    std::cout << "stamina: " << value.toDouble();
    i++;
    value="";
    while(input[i]!=' ')
    {
        value+=input[i];
        i++;
    }
    std::cout << " " << value.toDouble();
    i++;
    value="";
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << " " << value.toDouble() << std::endl;
    i++;
}

void ParserBase::sb_speed()
{
    i+=8;
    QString value("");
    while(input[i]!=' ')
    {
        value+=input[i];
        i++;
    }
    std::cout << "speed: " << value.toDouble();
    i++;
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << ' ' << value.toInt() << std::endl;
    i++;
}

void ParserBase::sb_head_angle()
{
    i+=13;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "head_angle: " << value.toInt() << std::endl;
}

void ParserBase::sb_kick()
{
    i+=7;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "kick: " << value.toInt() << std::endl;
    i++;
}

void ParserBase::sb_dash()
{
    i+=7;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "dash: " << value.toInt() << std::endl;
    i++;
}

void ParserBase::sb_turn()
{
    i+=7;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "turn: " << value.toInt() << std::endl;
    i++;
}

void ParserBase::sb_say()
{
    i+=6;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "say: " << value.toInt() << std::endl;
    i++;
}

void ParserBase::sb_turn_neck()
{
    i+=12;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "turn_neck: " << value.toInt() << std::endl;
    i++;
}

void ParserBase::sb_catch()
{
    i+=8;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "catch: " << value.toInt() << std::endl;
    i++;
}

void ParserBase::sb_move()
{
    i+=7;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "move: " << value.toInt() << std::endl;
    i++;
}

void ParserBase::sb_change_view()
{
    i+=7;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "change_view: " << value.toInt() << std::endl;
    i++;
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
    i++;
}

void ParserBase::sb_arm_movable()
{
    i+=10;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "arm::movable: " << value.toInt() << std::endl;
    i++;
}

void ParserBase::sb_arm_expires()
{
    i+=10;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "arm::expires: " << value.toInt() << std::endl;
    i++;
}

void ParserBase::sb_arm_target()
{
    i+=9;
    QString value("");
    while(input[i]!=' ')
    {
        value+=input[i];
        i++;
    }
    std::cout << "arm::target: " << value.toDouble();
    i++;
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << ' ' << value.toDouble() << std::endl;
    i++;
}

void ParserBase::sb_arm_count()
{
    i+=8;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "arm::count: " << value.toInt() << std::endl;
    i++;
}

void ParserBase::sb_focus()
{
    i+=7;
    sb_focus_target();
    sb_focus_count();
    i++;
}

void ParserBase::sb_focus_target()
{
    i+=9;
    QString value("");
    switch(input[i])
    {
    case 'n':
        i+=4;
        std::cout << "focus::target: none" << std::endl;
        break;
    case 'l':
        i+=2;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "focus::target: l - ";
        std::cout << value.toInt() << std::endl;
        break;
    case 'r':
        i+=2;
        while(input[i]!=')')
        {
            value+=input[i];
            i++;
        }
        std::cout << "focus::target: r - ";
        std::cout << value.toInt() << std::endl;
        break;
    }
    i++;
}

void ParserBase::sb_focus_count()
{
    i+=8;
    QString value("");
    while(input[i]!=')')
    {
        value+=input[i];
        i++;
    }
    std::cout << "focus::count: " << value.toInt() << std::endl;
    i++;
}
