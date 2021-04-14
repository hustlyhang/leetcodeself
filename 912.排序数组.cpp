/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    /*********************************归并*************************************/
    void merge(vector<int> &nums, int l1, int r1, int l2, int r2) {
        vector<int> tmp(r2 - l1 + 1, 0);
        int i = l1, j = l2, index = 0; 
        while (i <= r1 && j <= r2) {
            if (nums[i] <= nums[j])
                tmp[index++] = nums[i++];
            else
                tmp[index++] = nums[j++];
        }
        while (i <= r1)
            tmp[index++] = nums[i++];
        while (j <= r2)
            tmp[index++] = nums[j++];
        for (int i = l1; i <= r2; ++i)
            nums[i] = tmp[i - l1];
    }
    void mergeSort(int l, int r, vector<int> &nums) {
        if (l < r) {
            int mid = (l + r) / 2;
            mergeSort(l, mid, nums);
            mergeSort(mid + 1, r, nums);
            merge(nums, l, mid, mid + 1, r);
        }
    }
    /*********************************快排*************************************/
    void quickSort(int l, int r, vector<int> &nums) {
        if (l >= r)
            return;
        int tmp = nums[l];
        int tl = l, tr = r;
        while (tl < tr) {
            while (tl < tr && nums[tr] > tmp)
                tr--;
            nums[tl] = nums[tr];
            // 注意是小于等于
            while (tl < tr && nums[tl] <= tmp)
                tl++;
            nums[tr] = nums[tl];
        }
        nums[tl] = tmp;
        quickSort(l, tl - 1, nums);
        quickSort(tl + 1, r, nums);
        // return;
    }
    /*********************************堆排序*************************************/
    // void adjust(vector<int> &nums, int i, int n) {
    //     // i为待调整的节点，n为nums数组元素的个数，从上往下调整
    //     int j = 2 * i + 1; // 左子节点
    //     while (j < n) {
    //         if (j + 1 < n && nums[j + 1] > nums[j])
    //             j++; // 比较左右孩子谁更大
    //         if (nums[j] < nums[i])
    //             break; // 都比父节点小就停止
    //         else {
    //             swap(nums[i], nums[j]);
    //             i = j; // 继续往下调整
    //             j = 2 * i + 1;
    //         }
    //     }
    // }
    // void HeadSort(vector<int> &nums) {
    //     int n = nums.size();
    //     for (int i = n / 2 - 1; i >= 0; --i) {
    //         // i为数组中开始位置，n为个数，不是位置
    //         adjust(nums, i, n);
    //     }
    //     for (int i = n - 1; i >= 1; --i) {
    //         swap(nums[0], nums[i]);
    //         adjust(nums, 0, i);
    //     }
    // }
    void HeadSort(vector<int> &nums) {
        int n = nums.size();
        // 建好堆后（大根堆）
        for (int i = n / 2 - 1; i >= 0; --i) {
            adjust(nums, i, n);
        }
        // 然后将堆顶交换到数组尾部，从堆顶进行调整
        for (int i = n - 1; i >= 1; --i) {
            swap(nums[i], nums[0]);
            adjust(nums, 0, i);
        }
    }
    void adjust(vector<int> &nums, int begin, int len) {
        int j = begin * 2 + 1; // 左子节点
        while (j < len) {
            if (j + 1 < len && nums[j] < nums[j + 1])
                j++; //找到最大的那个孩子
            if (nums[j] <= nums[begin])
                break;
            else {
                swap(nums[j], nums[begin]);
                begin = j;
                j = j * 2 + 1;
            }
        }
    }
    vector<int> sortArray(vector<int> &nums) {
        // quickSort(0, nums.size() - 1, nums);
        // mergeSort(0, nums.size() - 1, nums);
        HeadSort(nums);
        return nums;
    }

    
};
// @lc code=end
