/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-05-04 15:31:18
 * @update on: 2019-05-04 15:31:24
 */
public class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        
        if (root == null)
            return null;
        
        if (root.val > key) {
            root.left = deleteNode(root.left, key);
            return root;
        }
        if (root.val < key) {
            root.right = deleteNode(root.right, key);
            return root;
        }
        
        if (root.left == null)
            return root.right;
        if (root.right == null)
            return root.left;
        
        TreeNode predecessor = maximum(root.left);
        predecessor.left = deleteNode(root.left, predecessor.val);
        predecessor.right = root.right;
        return predecessor;   
    }

    public TreeNode maximum(TreeNode root) {
        
        TreeNode cur = root;
        while (cur.right != null)
            cur = cur.right;
        return cur;
    }
}
