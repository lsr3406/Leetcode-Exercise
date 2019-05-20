/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-05-20 08:51:24
 * @update on: 2019-05-20 09:28:35
 */
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class Solution {

    List<List<Integer>> res;

    public List<List<Integer>> combine(int n, int k) {

        if (k == 0)
            return new ArrayList<>();
        if (k > n)
            throw new IllegalArgumentException("k must be larger than or equal to n");

        res = new ArrayList<>(C(n, k));
        combine(1, n, k, new ArrayList<Integer>(k));
        return res;
    }

    public void combine(int from, int to, int k, List<Integer> prev) {
        
        if (k == 0) {
            res.add(prev);
            return;
        }

        // add all
        if (k == to - from + 1) {
            for (int i = from; i <= to; i ++)
                prev.add(i);
            res.add(prev);
            return;
        }

        // ignore from
        combine(from+1, to, k, copy(prev));

        // add from
        prev.add(from);
        combine(from+1, to, k-1, copy(prev));
    }

    public int C(int n, int k) {
        
        int num = 1;
        int den = 1;
        while (k > 0) {
            num *= n --;
            den *= k --;
        }

        return num / den;
    }

    public List<Integer> copy(List<Integer> oldList) {
        List<Integer> newList = new ArrayList<>(oldList);
        Collections.copy(newList, oldList);
        return newList;
    }

    public static void main(String[] args) {
        
        List<List<Integer>> res = (new Solution()).combine(0, -1);
        System.out.println(res);
    }
}
