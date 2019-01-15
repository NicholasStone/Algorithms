//
// Created by Nicholas Stone on 2019-01-14.
//

#include <iostream>
#include <queue>

using namespace std;

void resolve(int n) {
    queue<int> say;
    say.push(1);
    say.push(0);

    for (int i = 0; i < n - 1; ++i) {
        int number = say.front(), count = 0;
        while (say.front()) {
            if (say.front() == number) {
                count++;
            } else {
                say.push(count);
                say.push(number);
                number = say.front();
                count = 0;
            }
            say.pop();
        }
        say.push(count); // 将最后两个数字添加到队尾
        say.push(number);
        say.pop(); // 去掉队首的0
        say.push(0); // 在队尾添加 0
    }

    while (say.front()){
        cout << say.front();
        say.pop();
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    resolve(n);
    return 0;
}