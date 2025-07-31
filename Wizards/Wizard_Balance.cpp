#include "Wizard.h"

Wizard_Balance::Wizard_Balance(bool isPlayer) : 
    Wizard(isPlayer, 100)
{
    health = MAX_HEALTH;
    passiveAbility = make_unique<Passive_Balance>();
    moves[1] = make_unique<Enlightenment>();
    moves[2] = make_unique<Equalize>();
    moves[3] = make_unique<HollowJustice>();

    if (isPlayer) {
        p.print("What is your Wizard Name?\n"
            "\n"
            ": ");
        cin.ignore();
        getline(cin, name);
        name = p.format(name, "bright-yellow");
        system("clear");
    } else {
        name = "Foulgaze";
    }
}

void Wizard_Balance::printSchool() {
    p.print("Balance\n", "bright-yellow");
}

void Wizard_Balance::printName() {
    p.print(name, "bright-yellow");
}
