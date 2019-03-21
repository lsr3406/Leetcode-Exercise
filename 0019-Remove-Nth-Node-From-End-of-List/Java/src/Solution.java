class Solution {

    // 19. Remove Nth Node From End of List
    // https://leetcode.com/problems/remove-nth-node-from-end-of-list/

    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;

        // 找到倒数第 n 的元素
        int length = 0;
        for (ListNode p = head; p != null; p = p.next)
            length ++;

        // 常规思路删除
        ListNode prev = dummyHead;
        for (int step = length - n; step > 0; step --)
            prev = prev.next;
        
        ListNode delNode = prev.next;
        prev.next = delNode.next;
        delNode = null;

        ListNode res = dummyHead.next;
        dummyHead = null;
        return res;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        ListNode list = new ListNode(arr);

        System.out.println(list);
        ListNode res = (new Solution()).removeNthFromEnd(list, 2);
        System.out.println(res);
    }
}