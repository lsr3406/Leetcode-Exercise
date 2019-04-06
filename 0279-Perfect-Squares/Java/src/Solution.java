/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-04-06 18:04:14
 * @update on: 2019-04-06 20:36:59
 */
import java.lang.Math;
import java.util.Queue;
import java.util.Map;
import java.util.LinkedList;
import java.util.HashMap;

class Solution {

    // private Map<Integer, Integer> record;

    // // 暴力搜索递归函数
    // private int getNumSquares(int n) {

    //     if (record.containsKey(n))
    //         return record.get(n);

    //     int res = n;
    //     for (int i = (int) Math.sqrt(n); i > 0; i --) {
    //         res = Math.min(getNumSquares(n - i * i) + 1, res);
    //     }
    //     record.put(n, res);
    //     return res;
    // }

    // // 暴力搜索
    // public int numSquares(int n) {

    //     if (n == 0)
    //         return 0;

    //     record = new HashMap<>();

    //     return getNumSquares(n);
    // }

    // 广度优先遍历法
    public int numSquares(int n) {

        if (n == 0)
            return 0;

        Queue<Integer> queue = new LinkedList<>();
        int res = 0;

        queue.offer(n);
        while (!queue.isEmpty()) {

            int size = queue.size();
            res ++;

            for (int i = 0; i < size; i ++) {
                int cur = queue.poll();
                int num = (int) Math.sqrt(cur);

                for (int j = num; j > 0; j --) {
                    int next = cur - j * j;

                    if (next == 0)
                        return res;
                    queue.offer(next);
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) {

        Solution solution = new Solution();
        System.out.println(solution.numSquares(9));
        System.out.println(solution.numSquares(12));
        System.out.println(solution.numSquares(13));
    }
}