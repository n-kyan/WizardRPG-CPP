#include "Wizard.h"

Wizard_Life::Wizard_Life(bool isPlayer) : 
    Wizard(isPlayer, 120)
{
    health = MAX_HEALTH;
    passiveAbility = make_unique<Passive_Life>();
    moves[1] = make_unique<Sting>();
    moves[2] = make_unique<Metamorphosis>();
    moves[3] = make_unique<NaturesImperative>();

    if (isPlayer) {
        p.print("What is your Wizard Name?\n"
            "\n"
            ": ");
        cin.ignore();
        getline(cin, name);
        name = p.format(name, "green");
        system("clear");
    } else {
        name = "Foulgaze";
    }
}

void Wizard_Life::printSchool() {
    p.print("Life\n", "green");
}

void Wizard_Life::printName() {
    p.print(name, "green");
}
