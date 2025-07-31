#include "../Move.h"
#include "../../Wizards/Wizard.h"

Passive_Life::Passive_Life() {
    name = "Life Wizard Passive Ability";
    description = "Life Wizards passively regenerate 5 health each turn";
    pipCost = 0;
    accuracy = 100;
}

void Passive_Life::use(Wizard& user, [[maybe_unused]] Wizard& target) {
    p.print(target.getName() + " healed 5 health.\n", "default", "default", NORMAL, YES);
    
    user.modHealth(5);
}