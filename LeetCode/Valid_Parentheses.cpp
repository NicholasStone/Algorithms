#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isMatch(char c, char x) {
    switch (c) {
        case '(':
            return x == ')';
        case '[':
            return x == ']';
        case '{':
            return x == '}';
        default:
            return false;
    }
}

bool isValid(string s) {
    stack<char> parentheses;
    for (char c : s) {
        if (c == ')' || c == ']' || c == '}') {
            if (!parentheses.empty() && isMatch(parentheses.top(), c)) {
                parentheses.pop();
            } else {
                return false;
            }
        } else {
            parentheses.push(c);
        }
    }
    return parentheses.empty();
}

int main(int argc, char const *argv[]) {
    string s = "{}";
    cout << isValid(s) << endl;
    return 0;
}