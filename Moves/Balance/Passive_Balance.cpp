#include "../Move.h"
#include "../../Wizards/Wizard.h"

Passive_Balance::Passive_Balance() {
    name = "Life Wizard Passive Ability";
    description = "Life Wizards passively regenerate 5 health each turn";

}

void Passive_Balance::use(Wizard& user, [[maybe_unused]] Wizard& target) {
    p.print(target.getName() + " healed 5 health and their accuracy increased by 3%.\n", "default", "default", NORMAL, YES);
    
    user.modHealth(3);
    user.modAccuracy(3);
}