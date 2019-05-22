/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-05-22 08:49:55
 * @update on: 2019-05-22 09:01:23
 */
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class Solution {

    List<List<Integer>> res;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        
        res = new ArrayList<>();
        Arrays.sort(candidates);

        combination(candidates, target, new ArrayList<Integer>(), 0);
        return res;
    }

    public void combination(int[] candidates, int target, List<Integer> cur, int startIndex) {

        if (target == 0) {
            res.add(new ArrayList<>(cur));
            return;
        }

        for (int i = startIndex; i < candidates.length; i ++) {

            if (candidates[i] > target)
                break;

            cur.add(candidates[i]);
            combination(candidates, target - candidates[i], cur, i);
            cur.remove(cur.size() - 1);
        }
    }

    public static void main(String[] args) {
        
        int[] candidates = {2, 3, 5};
        int target = 8;

        List<List<Integer>> res = (new Solution()).combinationSum(candidates, target);
        System.out.println(res);
    }
}
