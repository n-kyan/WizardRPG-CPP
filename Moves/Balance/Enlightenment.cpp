#include "../Move.h"
#include "../../Wizards/Wizard.h"

Enlightenment::Enlightenment() {
	name = "Enlightenment";
	description = "";
    pipCost = 1;
    accuracy = 90;
}

void Enlightenment::use(Wizard& user, [[maybe_unused]] Wizard& target) {
    p.print(user.getName() + " sits to meditate and begins to glow.\n", "default", "default", NORMAL, YES);

    user.modHealth(10);
    user.modPips(1);
    user.modAccuracy(10);
}