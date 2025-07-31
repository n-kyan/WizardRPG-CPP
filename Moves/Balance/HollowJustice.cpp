#include "../Move.h"
#include "../../Wizards/Wizard.h"

HollowJustice::HollowJustice() {
	name = "Hollow Justice";
	description = "";
    pipCost = 10;
    accuracy = 75;
}

void HollowJustice::use(Wizard& user, Wizard& target) {
    pipCost = user.getNumPips();

    p.print("Lady justice lifts up her blindfold to tip her scale in favor of " + user.getName() + " and delivers her verdict.\n", "default", "default", NORMAL, YES);

    user.modPips(target.getNumPips());
    target.modPips(-target.getNumPips());
    target.modHealth(-(15 * user.getNumPips()));
}