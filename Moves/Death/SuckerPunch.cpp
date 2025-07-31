#include "../Move.h"
#include "../../Wizards/Wizard.h"

SuckerPunch::SuckerPunch() {
	name = "Sucker Punch";
	description = "";
    pipCost = 1;
    accuracy = 70;
}

void SuckerPunch::use([[maybe_unused]] Wizard& user, Wizard& target) {
    p.print("A large shadowy fist extends from " + user.getName() + "'s arm as he throws a hook toward " + target.getName() + ".\n", "default", "default", NORMAL, YES);

    target.modHealth(-40);
}