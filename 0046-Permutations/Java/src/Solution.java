/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-05-20 09:31:21
 * @update on: 2019-05-20 10:51:17
 */
import java.util.stream.Collectors;
import java.util.Collections;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class Solution {
    
    private List<List<Integer>> res;
    
    public List<List<Integer>> permute(int[] nums) {
        res = new ArrayList<>(A(nums.length, nums.length));
        permute(nums, 0);
        return res;
    }

    private void permute(int[] nums, int from) {

        if (from == nums.length - 1) {
            res.add(Arrays.stream(nums).boxed().collect(Collectors.toList()));
        }

        for (int i = from+1; i < nums.length; i ++) {
            swap(nums, from, i);
            permute(nums, from + 1);
            swap(nums, from, i);
        }
    }

    private int A(int n, int k) {
        
        int num = 1;
        while (k-- > 0) {
            num *= n --;
        }

        return num;
    }

    private List<Integer> copy(List<Integer> oldList) {
        List<Integer> newList = new ArrayList<>(oldList);
        Collections.copy(newList, oldList);
        return newList;
    }

    private void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        List<List<Integer>> res = (new Solution()).permute(arr);
        System.out.println(res);
    }
}