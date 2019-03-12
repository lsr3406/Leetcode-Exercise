/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-12 18:18:47
 * @update on: 2019-03-12 18:38:05
 */
#include <iostream>
#include <cassert>

using namespace std;

// 328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list

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

    if (head == NULL)
        cout << "NULL" << endl;

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

    /**
     * 按照索引的奇偶性重排, 要求就地进行, 空间复杂度 O(1), 时间复杂度 O(n)
     */
    ListNode* oddEvenList(ListNode* head) {
        
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return head;

        // ListNode* dummyHead = new ListNode(-1);
        // dummyHead->next = head;

        ListNode* l = head;
        ListNode* r = head->next;
        bool isOdd = true;

        while (r->next != NULL) {

            if (!isOdd) {
                isOdd = !isOdd;
                r = r->next;
                continue;
            }

            // 拆 r + 1
            ListNode* oddNode = r->next;
            r->next = oddNode->next;

            // 放回.
            ListNode* s = l->next;
            l->next = oddNode;
            oddNode->next = s;
            l = oddNode;

            isOdd = !isOdd;
        }

        // delete dummyHead;
        return head;
    }
};

int main(int argc, char const *argv[]) {

    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode* list = createLinkedList(arr, 9);

    ListNode* res = Solution().oddEvenList(list);
    printLinkedList(res);

    deleteLinkedList(list);

    return 0;
}