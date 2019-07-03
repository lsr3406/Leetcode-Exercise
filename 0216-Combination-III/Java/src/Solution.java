/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-07-03 17:49:12
 * @update on: 2019-07-03 18:48:39
 */
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class Solution {

    public List<List<Integer>> res;
    public static final int MAX_NUMBER = 9;

    public List<List<Integer>> combinationSum3(int k, int n) {

        res = new ArrayList<>();

        if (k == 1) {
            if (n <= Solution.MAX_NUMBER)
                res.add(Arrays.asList(n));
            return res;
        }

        combination(k, n, new ArrayList<Integer>());
        return res;
    }

    public void combination(int k, int n, List<Integer> cur) {

        int l = cur.size();
        int start = l == 0 ? 1 : (cur.get(l - 1) + 1);

        if (k == 2) {

            for (int i = start; n - i > i; i ++) {
                if (n - i > Solution.MAX_NUMBER)
                    continue;

                List<Integer> newRes = new ArrayList<>(cur);
                newRes.addAll(Arrays.asList(i, n - i));
                res.add(newRes);
            }
            return;
        }

        for (int i = start; i <= Solution.MAX_NUMBER; i ++) {
            cur.add(i);
            combination(k - 1, n - i, cur);
            cur.remove(cur.size() - 1);
        }
    }

    public static void main(String[] args) {
        
        System.out.println((new Solution()).combinationSum3(3, 7));
        System.out.println((new Solution()).combinationSum3(3, 9));
        System.out.println((new Solution()).combinationSum3(2, 18));
        System.out.println((new Solution()).combinationSum3(3, 15));
    }
}
