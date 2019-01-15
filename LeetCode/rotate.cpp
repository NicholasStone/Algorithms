//
// Created by Nicho on 2018/11/23 0023.
//
// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/23/

#include <iostream>
#include <vector>

using namespace std;

void rotate_0(vector<int> &nums, int k) { // 空间复杂度 O(1)
    if (k < 1 || nums.size() < 2 || k % nums.size() == 0) return; // 不需要旋转的情况
    if (k > nums.size()) k = k % (int) nums.size();
    int temp = 0;
    for (int i = 0; i < k; ++i) {
        temp = nums[nums.size() - 1];
        for (int j = (int) nums.size() - 1; j >= 1; --j) {
            nums[j] = nums[j - 1];
        }
        nums[0] = temp;
    }
}

void Reverse(vector<int> &a, int m, int n) {
    int temp;
    while (m < n) {
        temp = a[m];
        a[m++] = a[n];
        a[n--] = temp;
    }
}

void rotate_1(vector<int> &nums, int k) {   // 空间复杂度O(1)
    if (nums.size() < 2 || k < 1 || k % nums.size() == 0)return;
    if (k > nums.size())k = k % (int) nums.size();
    Reverse(nums, (int) nums.size() - k, (int) nums.size() - 1);
    Reverse(nums, 0, (int) nums.size() - k - 1);
    Reverse(nums, 0, (int) nums.size() - 1);
}


void rotate_2(vector<int> &nums, int k) {   // 空间复杂度 O(k)
    if (nums.size() < 2 || k < 1 || k % nums.size() == 0)return;
    if (k > nums.size())k = k % (int) nums.size();
    vector<int> overflow(nums.begin() + nums.size() - k, nums.end());

    for (int i = (int) nums.size() - 1; i > 0; --i) {
        nums[i] = nums[i - k];
    }
    copy(overflow.begin(), overflow.end(), nums.begin());
}

int main(int argc, char const *argv[]) {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
//    rotate_0(nums, 5);
//    rotate_1(nums, 5);
    rotate_2(nums, 5);
    for (int i:nums) {
        cout << i << " ";
    }
    return 0;
}