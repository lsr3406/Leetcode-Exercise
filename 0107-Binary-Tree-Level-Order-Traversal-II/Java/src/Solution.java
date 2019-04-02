import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {

        List<List<Integer>> res = new LinkedList<>();
        if (root == null)
            return res;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {

            int nodeNum = queue.size();
            List<Integer> subList = new ArrayList<>(nodeNum);
            for (int i = 0; i < nodeNum; i ++) {
            
                TreeNode cur = queue.poll();
                subList.add(cur.val);
                if (cur.left != null)
                    queue.offer(cur.left);
                if (cur.right != null)
                    queue.offer(cur.right);
            }
            res.add(0, subList);
        }
        return res;
    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);

        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(17);

        List<List<Integer>> res = (new Solution()).levelOrder(root);

        System.out.println(res.toString());
    }
}