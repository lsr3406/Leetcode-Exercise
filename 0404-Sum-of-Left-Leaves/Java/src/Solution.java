/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-04-25 14:08:00
 * @update on: 2019-04-25 14:08:10
 */
public class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        
        if (root == null)
            return 0;
        
        return sumOfLeftLeaves(root.left, true) + sumOfLeftLeaves(root.right, false);
    }
    
    public int sumOfLeftLeaves(TreeNode root, boolean isLeftNode) {
        
        if (root == null)
            return 0;
        
        if (isLeftNode && root.left == null && root.right == null)
            return root.val;
        
        return sumOfLeftLeaves(root.left, true) + sumOfLeftLeaves(root.right, false);
    }
}