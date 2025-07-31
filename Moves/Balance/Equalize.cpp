#include "../Move.h"
#include "../../Wizards/Wizard.h"

Equalize::Equalize() {
	name = "Equalize";
	description = "";
    pipCost = 2;
    accuracy = 80;
}

void Equalize::use(Wizard& user, Wizard& target) {
    p.print("Perfectly balanced, as all things should be.\n", "default", "default", NORMAL, YES);

    uint16_t avgHealth = (target.getHealth() + user.getHealth()) / 2;

    user.modHealth(avgHealth - user.getHealth());
    target.modHealth(avgHealth - target.getHealth());

}