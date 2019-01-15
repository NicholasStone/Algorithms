//
// Created by Nicho on 2018/11/23 0023.
//
// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/25/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int singleNumber(vector<int> &nums) {
    if (nums.size() == 1)
        return nums[0];
    int count = 0;
    sort(nums.begin(), nums.end());

    if (nums[0] != nums[1]) return nums[0];
    for (int i = 1; i < nums.size() - 1; ++i) {
        if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1])
            return nums[i];
    }
    if (nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1];

    return count;
}

int singleNumber_better(vector<int>& nums) {
    int x = 0;
    for (auto i : nums)
        x ^= i;
    return x;
}