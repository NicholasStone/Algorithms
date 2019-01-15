//
// Created by Nicho on 2018/11/23 0023.
//

#include <vector>

void moveZeroes(vector<int> &nums) {
    if(nums.size() <= 1)
        return;

    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (!nums[i]) {
            count++;
        } else {
            nums[i - count] = nums[i];
        }
    }

    for (int i = nums.size() - count; i < nums.size(); i++) {
        nums[i] = 0;
    }
}