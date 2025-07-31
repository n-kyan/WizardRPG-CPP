#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include "Wizards/Wizard.h"
#include "Moves/Move.h"

using namespace std;

class Battle {
    private:
        unique_ptr<Wizard> w1;
        unique_ptr<Wizard> w2;
        bool battling;
        Move* move_w1;
        Move* move_w2;
        int roundCount;


    public:
        Battle(unique_ptr<Wizard> w1, unique_ptr<Wizard> w2);

        void run();
        void printState();
        void updateState();
        void playRound();
};

#endif