public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
    ListNode(int x, ListNode next) { val = x; this.next = next; }

    ListNode (int[] arr) {

        if (arr == null || arr.length == 0)
            throw new IllegalArgumentException("Array is Empty");

        val = arr[0];
        ListNode cur = this;
        for (int i = 1; i < arr.length; i ++) {
            cur.next = new ListNode(arr[i]);
            cur = cur.next;
        }
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        for (ListNode cur = this; cur != null; cur = cur.next)
            res.append(cur.val + "->");
        res.append("null");
        return res.toString();
    }
}