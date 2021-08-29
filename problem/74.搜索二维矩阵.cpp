/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i = 0, j = cols - 1;
        while (i < rows && j >= 0) {
            if (matrix[i][j] > target) j--;
            else if (matrix[i][j] < target) i++;
            else return true;
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 先找到行号，然后在行里面找
        int j = 0;
        int l = 0, r = matrix.size() - 1;
        while (l <= r) {
            int m = l + ((r - l) >>1);
            //cout<<"m = "<<m<<endl;
            if (matrix[m][0] > target) {
                r = m - 1;
            }
            else if (matrix[m][0] < target) l = m + 1;
            else return true;
        }
        if (r == -1) {
            return false;
        } 
        j = r;
        // cout<<"j = "<<j<<endl;
        l = 0;
        r = matrix[j].size() - 1;
        while (l <= r) {
            //cout<<"l = "<<l<<endl;
            //cout<<"r = "<<r<<endl;

            int mid = (l + r)/2;
            //cout<<"mid = "<<mid<<endl;
            if (matrix[j][mid] > target) {
                r = mid - 1;
            }
            else if (matrix[j][mid] < target) l = mid + 1;
            else return true;
        }
        if (l == matrix[j].size() || r == -1) return false;
        //if (matrix[j][r] == target) return true;
        return false;
    }
};
// @lc code=end

