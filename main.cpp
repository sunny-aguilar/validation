#include <iostream>
#include <sstream>
#include <string>
#include <regex>
using std::cin;
using std::cout;
using std::endl;
using std::string;

string validateSelection();
int validateSize();
string validateSizeRegex();
int validateSteps();

int main() {
//    validateSelection();
//    cout << "Returning value " << validateSize();
    validateSteps();

}
/*********************************************************************
** Description:     Validate number of rows for the board
*********************************************************************/
string validateSelection() {
    cout << "Testing validation\n";
    string choice;
    bool invalid = true;

    cout << "Choose 1 or 2:\n";
    getline(cin, choice);

    while (invalid) {
        if (choice.length() >= 1 && choice != "1" && choice != "2") {
            cout << "Invalid input!\n";
            cout << "Please enter 1 or 2\n";
            getline(cin, choice);
        }
        else {
            if (choice == "1") {
                cout << "You have selected choice 1\n";
                return choice;
            }
            else if (choice == "2") {
                cout << "You have selected choice 2\n";
                return choice;
            }
            invalid = false;
        }
    }
}

/*********************************************************************
** Description:     Validate number of rows and columns for the board
*********************************************************************/
int validateSize() {
    char choice[100];
    int boardSize = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    do {
        cout << "Enter an integer between 2 and 100\n";
        cin.getline(choice, 100);

        // check if length is greater than 3
        tooLong = false;
        if (strlen(choice) > 3) {
            tooLong = true;
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (int i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }

        // check if characters entered are within range
        notInRange = false;
        if (isNotDigit == false && tooLong == false) {
            convert.clear();
            convert << choice;
            convert >> boardSize;

            if (boardSize <= 100 && boardSize > 1) {
                cout << "You entered " << boardSize << endl;
            }
            else {
                notInRange = true;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return boardSize;
}

string validateSizeRegex() {
    string choice;
    std::regex validMatch("^[2-9]|[1-9][0-9]|100$");
//    regex validMatch("^[1-9]|[1-9][0-9]|[1-9][0-9][0-9]|1000$");
    std::smatch m;

    while (!std::regex_match(choice, m, validMatch)) {
        cout << "Please enter a valid selection between 2-100\n";
        getline(cin, choice);
    }
    cout << "You have selected " << choice << endl;

    return choice;
}

int validateSteps() {
    char choice[100];
    int boardSize = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    do {
        cout << "Enter an integer between 2 and 100\n";
        cin.getline(choice, 100);

        // check if length is greater than 3
        tooLong = false;
        if (strlen(choice) > 3) {
            tooLong = true;
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (int i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }

        // check if characters entered are within range
        notInRange = false;
        if (isNotDigit == false && tooLong == false) {
            convert.clear();
            convert << choice;
            convert >> boardSize;

            if (boardSize <= 100 && boardSize > 1) {
                cout << "You entered " << boardSize << endl;
            }
            else {
                notInRange = true;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return 0;

//    string steps;
//    getline(cin, steps);
//
//    regex validMatch("^[1-9]|[1-9][0-9]|[1-9][0-9][0-9]|1000$");
//    std::smatch m;
//
//    while (!std::regex_match(steps, m, validMatch)) {
//        cout << "Please enter a valid number of steps between 1 and 1000\n";
//        getline(cin, steps);
//    }
//    cout << "You have selected " << steps << " steps in the simulation\n\n";
//
//    return returnInteger(steps);
}
