#include <iostream>
#include <sstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "Testing validation\n";
    string choice;
    bool invalid = true;

    cout << "Choose 1 or 2:\n";
    getline(cin, choice);
//    cin >> choice;
//    cout << "String length is " << choice.length() << endl;

    while (invalid) {
        if (choice.length() >= 1 && choice != "1" && choice != "2") {
            cout << "Invalid input!\n";
            cout << "Please enter 1 or 2\n";
            getline(cin, choice);
        }
        else {
            if (choice == "1") {
                cout << "You have selected choice 1\n";
                return 0;
            }
            else if (choice == "2") {
                cout << "You have selected choice 2\n";
                return 0;
            }
            invalid = false;
        }
    }
}