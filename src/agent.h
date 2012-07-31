#ifndef AGENT_H
#define AGENT_H

#include <sstream>

#include "model/model.h"
#include "parser/Parser.h"

class Agent
{
public:
    Agent();
    void start();
    Model model;
private:
    Parser parser;
    std::stringstream inputStream;
};

#endif // AGENT_H
