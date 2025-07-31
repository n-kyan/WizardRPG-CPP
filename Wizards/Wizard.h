#ifndef WIZARD_H
#define WIZARD_H

#include <string>
#include <vector>
#include "../Moves/Move.h"

using namespace std;
    
struct Level {
    uint8_t levelValue;
    uint32_t curExperience;
    uint32_t reqExperience;
};

class Wizard {
    protected:
        static const uint8_t MAX_PIPS = 10;
        static const uint8_t MAX_ACCURACY = 100;
        static const uint8_t MAX_LEVEL = 255;
        static const uint8_t MAX_MOVES = 3;
        static const uint8_t NUM_MOVES = 4;

        const bool isPlayer;
        string name;
        
        const uint16_t MAX_HEALTH;
        uint16_t health;
        uint8_t numPips;
        uint8_t accuracy; // final odds to land = (spellAccuracy  * (1 + c.accuracy))
    
        unique_ptr<Level> level;
        unique_ptr<Move> passiveAbility;
        array<unique_ptr<Move>, NUM_MOVES> moves;


        // uint8_t mana; could be added later but doesn't really add much to gameplay rn

    public:
        Wizard(bool isPlayer, uint16_t maxHealth);
        virtual ~Wizard() = default;

        Move& pickMove();
        void printState();
        virtual void printName() = 0;
        virtual void printSchool() = 0;
        
        // Getters
        const string& getName() const;
        uint16_t getHealth() const;
        uint16_t getMaxHealth() const;
        uint8_t getNumPips() const;
        uint8_t getAccuracyMultiplier() const;
        const string& getSchoolName() const;
        
        // Setters / Modifiers
        void modHealth(int16_t amount);
        void modAccuracy(int8_t amount);
        void modPips(int8_t amount);
};

class Wizard_Life : public Wizard {
    public:
        Wizard_Life(bool isPlayer);
        void printSchool() override;
        void printName() override;
};

class Wizard_Death : public Wizard {
    public:
        Wizard_Death(bool isPlayer);
        void printSchool() override;
        void printName() override;
};

class Wizard_Balance : public Wizard {
    public:
        Wizard_Balance(bool isPlayer);
        void printSchool() override;
        void printName() override;
};

unique_ptr<Wizard> createWizard(bool isPlayer);

#endif
