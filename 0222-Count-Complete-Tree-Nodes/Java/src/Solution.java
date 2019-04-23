/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-04-23 15:50:32
 * @update on: 2019-04-23 15:50:44
 */
public class Solution {
    public int countNodes(TreeNode root) {
        if (root == null)
            return 0;
        return countNodes(root.left) + countNodes(root.right) + 1;
    }
}