/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-04-04 18:43:11
 * @update on: 2019-04-04 19:03:39
 */
import java.util.Queue;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

class Solution {

    public List<Integer> rightSideView(TreeNode root) {
        
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;

        Queue<TreeNode> record = new LinkedList<>();
        record.offer(root);

        int curLevel = 1;
        while (!record.isEmpty()) {

            TreeNode rightNode = record.peek();
            res.add(rightNode.val);

            int curLevelNum = record.size();
            for (int i = 0; i < curLevelNum; i ++) {

                TreeNode cur = record.poll();

                if (cur.right != null)
                    record.offer(cur.right);
                if (cur.left != null)
                    record.offer(cur.left);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);

        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(17);

        List<Integer> res = (new Solution()).rightSideView(root);

        System.out.println(res.toString());
    }
}
