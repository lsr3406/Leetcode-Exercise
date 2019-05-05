/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-05-05 10:10:12
 * @update on: 2019-05-05 10:10:35
 */
public class Solution {

    public TreeNode sortedArrayToBST(int[] nums) {

        return sortedArrayToBST(nums, 0, nums.length - 1);
    }
    
    public TreeNode sortedArrayToBST(int[] nums, int l, int r) {
        
        if (r < l)
            return null;
        
        int mid = l + (r - l) / 2;
        
        TreeNode root = new TreeNode(nums[mid]);
        
        root.left = sortedArrayToBST(nums, l, mid - 1);
        root.right = sortedArrayToBST(nums, mid + 1, r);
        return root;
    }
}
