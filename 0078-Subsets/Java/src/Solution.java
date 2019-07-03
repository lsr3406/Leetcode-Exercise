/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-07-03 18:59:03
 * @update on: 2019-07-03 19:15:37
 */
import java.util.List;
import java.util.ArrayList;

public class Solution {

    List<List<Integer>> res;

    public List<List<Integer>> subsets(int[] nums) {
        res = new ArrayList<>();
        subsets(nums, 0, new ArrayList<>());
        return res;
    }

    public void subsets(int[] nums, int index, List<Integer> cur) {

        if (index == nums.length) {
            res.add(new ArrayList<>(cur));
            return;
        }

        subsets(nums, index + 1, cur);
        cur.add(nums[index]);
        subsets(nums, index + 1, cur);
        cur.remove(cur.size() - 1);
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        System.out.println((new Solution()).subsets(arr));
    }
}

