/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-04-23 15:37:56
 * @update on: 2019-04-23 15:38:12
 */
public class Solution {

    public boolean isSameTree(TreeNode p, TreeNode q) {
        
        if (p == null) 
            return q == null;

        if (q == null)
            return false;

        if (p.val != q.val)
            return false;

        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}