#ifndef CONNECTION_H
#define CONNECTION_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

class Agent;

class Connection
{
public:
    Connection();
    Connection(const char* ip, const unsigned int& portNumber, Agent *parant=0);
    Connection(const std::string& ip, const unsigned int& portNumber, Agent* parent=0);
    void initialize(const std::string& ip, const unsigned int& portNumber, Agent* parent=0);
    void loop();
    void setInitializationCommand(const std::string& command);
private:
    int sockfd;
    struct sockaddr_in address;
    std::string initializeCommand;
    Agent* parant;
};

#endif // CONNECTION_H
