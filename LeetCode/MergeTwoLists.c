//
// Created by Nicho on 2018/12/5 0005.
//
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *list = (struct ListNode *) malloc(sizeof(struct ListNode)), *list_iter = list;
    // 若node2 的值要大于 node1
    while (l1 && l2) {
        if (l1->val < l2->val) {
            list_iter->next = l1;
            list_iter = list_iter->next;
            l1 = l1->next;
        } else {
            list_iter->next = l2;
            list_iter = list_iter->next;
            l2 = l2->next;
        }
    }

    if (l1) {
        list_iter->next = l1;
    } else {
        list_iter->next = l2;
    }

    list_iter = list;
    list = list->next;
    free(list_iter);

    return list;
}