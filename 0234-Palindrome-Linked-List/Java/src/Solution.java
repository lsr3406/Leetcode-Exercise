class Solution {

    // 234. Palindrome Linked List
    // https://leetcode.com/problems/palindrome-linked-list

    // 要求在 O(n) 的时间复杂度与 O(1) 的空间复杂度下完成
    public boolean isPalindrome(ListNode head) {

        if (head == null || head.next == null)
            return true;

        // 找到中间位置
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        if (fast != null)
            slow = slow.next;

        // 反转链表
        ListNode endNode = slow;
        ListNode cur = slow.next;
        while (cur != null) {
            ListNode next = cur.next;
            cur.next = slow;
            slow = cur;
            cur = next;
        }
        endNode.next = null;

        // 比较
        ListNode p1 = head;
        ListNode p2 = slow;
        while (p2 != null) {
            if (p1.val != p2.val)
                return false;
            p1 = p1.next;
            p2 = p2.next;
        }

        return true;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 2, 1};
        ListNode list = new ListNode(arr);

        System.out.println(list);
        boolean res = (new Solution()).isPalindrome(list);
        System.out.println(res);
    }
}