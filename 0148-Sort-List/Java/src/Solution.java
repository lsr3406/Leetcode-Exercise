public class Solution {

    // 148. Sort List
    // https://leetcode.com/problems/sort-list/

    public ListNode sortList(ListNode head) {
        return sortListUB(head);
    }

    // Merge Sort I
    public ListNode sortListUB(ListNode head) {

        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;

        sortListUB(dummyHead, null);

        head = dummyHead.next;
        dummyHead = null;
        return head;
    }

    // (l, r)
    public void sortListUB(ListNode l, ListNode r) {

        // System.out.print("sort: ");
        // printListInterval(l, r);

        if (l == r || l.next == r || l.next.next == r)
            return;

        // 找到链表的中间位置
        ListNode mid = getMid(l, r);

        // 先排右边再排左边, 如果颠倒会影响 mid 指针
        sortListUB(mid, r);
        sortListUB(l, mid.next);

        mid = getMid(l, r);
        merge(l, mid, r);
    }

    // (l, r)
    public void merge(ListNode l, ListNode mid, ListNode r) {

        // System.out.print("merge: ");
        // printListInterval(l, r);

        if (mid.val < mid.next.val)
            return;

        while (mid.next != r && l != mid) {

            if (l.next.val <= mid.next.val)
                l = l.next;
            else {
                ListNode obj = mid.next;
                mid.next = obj.next;
                obj.next = l.next;
                l.next = obj;
                l = l.next;
            }
        }
    }

    public ListNode getMid(ListNode l, ListNode r) {
        ListNode slow = l;
        ListNode fast = l;
        while (fast != r && fast.next != r) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public void printListInterval(ListNode l, ListNode r) {
        if (l == r) {
            System.out.println("[]");
            return;
        }
        System.out.print("[");
        while (true) {
            System.out.print(l.next.val);
            l = l.next;
            if (l.next == r)
                break;
            System.out.print(", ");
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        int arr[] = {8, 6, 2, 3, 1, 5, 7, 4};
        ListNode list = new ListNode(arr);

        System.out.println(list);
        ListNode res = (new Solution()).sortList(list);
        System.out.println(res);
    }
}