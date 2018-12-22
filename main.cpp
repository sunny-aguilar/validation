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
int validateNumber(int min, int max);
int validateStartingSelection();

int main() {
//    validateSelection();
//    cout << "Returning value " << validateSize();
//    validateNumber(1, 1000);
    cout << "Returning value " << validateStartingSelection();

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

            if (boardSize > 1 && boardSize <= 100) {
                cout << "You entered " << boardSize << endl;
            }
            else {
                notInRange = true;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return boardSize;
}

/*********************************************************************
** Description:     Validate number of rows and columns for the board
*********************************************************************/
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

/*********************************************************************
** Description:     Validate number of rows and columns for the board
*********************************************************************/
int validateNumber(int min, int max) {
    char choice[100];
    int steps = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    // determine # of digits in max value acceptable
    long unsigned length = std::to_string(max).length();

    do {
        cout << "Enter an integer between " << min << " and " << max << endl;
        cin.getline(choice, 100);

        // check if length is greater than 3
        tooLong = false;
        if (strlen(choice) > length) {
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
            convert >> steps;

            if (steps >= min && steps <= max) {
                cout << "You entered " << steps << endl;
            }
            else {
                notInRange = true;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return steps;
}
/*********************************************************************
** Description:     Validate start location of the ant
*********************************************************************/
int validateStartingSelection() {
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
            }
            else if (choice == "2") {
                cout << "You have selected choice 2\n";
            }
            invalid = false;
        }
    }

    return stoi(choice);


//    string start;
//    getline(cin, start);
//
//    regex validMatch("^[1-2]{1}$");
//    std::smatch m;
//
//    while (!std::regex_match(start, m, validMatch)) {
//        cout << "Invalid Input!\n\n"
//             << "Enter again: ";
//        getline(cin, start);
//    }
//    switch (std::stoi(start)) {
//        case 1:
//            cout << "Custom starting position\n";
//            break;
//        case 2:
//            cout << "Random starting position\n";
//            break;
//        default:
//            cout << "Invalid selection!\n";
//    }
//
//    cout << "Selection made is " << start << endl;
//    return returnInteger(start);
}