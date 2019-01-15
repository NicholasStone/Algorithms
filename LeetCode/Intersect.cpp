//
// Created by Nicho on 2018/11/23 0023.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> intersection;
    if (nums1.empty() || nums2.empty())
        return intersection;

    unordered_map<int, bool> unorderedMap;
    for (auto num : nums1) {
        unorderedMap.insert(make_pair(num, false));
    }

    for (auto num: nums2) {
        auto iter = unorderedMap.find(num);
        if (iter != unorderedMap.end() && !iter->second){
            iter->second = true;
            intersection.push_back(num);
        }
    }

    return intersection;
}