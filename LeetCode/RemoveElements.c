//
// Created by Nicho on 2018/12/5 0005.
//
#include <stdio.h>

int removeElement(int *nums, int numsSize, int val) {
    int count = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == val) {
            count++;
        } else {
            nums[i - count] = nums[i];
        }
    }
    return numsSize - count;
}

int main(int argc, char const *argv[]) {
    int a[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int len = removeElement(a, 2);

    return 0;
}