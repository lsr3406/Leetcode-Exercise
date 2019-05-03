/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-05-03 21:39:08
 * @update on: 2019-05-03 21:39:21
 */
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        if (root.val < Math.min(p.val, q.val))
            return lowestCommonAncestor(root.right, p, q);
        if (root.val > Math.max(p.val, q.val))
            return lowestCommonAncestor(root.left, p, q);
        
        return root;
    }
}
