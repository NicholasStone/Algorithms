//
// Created by Nicho on 2018/12/1 0001.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int valueOf(char c) {
    switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(string s) {
    int sum = 0;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (valueOf(s[i]) < valueOf(s[i + 1])) {
            sum += valueOf(s[i + 1]) - valueOf(s[i]);
            i++;
        } else {
            sum += valueOf(s[i]);
        }
    }

    return sum;
}

int main(int argc, char const *argv[]) {
    string number = "MCMXCIV";
    int n = romanToInt(number);
    cout << n << endl;
    return 0;
}