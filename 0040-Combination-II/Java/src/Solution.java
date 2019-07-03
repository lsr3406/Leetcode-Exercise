/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-07-03 16:13:12
 * @update on: 2019-07-03 16:39:41
 */
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class Solution {

    List<List<Integer>> res;

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        
        res = new ArrayList<>();
        Arrays.sort(candidates);

        combination(candidates, target, new ArrayList<Integer>(), 0, new boolean[candidates.length]);
        return res;
    }

    public void combination(int[] candidates, int target, List<Integer> cur, int startIndex, boolean[] used) {

        if (target == 0) {
            res.add(new ArrayList<>(cur));
            return;
        }

        for (int i = startIndex; i < candidates.length; i ++) {

            if (candidates[i] > target)
                break;

            if (used[i] == true)
                continue;

            if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false)
                continue;

            cur.add(candidates[i]);
            used[i] = true;
            combination(candidates, target - candidates[i], cur, i, used);
            cur.remove(cur.size() - 1);
            used[i] = false;
        }
    }

    public static void main(String[] args) {
        
        int[] candidates = {2, 3, 5};
        int target = 8;

        List<List<Integer>> res = (new Solution()).combinationSum2(candidates, target);
        System.out.println(res);
    }
}