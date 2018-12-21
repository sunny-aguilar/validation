#include <iostream>
#include <sstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

string validateSelection();
int validateSize();

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
** Description:     Validate number of rows for the board
*********************************************************************/
int validateSize() {
    char choice[100];
    int intValue;
    std::stringstream convert;
    bool invalid = true;

    cout << "Enter an integer between 2 and 100\n";
    cin >> choice;

    for (int i = 0; i < strlen(choice); i++) {
        if (!isdigit(choice[i])) {
            cout << "You must enter a number only!\n";
        }
        else {
            // convert s-string into a stream
            convert << choice;
            // concatenate c-string into a string
            convert >> intValue;

            while (invalid) {

                if (intValue > 100 || intValue < 2) {
                    cout << "Please enter a valid selection between 2-100\n";
                    cin >> choice;
                    convert.clear();
                    convert << choice;
                    convert >> intValue;
//                    cout << "intValue in while loop is " << intValue << endl;
                }
                else if (intValue <= 100 && intValue >= 2) {
                    cout << "You entered " << intValue << endl;
                    invalid = false;
                }
            }
        }
    }

    // debugging code
//    cout << "C-string length is " << strlen(choice) << endl;
//    cout << "Is digit " << isdigit(choice[0]) << endl;

    return intValue;

}


//    regex validMatch("^[2-9]|[1-9][0-9]|100$");
//    std::smatch m;
//
//    while (!std::regex_match(choice, m, validMatch)) {
//        cout << "Please enter a valid selection between 2-100\n";
//        getline(cin, choice);
//    }
//    cout << "You have selected " << choice << " " << dimension << endl;

//    return returnInteger(choice);