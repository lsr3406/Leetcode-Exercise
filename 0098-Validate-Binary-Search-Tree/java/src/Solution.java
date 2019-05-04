/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-05-04 14:31:26
 * @update on: 2019-05-04 14:34:35
 */
import java.lang.Integer
public class Solution {
    public boolean isValidBST(TreeNode root) {
        
        if (root == null)
            return true;

        return isValidBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    
    public boolean isValidBST(TreeNode root, int lb, int ub) {
        
        if (root.left != null && (root.left.val < lb || root.left.val >= root.val || !isValidBST(root.left, lb, root.val - 1)))
            return false;

        if (root.right != null && (root.right.val > ub || root.right.val <= root.val || !isValidBST(root.right, root.val + 1, ub)))
            return false;
        
        return true;
    }
}
