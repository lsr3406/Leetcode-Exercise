/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-27 18:22:21
 * @update on: 2019-02-27 21:23:50
 */
#include <iostream>
#include <cassert>

using namespace std;

// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/

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
     * 方案一, 不添加虚拟头结点, 删除节点时要分类讨论
     * 不考虑元素游离
     */
    ListNode* removeElements1(ListNode* head, int val) {

        while (head && head->val == val) {
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
        }

        if (!head)
            return NULL;

        ListNode* prev = head;
        while (prev) {
        
            ListNode* cur = prev->next;
            if (cur && cur->val == val) {
                prev->next = cur->next;
                delete cur;
            }
            else {
                prev = cur;
            }
        }
        return head;
    }

    /**
     * 方案二: 设置虚拟头结点挂载在原头结点之前, 统一删除.
     */
    ListNode* removeElements2(ListNode* head, int val) {

        if (!head)
            return NULL;

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* prev = dummyHead;
        while (prev) {

            ListNode* cur = prev->next;
            if (cur && cur->val == val) {
                prev->next = cur->next;
                delete cur;
            }
            else {
                prev = cur;
            }
        }
        // 不能写 return head;
        return dummyHead->next;
    }

    /**
     * 方案三, 递归调用
     */
    ListNode* removeElements3(ListNode* head, int val) {

        if (!head)
            return NULL;

        ListNode* remaining = removeElements3(head->next, val);
        if (head->val == val) {
            delete head;
            return remaining;
        }
        else {
            head->next = remaining;
            return head;
        }
    }
};

int main(int argc, char const *argv[]) {

    int arr[7] = {1, 2, 6, 3, 4, 5, 6};
    int n = (int) (end(arr) - begin(arr));

    ListNode* list = createLinkedList(arr, n);
    printLinkedList(list);

    (new Solution())->removeElements3(list, 6);
    printLinkedList(list);

    deleteLinkedList(list);
    
    return 0;
}
