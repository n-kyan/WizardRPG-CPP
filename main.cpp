#include <iostream>
#include "Wizards/Wizard.h"
#include "Battle.h"
#include "utils.h"


using namespace std;

int main() {
    system("clear");

    unique_ptr<Wizard> w1;
    unique_ptr<Wizard> w2;


    p.print(
        "Hi, my name is "
        + p.format("Kyan Nelson", "blue", "default", BOLD) +
        ". I am a "
        + p.format("Finance & Computer Science", "bright-blue") +
        " major at CU Boulder.\n"
        "This is a classic RPG style game that I created in order to sharpen my "
        + p.format("C++", "bright-red", "default") + 
        " skills and learn some new concepts like "
        + p.format("unique pointers", "bright-red", "default") +
        ", "
        + p.format("efficient data types (+templating)", "bright-red", "default") +
        " and "
        + p.format("polymorphism", "bright-red", "default") +
        " in a practical way.\n"
    );
    p.print("\nAlso, I think programming is really fun.\n", "default", "default", BOLD);

    uint8_t playerCount = 2;
    inputValid_uint<uint8_t>("\n Enter 1 to start.", 1, 1);

    // uint8_t playerCount = inputValid_uint<uint8_t>(
    //     "\nTo start, select the number of players.\n"
    //     "\t0: Simulate a battle\n"
    //     "\t1: Play against an NPC\n"
    //     "\t2: 1v1 against two players locally",
    //     0, 2
    // );
    
    switch (playerCount) {
        case 0:
            p.print("Player 1:\n");
            w1 = createWizard(false);
            p.print("Player 2:\n");
            w2 = createWizard(false);
            break;

        case 1:
            p.print("Player 1:\n");
            w1 = createWizard(true);
            p.print("Player 2:\n");
            w2 = createWizard(false);
            break;

        case 2:
            p.print("Player 1:\n");
            w1 = createWizard(true);
            p.print("Player 2:\n");
            w2 = createWizard(true);
            break;
            
        default:
            cout << "Invalid player count" << endl;
            return 1;
            break;
        }

        Battle battle(std::move(w1), std::move(w2)); // move to function parameters
        battle.run();

    return 0;
}
