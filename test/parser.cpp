#include <iostream>
#include <parser/Parser.h>
#include <perception/model.hpp>
#include <sstream>

int main() {
    std::istringstream ss;
    ss.str("(sense_body 0 (view_mode high normal) (stamina 8000 1 130600) (speed 0 0) (head_angle 0) (kick 0) (dash 0) (turn 0) (say 0) (turn_neck 0) (catch 0) (move 0) (change_view 0) (arm (movable 0) (expires 0) (target 0 0) (count 0)) (focus (target none) (count 0)) (tackle (expires 0) (count 0)) (collision none) (foul  (charged 0) (card none)))\n");
    u2d::model_t model;
    Parser p(ss,std::cerr, model);
    p.parse();
    std::cerr << "str: " << ss.str() << std::endl;
    ss.str("(sense_body 0 (view_mode high normal) (stamina 8000 1 130600) (speed 0 0) (head_angle 0) (kick 0) (dash 0) (turn 0) (say 0) (turn_neck 0) (catch 0) (move 0) (change_view 0) (arm (movable 0) (expires 0) (target 0 0) (count 0)) (focus (target none) (count 0)) (tackle (expires 0) (count 0)) (collision none) (foul  (charged 0) (card none)))\n");
    std::cerr << "str: " << ss.str() << std::endl;
    return p.parse();
}
