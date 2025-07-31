#include "../Move.h"
#include "../../Wizards/Wizard.h"

DeathsDoor::DeathsDoor() {
	name = "Death's Door";
	description = "";
    pipCost = 10;
    accuracy = 70;
}

void DeathsDoor::use([[maybe_unused]] Wizard& user, Wizard& target) {
    p.print("A giant robed skeleton emerges from a graveyard and slashes at " + target.getName() + ".\n", "default", "default", NORMAL, YES);

    target.modHealth(-20);
    target.modPips(-target.getNumPips());
}