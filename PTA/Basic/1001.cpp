//
// Created by Nicholas Stone on 2019-01-10.
//
// 1001 害死人不偿命的(3n+1)猜想

#include <iostream>

int main(int argc, char const *argv[]) {
    int n, log = 0;
    std::cin >> n;
    while (n > 1) {
        log++;
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }
    }
    std::cout << log;
    return 0;
}
