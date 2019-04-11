import java.util.*;
import java.util.Comparator;

public class Solution {

    public List<Integer> topKFrequent(int[] nums, int k) {

        // 统计所有的元素个数
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i ++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }

        // 遍历 map, 放入优先队列中
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>(k, new Comparator<>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return o2.getValue().compareTo(o1.getValue());
            }
        });

        for (Map.Entry<Integer, Integer> e: map.entrySet()) {
            pq.add(e);
        }

        // 返回
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < k; i ++) {
            list.add(pq.poll().getKey());
        }
        return list;
    }

    public static void main(String[] args) {

        int[] nums = {1,1,1,2,2,3};
        int k = 2;

        List<Integer> res = (new Solution()).topKFrequent(nums, k);
        System.out.println(res);
    }
}