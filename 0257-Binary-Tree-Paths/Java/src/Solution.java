/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-04-26 09:35:35
 * @update on: 2019-04-26 09:35:49
 */
public class Solution {
    
    private List<String> paths;
    
    public List<String> binaryTreePaths(TreeNode root) {

        paths = new ArrayList<>();
        
        binaryTreePath(root, "");
        return paths;
    }
    
    private void binaryTreePath(TreeNode node, String prevPath) {
        
        if (node == null)
            return;
        
        String curPath = prevPath.equals("") ? String.valueOf(node.val) : prevPath + "->" + node.val;

        if (isLeafNode(node)) {
            paths.add(curPath);
            return;
        }
        
        if (node.left != null)
            binaryTreePath(node.left, curPath);
        
        if (node.right != null)
            binaryTreePath(node.right, curPath);
    }
    
    private boolean isLeafNode(TreeNode node) {
        if (node.left == null && node.right == null)
            return true;
        return false;
    }
}
