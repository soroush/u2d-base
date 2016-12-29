#include <iostream>
#include <src/network/connection.hpp>

int main() {
    u2d::connection c {"127.0.0.1",6000};
    c.write("(init my_team (version 15))");
    //while(true) {
        std::string data = c.read();
        std::cerr << data << std::endl;
        //}
    return 0;
}

