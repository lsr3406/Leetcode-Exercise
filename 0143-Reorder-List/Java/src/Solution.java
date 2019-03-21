import java.util.Stack;

class Solution {

    // 143. Reorder List
    // https://leetcode.com/problems/reorder-list/

    // 初步计划使用栈来完成链表后半部分元素的处理
    public void reorderList(ListNode head) {

        if (head == null || head.next == null)
            return;

        Stack<ListNode> stack = new Stack<>();

        // 1. 查找中间元素
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // 2. 将链表后半部分元素放入栈中
        for (ListNode p = slow.next; p != null; p = p.next)
            stack.push(p);

        // 3. 从链表头部开始遍历
        ListNode p = head;
        ListNode insertedNode = stack.peek();
        while (!stack.isEmpty()) {
            insertedNode = stack.pop();
            insertedNode.next = p.next;
            p.next = insertedNode;
            p = insertedNode.next;
        }

        // 4. 奇数偶数情况分类讨论
        if (insertedNode.next == insertedNode)
            insertedNode.next = null;
        else 
            p.next = null;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        ListNode list = new ListNode(arr);

        System.out.println(list);
        (new Solution()).reorderList(list);
        System.out.println(list);
    }
}
