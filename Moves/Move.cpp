#include "Move.h"
#include "../Wizards/Wizard.h"

void Move::attempt(Wizard& user, Wizard& target) {
	if (user.getNumPips() < pipCost && pipCost != 10) {
		p.print("Not enough pips to cast " + name + "!\n");
		return;
	}

	uint8_t finalAccuracy = accuracy * (user.getAccuracyMultiplier());

	if (rollOdds(finalAccuracy)) {
		use(user, target);
		user.modPips(-pipCost);
	} else {
		p.print("Your move missed!\n");
	}
}

const string& Move::getName() const {
    return name;
}

const string& Move::getDesc() const {
    return description;
}

School Move::getSchool() const {
    return school;
}

uint8_t Move::getPipCost() const {
    return pipCost;
}

uint8_t Move::getAccuracy() const {
    return accuracy;
}

bool Move::rollOdds(uint8_t finalAccuracy) {
	if (finalAccuracy > 100) {
		finalAccuracy = 100;
	}

	static thread_local mt19937 gen{random_device{}()};
	uniform_int_distribution<int> dist(1, 100);

	return dist(gen) <= finalAccuracy;
}
