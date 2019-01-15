//
// Created by Nicho on 2018/11/23 0023.
//
// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/21/

#include <vector>
#include <iostream>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if(!nums.size())
        return 0;
    int temp = nums[0], duplicated = 0;
    for (int i = 1; i < nums.size(); i++){
        if (temp == nums[i]){
            duplicated ++;
        }else{
            nums[i - duplicated] = nums[i];
            temp = nums[i];
        }
    }
    return (int)nums.size() - duplicated;
}

int main(int argc, char const *argv[]){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int length = removeDuplicates(nums);

    cout << "length:" << length << endl;

    for (int i = 0; i < length; ++i) {
        cout << nums[i] << " ";
    }

    return 0;
}