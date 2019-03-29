import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {

        List<List<Integer>> res = new ArrayList<>();
        if (root == null)
            return res;

        Queue<TreeNode> curLevelNode = new LinkedList<>();
        Queue<TreeNode> nextLevelNode = new LinkedList<>();

        curLevelNode.offer(root);

        boolean isOddLevel = false;
        while (true) {

            List<Integer> curLevelValue = new LinkedList<>();
            while (!curLevelNode.isEmpty()) {

                TreeNode node = curLevelNode.poll();

                if (isOddLevel)
                    curLevelValue.add(0, node.val);
                else
                    curLevelValue.add(node.val);

                if (node.left != null)
                    nextLevelNode.offer(node.left);
                if (node.right != null)
                    nextLevelNode.offer(node.right);
            }
            res.add(curLevelValue);
            isOddLevel = !isOddLevel;

            if (nextLevelNode.isEmpty())
                return res;

            curLevelNode = nextLevelNode;
            nextLevelNode = new LinkedList<>();
        }
    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);

        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(17);

        List<List<Integer>> res = (new Solution()).zigzagLevelOrder(root);

        System.out.println(res.toString());
    }
}