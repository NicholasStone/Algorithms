//
// Created by Nicho on 2018/11/23 0023.
//
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    bool carry = true; // 进位
    int i = (int) digits.size() - 1;
    do {
        if (digits[i] == 9) {
            carry = true;
            digits[i] = 0;
        } else {
            carry = false;
            digits[i]++;
        }
        i--;
    } while (i >= 0 && carry);
    if(carry){
        digits.insert(digits.begin(), 1);
    }

    return digits;
}