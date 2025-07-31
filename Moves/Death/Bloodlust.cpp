#include "../Move.h"
#include "../../Wizards/Wizard.h"

Bloodlust::Bloodlust() {
	name = "Bloodlust";
	description = "";
    pipCost = 2;
    accuracy = 75;
}

void Bloodlust::use(Wizard& user, Wizard& target) {

    p.print("A pale face with a sharp smile appears from a group of hooded figures. He appears to sap energy from " + target.getName() + " and give it to " + user.getName() + ".\n", "default", "default", NORMAL, YES);

    target.modHealth(-30);
    user.modHealth(15);
}