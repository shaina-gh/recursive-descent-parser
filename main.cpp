#include <iostream>
#include <string>

using namespace std;

class RecursiveDescentParser {
private:
    string input;
    int index;

    char peek() {
        if (index < input.size())
            return input[index];
        return '\0'; // End of input
    }

    char getNextChar() {
        return input[index++];
    }

    void error(string message) {
        cerr << "Error: " << message << " at position " << index << endl;
        exit(1);
    }

    void match(char expected) {
        if (peek() == expected) {
            getNextChar();
        } else {
            error(string("Expected '") + expected + "'");
        }
    }

    // Grammar: S → aSb | c
    void S() {
        if (peek() == 'a') {
            match('a');
            S();
            match('b');
        } else if (peek() == 'c') {
            match('c');
        } else {
            error("Invalid character in input");
        }
    }

public:
    RecursiveDescentParser(string input) : input(input), index(0) {}

    void parse() {
        S(); // Start parsing from S
        if (index != input.size()) {
            error("Unexpected characters at the end of input");
        } else {
            cout << "The input string is valid according to the grammar." << endl;
        }
    }
};

int main() {
    string inputString;
    cout << "Enter a string: ";
    cin >> inputString;

    RecursiveDescentParser parser(inputString);
    try {
        parser.parse();
    } catch (...) {
        cout << "Failed to parse the input string." << endl;
    }

    return 0;
}
