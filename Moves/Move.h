#ifndef MOVE_H
#define MOVE_H

#include <random>
#include "../SpecialPrinter.h"

using namespace std;

enum class School { LIFE, DEATH, BALANCE };

// Forward Declaration (avoids circular dependency)
class Wizard;

class Move {
	protected:
		string name;
		string description;
		School school;
		uint8_t pipCost;
		uint8_t accuracy;

	public:
		virtual ~Move() = default;
		bool rollOdds(uint8_t finalAccuracy);
		void attempt(Wizard& user, Wizard& target);
		
		virtual void use(Wizard& user, Wizard& target) = 0;

		const string& getName() const;
		const string& getDesc() const;
		School getSchool() const; // enum type
		uint8_t getPipCost() const;
		uint8_t getAccuracy() const;
};

// All Schools
class Pass : public Move {
	public:
		Pass();
		void use(Wizard& user, Wizard& target) override;
};

// Life Moves
class Passive_Life : public Move {
	public:
		Passive_Life();
		void use(Wizard& user, Wizard& target) override;
};

class Sting : public Move {
	public:
		Sting();
		void use(Wizard& user, Wizard& target) override;
};

class Metamorphosis : public Move {
	public:
		Metamorphosis();
		void use(Wizard& user, Wizard& target) override;
};

class NaturesImperative : public Move {
	public:
		NaturesImperative();
		void use(Wizard& user, Wizard& target) override;
};

// Death Moves
class Passive_Death : public Move {
	public:
		Passive_Death();
		void use(Wizard& user, Wizard& target) override;
};

class SuckerPunch : public Move {
	public:
		SuckerPunch();
		void use(Wizard& user, Wizard& target) override;
};

class Bloodlust : public Move {
	public:
		Bloodlust();
		void use(Wizard& user, Wizard& target) override;
};

class DeathsDoor : public Move {
	public:
		DeathsDoor();
		void use(Wizard& user, Wizard& target) override;
};

// Balance Moves
class Passive_Balance : public Move {
	public:
		Passive_Balance();
		void use(Wizard& user, Wizard& target) override;
};

class Enlightenment : public Move {
	public:
		Enlightenment();
		void use(Wizard& user, Wizard& target) override;
};

class Equalize : public Move {
	public:
		Equalize();
		void use(Wizard& user, Wizard& target) override;
};

class HollowJustice : public Move {
	public:
		HollowJustice();
		void use(Wizard& user, Wizard& target) override;
};
#endif
