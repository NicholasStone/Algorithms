//
// Created by Nicho on 2018/12/6 0006.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    queue<int> nums;
    nums.push(1);
    nums.push(0);
    vector<vector<int>> result;
    for (int i = 0; i < numRows; ++i) {
        vector<int> layer;
        do {
            int temp = nums.front();
            nums.pop();
            int sum = temp + nums.front();
            layer.push_back(sum);
            nums.push(sum);
        } while (nums.front());
        nums.push(0);
        result.push_back(layer);
    }

    return result;
}

int main(int argc, char const *argv[]) {
    for (auto layer: generate(5)) {
        for (auto n: layer) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}