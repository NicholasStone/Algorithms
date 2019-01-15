//
// Created by Nicho on 2018/11/23 0023.
//
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    int addend_1, addend_2;
    for (addend_1 = 0; addend_1 < nums.size(); ++addend_1) {
        for (addend_2 = addend_1 + 1; addend_2 < nums.size(); ++addend_2) {
            if (nums[addend_1] + nums[addend_2] == target) {
                goto BREAK;
            }
        }
    }
    BREAK:
    return vector<int>{addend_1, addend_2};
}

vector<int> twoSum_better(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        int t = target - nums[i];
        if (m.count(t) && m[t] != i) {
            result.push_back(i);
            result.push_back(m[t]);
            break;
        }
    }
    return result;
}

vector<int> twoSum_best(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        int diff = target - nums[i];
        if (m.count(diff)) {
            result.push_back(m[diff]);
            result.push_back(i);
            break;
        } else {
            m[nums[i]] = i;
        }
    }
    return result;
}


int main(int argc, char const *argv[]) {
    vector<int> nums = {3, 2, 4};
    for (auto i: twoSum_best(nums, 6))
        cout << i << endl;
    return 0;
}