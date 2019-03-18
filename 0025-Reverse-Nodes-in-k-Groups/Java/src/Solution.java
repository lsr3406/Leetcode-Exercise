/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-18 20:07:04
 * @update on: 2019-03-18 20:50:41
 */
public class Solution {

    // 25. Reverse Nodes in k-Group
    // https://leetcode.com/problems/reverse-nodes-in-k-group

    /**
     * 将原问题看做一个二重反转的问题
     */
    public ListNode reverseKGroup(ListNode head, int k) {
        
        // 求链表长度, 计算分组数量
        int length = 0;
        for (ListNode cur = head; cur != null; cur = cur.next)
            length ++;
        int groups = length / k;

        if (groups == 0)
            return head;

        ListNode dummyHead = new ListNode(-1);
        ListNode prev = dummyHead;
        ListNode cur = head;
        for (int i = 0; i < groups; i ++) {
            prev.next = reverseInterval(cur, k);
            prev = cur;
            cur = cur.next;
        }

        ListNode res = dummyHead.next;
        dummyHead.next = null;
        return res;
    }

    /**
     * 反转以 head 为首的链表的长度为 k 的区间, 返回反转后的链表的头部
     */
    public ListNode reverseInterval(ListNode head, int k) {

        // 虚拟头结点
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode prev = dummyHead;
        
        // 找到下一个区间的头
        ListNode cur = head;
        for (int i = 0; i < k; i++)
            cur = cur.next;
        ListNode end = cur;

        // 常规思路
        cur = head;
        ListNode next = cur.next;
        for (int i = 0; i < k; i++) {
            next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }

        dummyHead = null;
        head.next = end;
        return prev;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        ListNode list = new ListNode(arr);

        System.out.println(list);
        ListNode res = (new Solution()).reverseKGroup(list, 2);
        System.out.println(res);
    }
}
