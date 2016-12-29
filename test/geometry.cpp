#include <iostream>
#include <src/geometry/geometry.hpp>

int main() {
    u2d::vector2df v1{1.1,2.2};
    u2d::vector2df v2{3.3,2.6};
    u2d::vector2df v3 = v1 + v2;
    std::cerr << v1.x << "," << v1.y << std::endl;
    std::cerr << v2.x << "," << v2.y << std::endl;
    std::cerr << v3.x << "," << v3.y << std::endl;
    std::cerr << v3.length() << std::endl;
    return 0;
}

