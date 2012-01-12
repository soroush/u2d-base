#ifndef INIT_H
#define INIT_H

class init
{
public:
    init();
    enum t_side{Left,Right};
    enum t_playMode{back_pass_l,            // 0
                    back_pass_r,            // 1
                    before_kick_off,        // 2
                    corner_kick_l,          // 3
                    corner_kick_r,          // 4
                    foul_charge_l,          // 5
                    foul_charge_r,          // 6
                    foul_l,                 // 7
                    foul_r,                 // 8
                    free_kick_l,            // 9
                    free_kick_r,            // 10
                    goal_kick_l,            // 11
                    goal_kick_r,            // 12
                    indirect_free_kick_l,   // 13
                    indirect_free_kick_r,   // 14
                    kick_in_l,              // 15
                    kick_in_r,              // 16
                    play_on                 // 17
                   };
public:
    static char* teamName;
    static int formNumber;
    static t_side side;
    static t_playMode playMode;
};

#endif // INIT_H
