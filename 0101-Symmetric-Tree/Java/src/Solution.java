/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-04-23 15:44:00
 * @update on: 2019-04-23 15:45:16
 */
public class Solution {

    public boolean isSymmetric(TreeNode root) {
        return root == null || isSymmetric(root.left, root.right);
    }
    
    public boolean isSymmetric(TreeNode t1, TreeNode t2) {
        
        if (t1 == null)
            return t2 == null;
        if (t2 == null)
            return false;
        
        if (t1.val != t2.val)
            return false;
        
        return isSymmetric(t1.left, t2.right) && isSymmetric(t1.right, t2.left);
    }
}