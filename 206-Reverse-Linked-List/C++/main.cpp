/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-07 17:55:54
 * @update on: 2019-03-07 18:29:14
 */
#include <iostream>
#include <cassert>

using namespace std;

// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(int* arr, int n) {
    
    if (n == 0)
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < n; i ++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printLinkedList(ListNode* list) {

    for (ListNode* cur = list; cur != NULL; cur = cur->next)
        cout << cur->val << "->";
    cout << "NULL" << endl;
}

class Solution {
public:

    /**
     * 从前往后, 依次调整指针方向
     * @param  head [description]
     * @return      [description]
     */
    ListNode* reverseList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* cur = head;
        ListNode* prev = NULL;

        while (cur != NULL) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

int main(int argc, char const *argv[]) {

    int arr[5] = {1, 2, 3, 4, 5};
    ListNode* list = createLinkedList(arr, 5);
    printLinkedList(list);

    list = Solution().reverseList(list);
    printLinkedList(list);

    return 0;
}

