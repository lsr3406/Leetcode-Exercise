/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-07-06 16:14:51
 * @update on: 2019-07-06 16:42:22
 */
import java.util.Collections;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;

public class Solution {

    private List<List<Integer>> res;

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        res = new ArrayList<>();
        subsetsWithDup(nums, 0, new ArrayList<Integer>());
        return res;
    }

    private void subsetsWithDup(int[] nums, int index, List<Integer> cur) {

        if (index == nums.length) {
            Collections.sort(cur);
            if (!res.contains(cur))
                res.add(new ArrayList<>(cur));
            return;
        }

        int prev = nums[index];
        subsetsWithDup(nums, index + 1, cur);
        cur.add(prev);
        
        subsetsWithDup(nums, index + 1, cur);
        cur.remove(cur.indexOf(prev));
    }

    public static void main(String[] args) {

        int[] arr = {4, 1, 0};
        System.out.println((new Solution()).subsetsWithDup(arr));
    }
}

