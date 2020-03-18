#include <iostream>
#include "game/GameTester.h"

int main() {

    GameTester gameTester;
    vector<string> NAME;
    NAME.push_back("guessmynumber");
    NAME.push_back("Guess");
    NAME.push_back("heros_inventory");
    NAME.push_back("heros_inventory2");
    NAME.push_back("tic_tac_toe_board");
    NAME.push_back("word_jumble");


    while (1){
        cout << "\n\nWe have " << NAME.size() << " games.\n";
        cout << "\nOur games:\n";
        for (unsigned int i = 0; i < NAME.size(); ++i) {
            cout << NAME[i] << endl;
        }
        cout << "Enter 'quit' to quit the game.\n\n";

        string gameName;
        cout << "Enter gamename to choose the game:";
        cin >> gameName;


        if (gameName == NAME[0]) {
            gameTester.guessMyNumber();
        } else if (gameName == NAME[1]) {
            gameTester.Guess();
        } else if (gameName == NAME[2]) {
            gameTester.heros_inventory();
        } else if (gameName == NAME[3]) {
            gameTester.heros_inventory2();
        } else if (gameName == NAME[4]) {
            gameTester.tic_tac_toe_board();
        } else if (gameName == NAME[5]) {
            gameTester.word_jumble();
        } else if (gameName == "quit") {
            break;
        }
    }

    return 0;
}
