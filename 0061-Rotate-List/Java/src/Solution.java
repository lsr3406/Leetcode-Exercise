class Solution {

    // 61. Rotate List
    // https://leetcode.com/problems/rotate-list/

    public ListNode rotateRight(ListNode head, int k) {

        if (head == null)
            return head;

        // 1. 计算链表长度, 并记录链表尾部
        int length = 1;
        ListNode endNode = head;
        for (; endNode.next != null; endNode = endNode.next)
            length ++;

        // 2. 计算步数
        int step = length - k % length - 1;
        if (step == -1)
            return head;

        // 3. 找到需要断开的位置
        ListNode prev = head;
        for (; step > 0; step --)
            prev = prev.next;

        // 4. 拼接
        endNode.next = head;
        ListNode newHead = prev.next;
        prev.next = null;
        return newHead;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        ListNode list = new ListNode(arr);

        System.out.println(list);
        ListNode res = (new Solution()).rotateRight(list, 2);
        System.out.println(res);
    }
}
