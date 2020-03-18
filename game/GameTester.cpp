//
// Created by hehaowei on 2020/3/18.
//

#include "GameTester.h"


/*
 * *猜数小游戏，猜中计算机随机出来的数字
 */
void GameTester::guessMyNumber() {
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int tries = 0;
    int guess;
    cout << "Welcome to Guess My Number" << endl;
    do {
        cout << "Enter a guess";
        cin >> guess;
        ++tries;
        if (guess > secretNumber) {
            cout << "too High\n\n";
        } else if (guess < secretNumber) {
            cout << "too Low\n\n";
        } else {
            cout << "\nThat is it! You get it in " << guess << " guess!\n";
        }
    } while (guess != secretNumber);

}

/*
 * *让计算机猜数字
 */
void GameTester::Guess() {
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber;
    int tries = 0;
    int guess;
    cout << "Welcome to Guess My Number" << endl;
    cout << "Enter a secretNumber";
    cin >> secretNumber;
    do {
        guess = rand() % 100 + 1;
        ++tries;
        cout << "My guess is " << guess << "is right?" << endl;
        if (guess > secretNumber) {
            cout << "too High\n\n";
        } else if (guess < secretNumber) {
            cout << "too Low\n\n";
        } else {
            cout << "\nThat is it! I get it in " << tries << " guess!\n";
        }
    } while (guess != secretNumber);

}

/*
 * *英雄物品
 */
void GameTester::heros_inventory() {
    const int MAX_ITEMS = 10;
    string inventory[MAX_ITEMS];

    int numItems = 0;
    inventory[numItems++] = "sword";
    inventory[numItems++] = "armor";
    inventory[numItems++] = "shield";

    cout << "Your items:\n";
    for (int i = 0; i < numItems; ++i) {
        cout << inventory[i] << endl;
    }

    cout << "\nYou trade your sword for a battle axe.";
    inventory[0] = "battle axe";
    cout << "\nYour items:\n";
    for (int i = 0; i < numItems; ++i) {
        cout << inventory[i] << endl;
    }

    cout << "\nThe item name '" << inventory[0] << "' has ";
    cout << inventory[0].size() << " letters in it.\n";

    cout << "\nYou find a healing potion.";
    if (numItems < MAX_ITEMS) {
        inventory[numItems++] = "healing potion";
    } else {
        cout << "You have too many items and can't carry another.";
    }
    cout << "\nYour items:\n";
    for (int i = 0; i < numItems; ++i) {
        cout << inventory[i] << endl;
    }
}


/*
 * *下棋游戏
 */
void GameTester::tic_tac_toe_board() {
    const int ROWS = 3;
    const int COLUMNS = 3;
    char board[ROWS][COLUMNS] = {{'O', 'X', 'O'},
                                 {' ', 'X', 'X'},
                                 {'X', 'O', 'O'}};

    cout << "Here's the tic-tac-toe board:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            cout << board[i][j];
        }

        cout << endl;
    }

    cout << "\n'X' moves to the empty location.\n\n";
    board[1][0] = 'X';

    cout << "Now the tic-tac-toe board is:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            cout << board[i][j];
        }

        cout << endl;
    }

    cout << "\n'X' wins!";

}


/*
 * *猜单词
 */
void GameTester::word_jumble() {
    enum fields {
        WORD, HINT, SCORE, NUM_FIELDS
    };
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
            {
                    {"wall",       "Do you feel you're banging your head against something?", "4"},
                    {"glasses",    "These might help you see the answer.",                    "7"},
                    {"labored",    "Going slowly, is it?",                                    "7"},
                    {"persistent", "Keep at it.",                                             "10"},
                    {"jumble",     "It's what the game is all about.",                        "6"}
            };

    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "You have 10 initial points at the beginning of the game, and each hint will cost 5 points\n";
    cout << "When the points are exhausted, the game is over\n\n";

    string guess;
    int score = 10;
    while (score > 0) {
        srand(static_cast<unsigned int>(time(0)));
        int choice = (rand() % NUM_WORDS);
        string theWord = WORDS[choice][WORD];  // word to guess
        string theHint = WORDS[choice][HINT];  // hint for word
        string theScore = WORDS[choice][SCORE];  // score for word

        string jumble = theWord;  // jumbled version of word
        int length = jumble.size();
        for (int i = 0; i < length; ++i) {
            int index1 = (rand() % length);
            int index2 = (rand() % length);
            char temp = jumble[index1];
            jumble[index1] = jumble[index2];
            jumble[index2] = temp;
        }


        cout << "\nThe jumble is: " << jumble;

        cout << "\n\nYour score: " << score << "\n";
        cout << "Your guess: ";
        cin >> guess;
        if (guess == "quit") {
            break;
        }
        while ((guess != theWord) && (guess != "quit") && (score > 0)) {
            if (guess == "hint") {
                cout << theHint;
                cout << "You asked for a reminder, deduct 5 points";
                score -= 5;
            } else {
                cout << "Sorry, that's not it.";
            }
            cout << "\n\nYour score: " << score << "\n";
            cout << "Your guess: ";
            cin >> guess;
        }

        if (guess == theWord) {
            cout << "\nThat's it!  You guessed it!\n";
            cout << "\nYou get " << score << " points\n";
            score += stoi(theScore);
            cout << "You have " << score << " points\n";
        }
    }

    if (score <= 0) {
        cout << "\nYour points have been exhausted, the game is over!\n";
    }
    cout << "\nThanks for playing.\n";
}


/*
 * *英雄物品2
 */
void GameTester::heros_inventory2() {
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    cout << "You have " << inventory.size() << " items.\n";

    cout << "\nYour items:\n";
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        cout << inventory[i] << endl;
    }

    cout << "\nYou trade your sword for a battle axe.";
    inventory[0] = "battle axe";
    cout << "\nYour items:\n";
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        cout << inventory[i] << endl;
    }

    cout << "\nThe item name '" << inventory[0] << "' has ";
    cout << inventory[0].size() << " letters in it.\n";

    cout << "\nYour shield is destroyed in a fierce battle.";
    inventory.pop_back();
    cout << "\nYour items:\n";
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        cout << inventory[i] << endl;
    }

    cout << "\nYou were robbed of all of your possessions by a thief.";
    inventory.clear();
    if (inventory.empty()) {
        cout << "\nYou have nothing.\n";
    } else {
        cout << "\nYou have at least one item.\n";
    }
}
