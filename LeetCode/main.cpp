#include <iostream>
#include <stack>
enum Numbers {
    zero, one, two, three
};

int main() {
    Numbers numbers = one;
    std::stack<int> s;

    std::cout << s.top() << std::endl;
    return 0;
}