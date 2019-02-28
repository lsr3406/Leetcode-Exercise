import org.w3c.dom.NodeList;

public class Solution {

    /**
     * 方案一, 不添加虚拟头结点, 删除节点时要分类讨论
     * 不考虑元素游离
     */
    public ListNode removeElements1(ListNode head, int val) {

        // 待删元素在链表头部时, 特殊处理
        while (head != null && head.val == val)
            head = head.next;

        if (head == null)
            return head;

        ListNode prev = head;
        while (prev.next != null) {
            if (prev.next.val == val)
                prev.next = prev.next.next;
            else
                prev = prev.next;
        }
        return head;
    }

    /**
     * 方案二, 设置虚拟头结点挂载在原头结点之前, 统一删除.
     */
    public ListNode removeElements2(ListNode head, int val) {

        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;

        ListNode prev = dummyHead;
        while (prev.next != null) {
            if (prev.next.val == val)
                prev.next = prev.next.next;
            else
                prev = prev.next;
        }

        return dummyHead.next;
    }

    /**
     * 方案三, 递归调用
     */
    public ListNode removeElements3(ListNode head, int val) {

        if (head == null)
            return null;

        ListNode remaining = removeElements3(head.next, val);

        if (head.val == val)
            return remaining;
        else {
            head.next = remaining;
            return head;
        }
    }

    public static void main(String[] args) {

        int[] arr = new int[] {1, 2, 6, 3, 4, 5, 6};

        ListNode list = new ListNode(arr);

        System.out.println((new Solution()).removeElements1(list, 6));
    }
}
