/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-09 20:19:07
 * @update on: 2019-03-09 22:19:01
 */
#include <iostream>
#include <cassert>

using namespace std;

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
     * partition 操作, 要求保留原来的相对位置
     */
    ListNode* partition(ListNode* head, int x) {

        if (head == NULL)
            return NULL;

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        // 设置两个指针, l 对应小于标定点的最后一个元素, r 为目前检索过的最后一个元素, s = r + 1 对应正在考察的元素, 仿照数组快速排序的思路进行操作.
        ListNode* l = dummyHead;
        ListNode* r = dummyHead;
        while (r->next != NULL) {

            if (r->next->val >= x) {
                r = r->next;
            }
            else {

                if (l == r) {
                    r = r->next;
                    l = l->next;
                    continue;
                }

                // 拆 r + 1 处
                ListNode* s = r->next;
                r->next = s->next;

                // 拼接
                ListNode* m = l->next;
                l->next = s;
                s->next = m;
                l = s;
            }
        }
        return dummyHead->next;
    }
};

int main(int argc, char const *argv[]) {

    int arr[6] = {1, 4, 3, 2, 5, 2};
    ListNode* list = createLinkedList(arr, 6);
    // int arr[2] = {1, 1};
    // ListNode* list = createLinkedList(arr, 2);
    // int arr[2] = {2, 1};
    // ListNode* list = createLinkedList(arr, 2);

    printLinkedList(list);

    ListNode* res = Solution().partition(list, 3);
    printLinkedList(res);

    return 0;
}