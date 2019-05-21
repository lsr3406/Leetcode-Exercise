/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-05-21 14:46:36
 * @update on: 2019-05-21 14:57:07
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class Solution {
    
    private Map<Integer, Integer> record;
    private List<List<Integer>> res;
    
    public List<List<Integer>> permuteUnique(int[] nums) {
        
        record = new HashMap<>();
        res = new ArrayList<>();

        // 统计
        for (int i: nums) {
            int count = record.getOrDefault(i, 0);
            record.put(i, count + 1);
        }
        
        // 回溯
        permute(new ArrayList<Integer>(), nums.length);
        return res;
    }
    
    private void permute(List<Integer> prev, int remaining) {
        
        if (remaining == 0) {
            res.add(new ArrayList<Integer>(prev));
            return;
        }
        
        for (Integer i: record.keySet()) {
            
            Integer count = record.get(i);
            if (count == 0)
                continue;
            
            prev.add(i);
            record.put(i, count - 1);
            
            permute(prev, remaining - 1);
            
            prev.remove(prev.size() - 1);
            record.put(i, count);
        }
    }

    public static void main(String[] args) {

        int[] input = {1, 1, 2};
        List<List<Integer>> res = (new Solution()).permuteUnique(input);

        System.out.println(res);
    }
}
