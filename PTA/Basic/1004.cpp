//
// Created by Nicholas Stone on 2019-01-12.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct student {
    string name;
    string id;
    int score{};
} student;

void resolve() {
    int n, max_index = 0, max_score = 0, min_score = 0, min_index = 0;
    vector<student> students;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        student s;
        cin >> s.name >> s.id >> s.score;
        if (s.score > max_score) {
            max_score = s.score;
            max_index = i;
        } else if (s.score < min_score) {
            min_score = s.score;
            min_index = i;
        }
        students.push_back(s);
    }

    cout << students[max_index].name << " " << students[max_index].id << endl
         << students[min_index].name << " " << students[min_index].id;
}

int main(int argc, char const *argv[]) {
    resolve();
    return 0;
}