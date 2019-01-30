/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-01-30 11:06:50
 * @update on: 2019-01-30 12:12:02
 */
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:

    /**
     * 找到有序数组中和为指定值的两个索引.
     */
    vector<int> twoSum(vector<int>& numbers, int target) {

        // return twoSum1(numbers, target);
        return twoSum2(numbers, target);
    }

    /**
     * 方案一: 遍历数组的一部分, 在另一部分用二分查找找到互补数
     */
    vector<int> twoSum1(vector<int>& numbers, int target) {

        int halfTarget = target / 2;

        for (int i = 0; i < numbers.size(); i ++) {

            int complemention = binarySearchNonRecursive(numbers, target - numbers[i], i + 1, numbers.size() - 1);

            // 无解情况
            if (numbers[i] > halfTarget && complemention == -1){
                int res[] = {-1, -1};
                return vector<int>(res, end(res));
            }

            if (complemention != -1) {
                int res[] = {i+1, complemention+1};
                return vector<int>(res, end(res));
            }
        }
    }

    /**
     * 方案二: 对撞指针法
     */
    vector<int> twoSum2(vector<int>& numbers, int target) {

        int l = 0, r = numbers.size() - 1;

        while (l <= r) {
            
            int sum = numbers[l] + numbers[r];
            if (sum < target)  // 找一个比现在大的加数
                l ++;
            else if (sum > target)  // 找一个比现在小的加数
                r --;
            else {  // sum == target
                int res[] = {l+1, r+1};
                return vector<int>(res, end(res));
            }
        }
        // 无解
        int res[] = {-1, -1};
        return vector<int>(res, end(res));
    }

private:

    /**
     * 在指定区间 [l, r] 内二分查找, 返回 target 的索引, 找不到返回 -1
     */
    int binarySearchNonRecursive(vector<int> numbers, int target, int l, int r) {
        
        // 验证区间的合法性
        assert(l >= 0 && r < numbers.size());

        while (l <= r) {    // l == r 时也是有效的搜索区间, 所以条件是 l <= r
            // 这样计算 mid 是为了防止整形溢出
            int mid = l + (r - l) / 2;

            if (numbers[mid] < target)
                l = mid + 1;
            else if (numbers[mid] > target)
                r = mid - 1;
            else // numbers[mid] == target
                return mid;
        }
        return -1;
    }

    /**
     * 在指定区间 [l, r] 内二分查找, 返回 target 的索引, 找不到返回 -1
     */
    int binarySearchRecursive(vector<int> numbers, int target, int l, int r) {
        
        // 验证区间的合法性
        assert(l >= 0 && r < numbers.size());

        // 先写出递归到底的情况
        if (l == r)
            return numbers[l] == target ? l : -1;

        // 这样计算 mid 是为了防止整形溢出
        int mid = l + (r - l) / 2;

        if (numbers[mid] < target)
            return binarySearchRecursive(numbers, target, mid+1, r);
        else if (numbers[mid] > target)
            return binarySearchRecursive(numbers, target, l, mid-1);
        else // numbers[mid] == target
            return mid;
    }
};

int main(int argc, char const *argv[]) {

    int arr[] = {2, 7, 11, 15};
    vector<int> numbers(arr, end(arr));
    int target = 9;

    vector<int> res = Solution().twoSum(numbers, target);

    cout << res[0] << " " << res[1] << endl;

    return 0;
}
