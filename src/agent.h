#ifndef AGENT_H
#define AGENT_H

#include <string>
#include <sstream>

#include "model/model.h"
#include "parser/Parser.h"
#include "network/connection.h"

class Agent
{
public:
    Agent();
    void setTeamName(const std::string& name);
    void setGoalie(const bool& goalie);
    void setVersion(const unsigned int& version);
    void setPort(const unsigned int& port);
    void setAddress(const std::string& address);
    void start();
    void parse(const char* input);
    Model model;
    // Testing proposed
    void test();
private:
    Parser parser;
    Connection connection;
    std::stringstream inputStream;
    std::string teamName;
    unsigned int rcssVersion;
    std::string address;
    unsigned int portNumber;
    bool goalie;
};

#endif // AGENT_H
