//
// Created by Nicholas Stone on 2019-01-10.
//
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void toPinyin(int n) {
    string pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    stack<string> output;

    while (n > 0) {
        output.push(pinyin[n % 10]);
        n /= 10;
    }

    cout << output.top();
    output.pop();

    while (!output.empty()){
        cout << " " << output.top();
        output.pop();
    }
}

int main(int argc, char const *argv[]) {
    char n = '0';
    int sum = 0;
    while (n != '\n') {
        sum += n - '0';
        cin.get(n);
    }
    toPinyin(sum);
    return 0;
}