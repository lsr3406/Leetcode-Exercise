public class Solution {

    int count = 0;

    public int pathSum(TreeNode root, int sum) {

        if (root == null)
            return count;

        if (root.val == sum)
            count ++;

        pathSumConstant(root.left, sum - root.val);
        pathSumConstant(root.right, sum - root.val);
        pathSum(root.left, sum);
        pathSum(root.right, sum);

        return count;
    }

    public void pathSumConstant(TreeNode root, int sum) {

        if (root == null)
            return;

        if (root.val == sum)
            count ++;

        pathSumConstant(root.left, sum - root.val);
        pathSumConstant(root.right, sum - root.val);

        return;
    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(10);

        root.left = new TreeNode(5);
        root.left.left = new TreeNode(3);
        root.left.left.left = new TreeNode(3);
        root.left.left.right = new TreeNode(-2);
        root.left.right = new TreeNode(2);
        root.left.right.right = new TreeNode(1);

        root.right = new TreeNode(-3);
        root.right.right = new TreeNode(11);

        int res = (new Solution()).pathSum(root, 8);
        System.out.println(res);
    }
}
