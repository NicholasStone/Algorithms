//
// Created by Nicho on 2018/11/29 0029.
//
#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> temp;
    auto iter_1 = nums1.begin(), iter_2 = nums2.begin();
    while (iter_1 != nums1.end() && iter_2 != nums2.end() && m != 0 && n != 0) {
        if (*iter_1 < *iter_2) {
            temp.push_back(*iter_1);
            iter_1++;
            m--;
        } else {
            temp.push_back(*iter_2);
            iter_2++;
            n--;
        }
    }
    if (m) {
        copy(iter_1, iter_1 + m, back_inserter(temp));
    } else if (n) {
        copy(iter_2, iter_2 + n, back_inserter(temp));
    }

    nums1 = temp;

}

void merge_better(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    while (m > 0 && n > 0) {
        if (nums1[m - 1] > nums2[n - 1]) {
            nums1[m + n - 1] = nums1[m - 1];
            m--;
        } else {
            nums1[m + n - 1] = nums2[n - 1];
            n--;
        }

    }

    if (n > 0) {
        std::copy(nums2.begin(), nums2.begin() + n, nums1.begin());
    }
}

int main(int argc, char const *argv[]) {
    vector<int> num1 = {1, 2, 3, 0, 0, 0};
    vector<int> num2 = {2, 5, 6};
    merge(num1, 3, num2, 3);
    for (auto n : num1) {
        cout << n << endl;
    }
    return 0;
}