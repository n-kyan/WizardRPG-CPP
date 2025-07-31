#include "Wizard.h"

Wizard_Death::Wizard_Death(bool isPlayer) : 
    Wizard(isPlayer, 120)
{
    health = MAX_HEALTH;
    passiveAbility = make_unique<Passive_Death>();
    moves[1] = make_unique<SuckerPunch>();
    moves[2] = make_unique<Bloodlust>();
    moves[3] = make_unique<DeathsDoor>();

    if (isPlayer) {
        p.print("What is your Wizard Name?\n"
            "\n"
            ": ");
        cin.ignore();
        getline(cin, name);
        name = p.format(name, "bright-black");
        system("clear");
    } else {
        name = "Foulgaze";
    }
}

void Wizard_Death::printSchool() {
    p.print("Death\n", "black", "bright-black");
}

void Wizard_Death::printName() {
    p.print(name, "black", "bright-black");
}
