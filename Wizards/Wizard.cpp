#include <iostream>
#include "Wizard.h"
#include "../utils.h"

using namespace std;

unique_ptr<Wizard> createWizard(bool isPlayer) {

    uint8_t choice = inputValid_uint<uint8_t>(
        "Choose a school:\n"
        "\n"
            "\t1. Life\n"
            "\t2. Death\n"
            "\t3. Balance",
            1, 3
    );
    
    switch (choice) {
        case 1:
            return make_unique<Wizard_Life>(isPlayer);
        
        case 2:
            return make_unique<Wizard_Death>(isPlayer);

        case 3:
            return make_unique<Wizard_Balance>(isPlayer);
        
        default:
            p.print("Wizard choice type error.");
            return nullptr;
    }
}

Wizard::Wizard(bool isPlayer_, uint16_t maxHealth) :
    isPlayer(isPlayer_),
    MAX_HEALTH(maxHealth),
    health(MAX_HEALTH),
    numPips(0),
    accuracy(0)
{
    level = make_unique<Level>();
    level->curExperience = 0;
    level->reqExperience = 100;
    level->levelValue = 1;

    moves[0] = make_unique<Pass>();
}

Move& Wizard::pickMove() {
    // uint8_t selection;
    // cout << name << ", select your move:" << endl;
    // for (uint8_t i = 0; i < 3; i++) {
    //     p.print(to_string(i+1) + ". " + moves[i]->getName() + " (Cost: " + to_string(moves[i]->getPipCost()) + " pips)");
    // }
    // cin >> selection;
    // while (selection < 1 || selection > MAX_MOVES) {
    //     p.print("Select a valid move (1-3)");\
    //     cin >> selection;
    // }

    string prompt = name + ", select your move:\n";
    for (uint8_t i = 0; i < NUM_MOVES; i++) {
        prompt += 
            p.format(to_string(i+1) + ". " + moves[i]->getName() + " (Cost: " + to_string(moves[i]->getPipCost()) + " pips)\n");
    }
    uint8_t selection = inputValid_uint<uint8_t>(prompt,1 , NUM_MOVES);

    selection--;
    p.print(moves[selection]->getName() + " selected\n", "default", "default", BOLD);
    return *moves[selection];
}

void Wizard::printState() {
    printName();
    p.print(" - ");
    printSchool();
    p.print(
        "Health: " + to_string(health) + '/' + to_string(MAX_HEALTH) + '\n', "red"
    );
    p.print(
        "Pips: " + string(numPips, '*') + '\n', "yellow"
    );
    p.print(
        "Accuracy Multiplier: " + to_string(getAccuracyMultiplier()) + '\n', "default", "default", BOLD
    );
    cout << endl;
}

void Wizard::usePassive() {
    passiveAbility->use(*this, *this);
}

// Getters
uint16_t Wizard::getHealth() const {
    return health;
}

uint16_t Wizard::getMaxHealth() const {
    return MAX_HEALTH;
}

uint8_t Wizard::getNumPips() const {
    return numPips;
}

uint8_t Wizard::getAccuracyMultiplier() const {
    return (1.0 + accuracy / 100.0);
}

const string& Wizard::getName() const {
    return name;
}

// Modifiers
void Wizard::modHealth(int16_t amount) {
    health += amount;

    if (health < 0) { health = 0;}
    if (health > MAX_HEALTH) { health = MAX_HEALTH;}
}

void Wizard::modAccuracy(int8_t amount) {
    accuracy += amount;

    if (accuracy < 0) { accuracy = 0;}
    if (accuracy > MAX_ACCURACY) { accuracy = MAX_ACCURACY;}
}

void Wizard::modPips(int8_t amount) {
    numPips += amount;

    if (numPips < 0) { numPips = 0;}
    if (numPips > MAX_PIPS) { numPips = MAX_PIPS;}
}
