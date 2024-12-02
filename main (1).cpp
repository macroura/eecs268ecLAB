#include <iostream>
#include <iomanip>
#include <string>

// Add this line to avoid repeating std::
using namespace std;

double extractNumeric(const string& str) {
    double finishedNumber = 0.0;
    bool negative = false;
    int i = 0;
    bool decimalActive = false;
    double decimal = 1.0;

    if (str.empty()) {
        return -999999.99;
    }

    if (str[0] == '-') {
        negative = true;
        i++;
    } else if (str[0] == '+') {
        i++;
    }

    for (; i < str.size(); i++) {
        char c = str[i];

        if (c == '.' && !decimalActive) {
            decimalActive = true;
            continue;
        } else if (c >= '0' && c <= '9') {
            if (decimalActive) {
                decimal /=10;
                finishedNumber += decimal * (c- '0');
            } else {
                finishedNumber = finishedNumber * 10 + (c-'0');
            }
        } else {
            return -999999.99;
        }
    }

    if (negative) {
        finishedNumber = -finishedNumber;
    }

    return finishedNumber;
}

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                 << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}
