public class Solution {

    // 24. Swap Nodes in Pairs
    // https://leetcode.com/problems/swap-nodes-in-pairs

    public ListNode swapPairs(ListNode head) {

        // 1. 拼接 dummyHead
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;

        // 2. 常规思路
        ListNode prev = dummyHead;
        while (prev.next != null && prev.next.next != null) {

            ListNode cur = prev.next;
            ListNode next = cur.next;

            prev.next = next;
            cur.next = next.next;
            next.next = cur;

            prev = cur;
        }

        head = dummyHead.next;
        dummyHead = null;
        return head;
    }
    public static void main(String[] args) {

        int[] arr = {1, 2, 3, 4, 5};
        ListNode list = new ListNode(arr);

        System.out.println(list);
        ListNode res = (new Solution()).swapPairs(list);
        System.out.println(res);
    }
}
