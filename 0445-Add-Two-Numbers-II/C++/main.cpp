/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-12 19:59:33
 * @update on: 2019-03-12 20:33:18
 */
#include <iostream>
#include <cassert>

using namespace std;

// 445. Add Two Numbers II
// https://leetcode.com/problems/add-two-numbers-ii


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int n1 = getLinkedListLength(l1);
        int n2 = getLinkedListLength(l2);

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        if (n1 < n2) {
            swap(n1, n2);
            swap(p1, p2);
        }

        ListNode* res = addTwoNumbersRecursive(p1, p2, n1, n2);

        // 处理首位大于等于 10 的情况
        if (res->val >= 10) {
            ListNode* head = new ListNode(1);
            res->val %= 10;
            head->next = res;
            return head;
        }

        return res;
    }

    /**
     * 这个递归方法要求传进来的参数中, n1 >= n2, 另外返回的链表中, 首项可能大于等于 10
     */
    ListNode* addTwoNumbersRecursive(ListNode* p1, ListNode* p2, int n1, int n2) {

        /**
         * 公共部分
         */
        if (n1 == n2) {
            // 递归到底
            if (n1 == 1)
                return new ListNode(p1->val + p2->val);

            ListNode* remaining = addTwoNumbersRecursive(p1->next, p2->next, n1-1, n2-1);
            ListNode* head = new ListNode(p1->val + p2->val + remaining->val/10);
            remaining->val %= 10;
            head->next = remaining;
            return head;
        }

        // n1 > n2
        ListNode* remaining = addTwoNumbersRecursive(p1->next, p2, n1-1, n2);
        ListNode* head = new ListNode(p1->val + remaining->val/10);
        remaining->val %= 10;
        head->next = remaining;
        return head;
    }

    int getLinkedListLength(ListNode* list) {
        int length = 0;
        ListNode* p = list;
        while (p != NULL) {
            p = p->next;
            length ++;
        }
        return length;
    }
};

int main(int argc, char const *argv[]) {

    int arr1[1] = {5};  // 5
    int arr2[1] = {5};  // 5
    ListNode* list1 = createLinkedList(arr1, 1);
    ListNode* list2 = createLinkedList(arr2, 1);

    ListNode* res = Solution().addTwoNumbers(list1, list2);

    printLinkedList(res);

    deleteLinkedList(list1);
    deleteLinkedList(list2);
    deleteLinkedList(res);

    return 0;
}
