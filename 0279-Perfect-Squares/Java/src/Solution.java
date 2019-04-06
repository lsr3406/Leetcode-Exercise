/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-04-06 18:04:14
 * @update on: 2019-04-06 18:48:11
 */
import java.lang.Math;
import java.util.Map;
import java.util.HashMap;

class Solution {

    private Map<Integer, Integer> record;

    private int getNumSquares(int n) {

        if (record.containsKey(n))
            return record.get(n);

        int sq = 1;
        int res = n;
        for (int i = 1; sq <= n; i ++, sq = i*i) {
            res = Math.min(getNumSquares(n - sq) + 1, res);
        }
        record.put(n, res);
        return res;
    }

    public int numSquares(int n) {

        if (n == 0)
            return 0;

        record = new HashMap<>();

        return getNumSquares(n);
    }

    public static void main(String[] args) {

        Solution solution = new Solution();
        System.out.println(solution.numSquares(9));
        System.out.println(solution.numSquares(12));
        System.out.println(solution.numSquares(13));
    }
}