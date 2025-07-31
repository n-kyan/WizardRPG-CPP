#include "Battle.h"

using namespace std;

Battle::Battle(unique_ptr<Wizard> wizard1, unique_ptr<Wizard> wizard2) :
    w1(std::move(wizard1)), // move to member variable
    w2(std::move(wizard2)), // move to member variable
    battling(true),
    roundCount(1)
{}

void Battle::run() {
    while (battling) {
        playRound();
    }
    p.print("\nThanks for playing!!\n");
}

void Battle::playRound() {

    p.print("\n===== ROUND " + to_string(roundCount) + " =====\n", "default", "default", BOLD);
    w1->modPips(1);
    w2->modPips(1);
    printState();

    // Player 1 acts first
    move_w1 = &(w1->pickMove());
    move_w1->attempt(*w1, *w2);
    updateState();
    printState();

    if (!battling) return; 

    // Player 2 acts second
    move_w2 = &(w2->pickMove());
    move_w2->attempt(*w2, *w1);
    updateState();

    roundCount++;
}

void Battle::printState() {

    w1->printState();
    w2->printState();
}

void Battle::updateState() {
    if (w1->getHealth() <= 0) {
        p.print(w1->getName() + " ran out of health points!\n");
        p.print(w2->getName() + " wins!\n", "default", "default", BOLD);
        battling = false;
    } else if (w2->getHealth() <= 0) {
        p.print(w2->getName() + " ran out of health points!\n");
        p.print(w1->getName() + " wins!\n", "default", "default", BOLD);
        battling = false;
    }
}
