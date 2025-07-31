#include "../Move.h"
#include "../../Wizards/Wizard.h"

Passive_Death::Passive_Death() {
    name = "Death Wizard Passive Ability";
    description = "Death Wizards passively improve accuracy by 5% each turn";
    pipCost = 0;
    accuracy = 100;
}

void Passive_Death::use(Wizard& user, [[maybe_unused]] Wizard& target) {
    p.print(target.getName() + " accuracy increased by 5%.\n", "default", "default", NORMAL, YES);
    
    user.modAccuracy(5);
}