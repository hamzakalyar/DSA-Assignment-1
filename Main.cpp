#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"

using namespace std;

bool isValidExpression(const string& expression) {
    Stack s;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.Push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;

            char topChar;
            s.Pop(topChar);

            
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}


string readFileAndSelectLine(const string& filename) {
    ifstream file(filename);
    string line;
    int lineNumber = 0;

    if (!file) {
        cerr << "Error: Could not open the file '" << filename << "'." << endl;
        return "";
    }

    cout << "File contents:\n";
    while (getline(file, line)) {
        cout << ++lineNumber << ": " << line << endl;
    }


    int selectedLine;
    cout << "Enter the line number to check: ";
    cin >> selectedLine;

    
    file.clear();
    file.seekg(0, ios::beg);

    lineNumber = 0;
    while (getline(file, line)) {
        if (++lineNumber == selectedLine) {
            return line;
        }
    }

    return "";
}

int main() {
    string filename = "Data.txt";

    
    string selectedLine = readFileAndSelectLine(filename);

    if (selectedLine.empty()) {
        cerr << "Error: Invalid selection or empty file." << endl;
        return 1;
    }

    
    if (isValidExpression(selectedLine)) {
        cout << "The expression is valid." << endl;
    }
    else {
        cout << "The expression is not valid." << endl;
    }

    return 0;
}
