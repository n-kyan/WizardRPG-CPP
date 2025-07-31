#include "../Move.h"
#include "../../Wizards/Wizard.h"

Metamorphosis::Metamorphosis() {
	name = "Metamorphosis";
	description = "";
	pipCost = 2;
	accuracy = 80;
}

void Metamorphosis::use(Wizard& user, [[maybe_unused]] Wizard& target) {
    p.print("A cocoon encapsulates " + user.getName() + ". They emerge stronger than before.\n", "default", "default", NORMAL, YES);

	user.modHealth(20);
	user.modAccuracy(20);

}