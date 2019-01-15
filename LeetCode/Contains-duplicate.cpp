//
// Created by Nicho on 2018/11/23 0023.
//
// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/24/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool containsDuplicate(vector<int> &nums) {
    if (nums.size() <= 1)
        return false;

    bool flag = false;
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i-1] == nums[i]){
            flag = true;
            break;
        }
    }

    return flag;
}

int main(int argc, char const *argv[]){
    vector<int> nums = {3 ,1};
    cout << containsDuplicate(nums);
    return 0;
}