public class Solution {
    public int minDepth(TreeNode root) {
        if (root == null)
            return 0;

        if (root.left == null || root.right == null)
            return 1 + (root.right == null ? minDepth(root.left) : minDepth(root.right));

        return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.left.left = new TreeNode(15);
        root.left.right = new TreeNode(7);

        int res = (new Solution()).minDepth(root);
        System.out.println(res);
    }
}
