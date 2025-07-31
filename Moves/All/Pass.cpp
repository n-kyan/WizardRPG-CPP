#include "../Move.h"
#include "../../Wizards/Wizard.h"

Pass::Pass() {
	name = "Pass";
	description = "";
    pipCost = 0;
    accuracy = 100;
}

void Pass::use([[maybe_unused]] Wizard& user, [[maybe_unused]] Wizard& target) {
    p.print(user.getName() + " passes their turn\n", "default", "default", NORMAL, YES);
}