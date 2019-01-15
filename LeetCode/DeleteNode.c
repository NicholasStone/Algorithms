//
// Created by Nicho on 2018/11/29 0029.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode *node) {
    struct ListNode *iter = node;
    while (iter->next != NULL) {
        iter->val = iter->next->val;
        iter = iter->next;
    }
    free(iter);
}

int main(int argc, char const *argv[]) {

    return 0;
}