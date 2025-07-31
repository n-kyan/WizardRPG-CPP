#include "../Move.h"
#include "../../Wizards/Wizard.h"

NaturesImperative::NaturesImperative() {
	name = "Nature's Imperative";
	description = "";
	pipCost = 10;
	accuracy = 60;
}

void NaturesImperative::use(Wizard& user, Wizard& target) {
    p.print("A colossal bear rears up and flashed its flattened face and massive jaws lined with bone crushing teeth. It lunges at " + target.getName() + ".\n", "default", "default", NORMAL, YES);

	target.modHealth(-(user.getNumPips() * 30));
}