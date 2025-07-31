#include "../Move.h"
#include "../../Wizards/Wizard.h"

Sting::Sting() {
	name = "Sting";
	description = "";
    pipCost = 1;
    accuracy = 80;
}

void Sting::use([[maybe_unused]] Wizard& user, Wizard& target) {
    p.print("A giant wasp appears and dives towards " + target.getName() + ", stinging them.\n", "default", "default", NORMAL, YES);

    target.modHealth(-20);
}