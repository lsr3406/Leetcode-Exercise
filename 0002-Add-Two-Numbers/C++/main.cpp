/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-12 18:40:47
 * @update on: 2019-03-12 19:50:03
 */
#include <iostream>
#include <cassert>

using namespace std;

// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers

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

    /**
     * 方案一: 循环实现
     */
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {

        assert (l1 != NULL && l2 != NULL);

        ListNode* p1 = l1;
        ListNode* p2 = l2;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* p3 = dummyHead;

        int div = 0;
        while (true) {

            int sum = div;
            if (p1 != NULL) {
                sum += p1->val;
                p1 = p1->next;
            }
            if (p2 != NULL) {
                sum += p2->val;
                p2 = p2->next;
            }

            div = sum / 10;

            /**
             * 结束计算的条件, 另外要考虑传进来两个 0 的情况
             */
            if (div == 0 && sum == 0 && p1 == NULL && p2 == NULL) {
                ListNode* head = dummyHead->next;
                delete dummyHead;
                return head ? head : new ListNode(0);
            }

            p3->next = new ListNode(sum % 10);
            p3 = p3->next;
        }
    }

    /**
     * 方案二: 递归实现
     */
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {

        ListNode* p1 = l1;
        ListNode* p2 = l2;

        ListNode* res = addTwoNumbersRecursive(p1, p2, 0);
        return res ? res : new ListNode(0);
    }

    ListNode* addTwoNumbersRecursive(ListNode* p1, ListNode* p2, int div) {

        int sum = div;
        if (p1 != NULL) {
            sum += p1->val;
            p1 = p1->next;
        }
        if (p2 != NULL) {
            sum += p2->val;
            p2 = p2->next;
        }

        div = sum / 10;
        if (sum == 0 && div == 0 && p1 == NULL && p2 == NULL)
            return NULL;

        ListNode* res = new ListNode(sum % 10);
        res->next = addTwoNumbersRecursive(p1, p2, div);   
        return res;
    }
};

int main(int argc, char const *argv[]) {

    int arr1[3] = {2, 4, 3};  // 342
    int arr2[3] = {5, 6, 4};  // 465
    ListNode* list1 = createLinkedList(arr1, 3);
    ListNode* list2 = createLinkedList(arr2, 3);

    ListNode* res = Solution().addTwoNumbers1(list1, list2);

    printLinkedList(res);

    deleteLinkedList(list1);
    deleteLinkedList(list2);
    deleteLinkedList(res);

    return 0;
}
