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

int main() {
//    validateSelection();
    cout << "Returning value " << validateSize();

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
    string row;
    char choice[100];
    int intValue = 0;
    std::stringstream convert;
    bool invalid = true;
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
            // if digit is not true, then set it true so that
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
            convert >> intValue;

            if (intValue <= 100 && intValue > 1) {
                cout << "You entered " << intValue << endl;
            }
            else {
                notInRange = true;
            }
        }


    } while (tooLong || isNotDigit || notInRange);



//    do {
//        while (strlen(choice) > 3) {
//            cout << "You must enter no more than 3 numbers\n";
//            cin >> choice;
//        }
//        convert << choice;
//        convert.clear();
//        convert >> intValue;
//
//        while (!isDigit) {
//            for (int i = 0; i < strlen(choice); i++) {
//                // if digit is not true, then set it true so that
//                // loop will repeat
//                if (!isdigit(choice[i])) {
//                    isDigit = true;
//                }
//            }
//
//            if (isDigit) {
//                cout << "Do not enter characters!\n";
//                cout << "You must enter an integer between 2 and 100\n";
//                cin >> choice;
//                convert.clear();
//                convert << choice;
//                convert >> intValue;
//            }
//        }
//        cout << "Congrats! You entered " << intValue << endl;
//        invalid = false;

//        if (intValue <= 100 && intValue > 1) {
//            cout << "You entered " << intValue << endl;
//        } else {
//            cout << "Enter a value between 2 and 100\n";
//            getline(cin, row);
//            convert.clear();
//            convert << row;
//            convert >> intValue;
//        }
//    } while (invalid);


//    while (invalid) {
//        while (!isDigit) {
//            for (int i = 0; i < strlen(choice); i++) {
//                if (!isdigit(choice[i])) {
//                    isDigit = true;
//                }
//            }
//            cout << "You must enter a number only!\n";
//            cin >> choice;
//            convert << choice;
//            convert.clear();
//            convert >> intValue;
//        }
//        invalid = false;
//        cout << "Valid number entered\n";

//        while (strlen(choice) > 1) {
//            cout << "You must enter a number only!\n";
//            cin >> choice;
//            convert << choice;
//            convert.clear();
//            convert >> intValue;
//        }
//
//        if (intValue > 100 || intValue < 2) {
//            cout << "Please enter a valid selection between 2-100\n";
//            cin >> choice;
//            convert.clear();
//            convert << choice;
//            convert >> intValue;
////            cout << "intValue in while loop is " << intValue << endl;
//        }
//        else if (intValue <= 100 && intValue >= 2) {
//            cout << "You entered " << intValue << endl;
//            invalid = false;
//            return intValue;
//        }
//    }



//
//    for (int i = 0; i < strlen(choice); i++) {
//        if (!isdigit(choice[i])) {
//            cout << "You must enter a number only!\n";
//        }
//        else {
//            // convert s-string into a stream
//            convert << choice;
//            // concatenate c-string into a string
//            convert >> intValue;
//
//            while (invalid) {
//
//                if (intValue > 100 || intValue < 2) {
//                    cout << "Please enter a valid selection between 2-100\n";
//                    cin >> choice;
//                    convert.clear();
//                    convert << choice;
//                    convert >> intValue;
////                    cout << "intValue in while loop is " << intValue << endl;
//                }
//                else if (intValue <= 100 && intValue >= 2) {
//                    cout << "You entered " << intValue << endl;
//                    invalid = false;
//                }
//            }
//        }
//    }
//
//    // debugging code
////    cout << "C-string length is " << strlen(choice) << endl;
////    cout << "Is digit " << isdigit(choice[0]) << endl;
//
    return intValue;

}

string validateSizeRegex() {
    string choice;
    std::regex validMatch("^[2-9]|[1-9][0-9]|100$");
    std::smatch m;

    while (!std::regex_match(choice, m, validMatch)) {
        cout << "Please enter a valid selection between 2-100\n";
        getline(cin, choice);
    }
    cout << "You have selected " << choice << endl;

    return choice;
}