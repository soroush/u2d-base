#include "agent.h"
#include <sstream>
using namespace std;

Agent::Agent()
{
    this->parser.setParent(this);
}

void Agent::setTeamName(const string &name)
{
    this->teamName = name;
}

void Agent::setGoalie(const bool &_goalie)
{
    this->goalie = _goalie;
}

void Agent::setVersion(const unsigned int &version)
{
    this->rcssVersion = version;
}

void Agent::setPort(const unsigned int &port)
{
    this->portNumber = port;
}

void Agent::setAddress(const string &_address)
{
    this->address = _address;
}

void Agent::start()
{
    this->parser.setIstream(this->inputStream);
    connection.initialize(this->address, this->portNumber,this);
    char buffer[50];
    sprintf(buffer, "(init %s (version %d) %s)",
            this->teamName.c_str(), this->rcssVersion,
            (this->goalie ? "(goalie)" : ""));
    connection.setInitializationCommand(buffer);
    connection.loop();
}

void Agent::parse(const char *input)
{
    inputStream.str(std::string());
    inputStream << input;
//    cout << "parsing result: " << endl;
    this->parser.reset();
    int r = this->parser.parse() ;
//    cout << r << endl;
//    if(r)
//        exit(r);
}

// Testing proposed
void Agent::test()
{
    parser.setIstream(std::cin);
    while(true)
    parser.parse();
//    string value;
//    this->parser.setIstream(inputStream);
//    while(true)
//    {
//        getline(cin,value);
//        inputStream.str("");
//        inputStream << value;
//        this->parser.reset();
//        this->parser.parse();
//    }
}
