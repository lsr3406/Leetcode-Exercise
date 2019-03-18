class Solution {

    // 147. Insertion Sort List
    // https://leetcode.com/problems/insertion-sort-list/

    public ListNode insertionSortList(ListNode head) {

        // 虚拟头结点
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;

        boolean goOn = true;
        for (ListNode prev = dummyHead; prev.next != null; ) {
            for (ListNode l = dummyHead; l != prev; l = l.next) {

                if (l.next.val > prev.next.val) {
                    moveListNode(prev, l);
                    goOn = false;
                    break;
                }
            }

            if (!goOn)
                goOn = true;
            else
                prev = prev.next;
        }
        ListNode res = dummyHead.next;
        dummyHead = null;
        return res;
    }

    public void moveListNode(ListNode r, ListNode l) {
        ListNode obj = r.next;
        r.next = obj.next;

        obj.next = l.next;
        l.next = obj;
    }

    public static void main(String[] args) {
        int arr[] = {-1, 5, 3, 4, 0};
        ListNode list = new ListNode(arr);

        System.out.println(list);
        ListNode res = (new Solution()).insertionSortList(list);
        System.out.println(res);
    }
}
