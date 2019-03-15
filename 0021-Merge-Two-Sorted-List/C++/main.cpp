/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-15 08:43:49
 * @update on: 2019-03-15 09:09:38
 */
#include <iostream>
#include <cassert>

using namespace std;

// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(int arr[], int n) {

    if (n == 0)
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < n; i ++) {
        ListNode* node = new ListNode(arr[i]);
        cur->next = node;
        cur = cur->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {

    ListNode* cur = head;
    while (cur != NULL) {
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << "NULL" << endl;
}

void deleteLinkedList(ListNode* head) {

    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* delNode = cur;
        cur = cur->next;
        delete delNode;
    }
    return;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode* p1 = l1;
        ListNode* p2 = l2;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* p = dummyHead;
        while (true) {

            if (p1 == NULL && p2 == NULL)
                break;

            if (p1 == NULL || p2 != NULL && p1->val >= p2->val) {
                p->next = p2;
                p2 = p2->next;
            }
            else if (p2 == NULL || p1 != NULL && p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            }

            p = p->next;     
        }

        ListNode* head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main(int argc, char const *argv[]) {

    int arr1[3] = {1, 2, 4};
    int arr2[3] = {1, 3, 4};
    ListNode* list1 = createLinkedList(arr1, 3);
    ListNode* list2 = createLinkedList(arr2, 3);

    ListNode* res = Solution().mergeTwoLists(list1, list2);
    printLinkedList(res);

    // deleteLinkedList(list1);
    // deleteLinkedList(list2);
    deleteLinkedList(res);

    return 0;
}
