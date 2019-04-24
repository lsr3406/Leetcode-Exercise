/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-04-24 16:30:21
 * @update on: 2019-04-24 16:30:34
 */
public class Solution {
    public boolean isBalanced(TreeNode root) {
        
        return getDepth(root) == -1 ? false : true;
    }
    
    public int getDepth(TreeNode node) {
    
        if (node == null)
            return 0;
        
        int leftDepth = getDepth(node.left);
        if (leftDepth == -1)
            return -1;
        
        int rightDepth = getDepth(node.right);
        if (rightDepth == -1)
            return -1;

        if (Math.abs(leftDepth - rightDepth) > 1)
            return -1;
        
        return Math.max(leftDepth, rightDepth) + 1;
    }
}