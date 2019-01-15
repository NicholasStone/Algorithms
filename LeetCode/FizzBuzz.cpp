//
// Created by Nicho on 2018/11/29 0029.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> result;
    string Fizz = "Fizz";
    string Buzz = "Buzz";
    for (int i = 1; i <= n; i++) {
        string s = "";
        if (!(i % 3)) s += Fizz;
        if (!(i % 5)) s += Buzz;
        if (s.empty()) s += to_string(i);
        result.push_back(s);
    }
    return result;
}

int main(int argc, char const *argv[]) {
    for (string str: fizzBuzz(15))
        cout << str << endl;
    return 0;
}