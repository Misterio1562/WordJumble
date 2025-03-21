#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 3;
    const string WORDS[NUM_WORDS][NUM_FIELDS] = {
        {"wall", "wall"},
        {"glass", "glass"},
        {"brick", "brick"}
    };

    srand(static_cast<unsigned int>(time(0)));
    int choice = rand() % NUM_WORDS;
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];

    string jumble = theWord;
    int length = jumble.size();
    for(int i = 0; i < length; i++) {
        int index1 = rand() % length;
        int index2 = rand() % length;

        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    cout << "\t\tWelcome to Word Jumble!\n";
    cout << "Enter 'hint' for hint\n";
    cout << "Enter 'quit' for quit\n";
    cout << "Jumble is: " << jumble << endl;

    string guess;
    do {
        cout << "\nYour guess: ";
        cin >> guess;
        if(guess == "hint") {
            cout << theHint;
        }
        else if(guess == theWord) {
            cout << "Yeah! it's it!";
        }
        else {
            cout << "Sorry, it's not a secret word";
        }
    } while(guess != theWord && guess != "quit");
    cout << "\nThanks for playing!";

    return 0;
}
