//
// Created by Nicholas Stone on 2019-01-11.
//

#include <iostream>
#include <vector>

using namespace std;

bool judge(string str) {
    size_t first_not_of_A = str.find_first_not_of('A'), last_not_of_A = str.find_last_not_of('A');
    size_t a = first_not_of_A, b = 0, c = str.length() - last_not_of_A - 1;

    // 第一个不是 A 的字母不是 P 或 最后一个不是 A 的字母不是 T 返回错误
    if (str[first_not_of_A] != 'P' || str[last_not_of_A] != 'T') return false;

    // 若剩余字母为空或含有其他字母则为错误
    if (last_not_of_A - first_not_of_A <= 1) return false;
    cout << *(str.end() - last_not_of_A - 1) << endl;
    for (auto iter = str.begin() + first_not_of_A + 1; iter != str.end() - last_not_of_A; ++iter) {
        if (*iter != 'A')return false;
        else b++;
    }

    return a * b == c;
}


void resolve() {
    string str;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        // 删去头尾的 A,判断剩余字符串是否符合条件
        if (judge(str)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main(int argc, char const *argv[]) {
    resolve();
    return 0;
}