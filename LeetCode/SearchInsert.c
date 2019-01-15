//
// Created by Nicho on 2018/12/6 0006.
//

#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target) {
    if (nums[0] >= target) return 0;
    int l = 0, r = numsSize - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    mid = (l + r) / 2;
    return nums[mid] == target ? mid : mid + 1;
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 3};
    printf("%d", searchInsert(arr, 2, 2));
    return 0;
}