/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-04-26 10:16:55
 * @update on: 2019-04-26 10:17:21
 */
import java.util.List;
import java.util.ArrayList;

public class Solution {
    
    private List<List<Integer>> paths = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();
    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        
        if (root == null)
            return paths;
        
        path.add(root.val);
        
        int remainingSum = sum - root.val;
        if (remainingSum == 0 && root.left == null && root.right == null) {
            paths.add(new ArrayList<>(path));
            path.remove(path.size() - 1);
            return paths;
        }
        
        if (root.left != null) {
            pathSum(root.left, remainingSum);
        }
            
        if (root.right != null) {
            pathSum(root.right, remainingSum);
        }
        
        path.remove(path.size() - 1);
        return paths;
    }
}