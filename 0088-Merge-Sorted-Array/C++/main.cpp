/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-01-29 19:28:57
 * @update on: 2019-01-29 21:11:50
 */
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:

    /**
     * 将两个有序的 vector 合并至 nums1, 其中 nums1 容量充足
     * @param nums1 第一个 vector, m 个元素, 容量充足
     * @param m     nums1 中需要考虑的元素
     * @param nums2 第二个 vector, n 个元素, 容量为 n
     * @param n     nums2 中需要考虑的元素
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // merge1(nums1, m, nums2, n);    
        // merge2(nums1, m, nums2, n);    
        merge3(nums1, m, nums2, n);    
    }

    /**
     * 方案一: 使用插入排序的思想, 从左向右依次将 nums2 中的元素插入到 nums1 中. 
     * 时间复杂度: O(mn), 
     * 空间复杂度: O(1)
     */
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        assert(nums1.size() >= m + n && nums2.size() >= n);

        int l = 0, r = m - 1;   // 定义 nums1 中未处理元素的区间 [l, r]

        for (int i = 0; i < n; i ++) {

            // 首先在 nums1 的元素中找到比 nums2 中当前元素大的索引
            // l <= r 这个条件一定要有
            while (nums1[l] <= nums2[i] && l <= r)
                l ++;

            // nums1 中的索引在 [l, r] 中的元素向后移一位
            for(int j = r; j >= l; j --)
                nums1[j + 1] = nums1[j];

            // 放入 nums2 中的元素
            nums1[l] = nums2[i];
            l ++;
            r ++;
        }
    }

    /**
     * 方案二: 使用归并排序的思想, 将 nums1 中的有小部分复制一份为 nums3, 再将 nums2 与 nums3 归并到 nums1
     * 时间复杂度: O(m+n)
     * 空间复杂度: O(m)
     */
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        assert(nums1.size() >= m + n && nums2.size() >= n);

        // 拷贝元素
        vector<int> nums3(nums1.begin(), nums1.begin() + m);

        // 归并
        int k1 = 0, k2 = 0;  // 分别代表 nums3 与 nums2 中的当前指针
        for (int i = 0; i < m + n; i ++) {
            if (k1 >= m) {
                nums1[i] = nums2[k2];
                k2 ++;
            }
            else if (k2 >= n) {
                nums1[i] = nums3[k1];
                k1 ++;
            }
            else if (nums3[k1] < nums2[k2]) {
                nums1[i] = nums3[k1];
                k1 ++;
            }
            else { /* nums3[k1] >= nums2[k2] */
                nums1[i] = nums2[k2];
                k2 ++;
            }
        }
    }

    /**
     * 方案三: 使用归并排序的思想, 与方案二不同的是从后向前归并, 无需拷贝 nums1
     * 时间复杂度: O(m+n)
     * 空间复杂度: O(1)
     */
    void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        assert(nums1.size() >= m + n && nums2.size() >= n);

        // 归并
        int k1 = m - 1, k2 = n - 1;  // 分别代表 nums1 与 nums2 中的当前指针
        for (int i = m + n - 1; i >= 0; i --) {
            if (k1 < 0) {
                nums1[i] = nums2[k2];
                k2 --;
            }
            else if (k2 < 0) {
                nums1[i] = nums1[k1];
                k1 --;
            }
            else if (nums1[k1] > nums2[k2]) {
                nums1[i] = nums1[k1];
                k1 --;
            }
            else { /* nums1[k1] <= nums2[k2] */
                nums1[i] = nums2[k2];
                k2 --;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    
    int arr1[] = {1, 2, 3, 0, 0, 0}, m = 3;
    int arr2[] = {2, 5, 6}, n = 3;
    vector<int> nums1(arr1, end(arr1));
    vector<int> nums2(arr2, end(arr2));

    Solution solution = Solution();
    solution.merge(nums1, m, nums2, n);

    for (int i = 0; i < m + n; i ++)
        cout << nums1[i] << " ";
    cout << endl;

    return 0;
}
