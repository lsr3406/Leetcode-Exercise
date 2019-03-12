/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-07 18:31:49
 * @update on: 2019-03-07 19:09:43
 */
#include <iostream>
#include <cassert>

using namespace std;

// 92. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii

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
     * 参考 206题的思路, 从 m 开始, 不断调整指针方向. 已知 1 ≤ m ≤ n ≤ length, 索引从 1 开始
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        // 让 l 指向 m - 1 的位置
        ListNode* l = dummyHead;
        for (int i = 1; i < m; i ++)
            l = l->next;

        // 处理区间内的节点指向
        ListNode* prev = l->next;
        ListNode* cur = prev->next;
        for (int i = m; i < n; i ++) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // 处理区间边上的节点指向
        l->next->next = cur;
        l->next = prev;
        return dummyHead->next;
    }
};

int main(int argc, char const *argv[]) {

    int arr[5] = {1, 2, 3, 4, 5};
    ListNode* list = createLinkedList(arr, 5);
    printLinkedList(list);

    list = Solution().reverseBetween(list, 2, 4);
    printLinkedList(list);

    return 0;
}
