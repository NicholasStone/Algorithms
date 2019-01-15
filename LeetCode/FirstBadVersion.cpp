//
// Created by Nicho on 2018/11/29 0029.
//

#include <iostream>

bool isBadVersion(int n) {
    return n <= 5;
}

// 二分查找
// 成果条件，i 为 true and i+1 为 false

int firstBadVersion(int n) {
    if (isBadVersion(n)) {
        //考虑到边界问题，必须先排除n
        return n;
    }
    int left = 1, right = n - 1, mid = (left + right) / 2;
    while (!(isBadVersion(mid) ^ isBadVersion(mid + 1))) {
        if (left > right){
            break;
        }
        if (isBadVersion(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    return mid;
}

int main(int argc, char const *argv[]) {
    std::cout << firstBadVersion(6);
    return 0;
}