/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-07 22:02:04
 * @update on: 2019-03-07 22:48:13
 */
#include <iostream>
#include <cassert>

using namespace std;

// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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

void deleteLinkedList(ListNode* list) {
    ListNode* cur = list;
    while (cur != NULL) {
        ListNode* prev = cur;
        cur = cur->next;
        delete prev;
    }
}

class Solution {
public:
    /**
     * 本题暂不考虑释放内存
     */
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* prev = dummyHead;
        ListNode* cur = head;
        ListNode* next = head->next;

        bool deleteMode = false;
        while (next != NULL) {

            if (cur->val != next->val) {
                if (deleteMode == false) {
                    prev = cur;
                }
                else {
                    prev->next = next;
                    deleteMode = false;
                }
            }
            else {
                deleteMode = true;
            }

            cur = next;
            next = next->next;
        }

        if (deleteMode)
            prev->next = NULL;

        return dummyHead->next;
    }
};

int main(int argc, char const *argv[]) {

    // int arr[7] = {1, 2, 3, 3, 4, 4, 5};
    // ListNode* list = createLinkedList(arr, 7);
    int arr[7] = {1, 1, 1, 2, 3, 3, 3};
    ListNode* list = createLinkedList(arr, 7);
    printLinkedList(list);

    list = Solution().deleteDuplicates(list);
    printLinkedList(list);

    deleteLinkedList(list);

    return 0;
}

