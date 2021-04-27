/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int zx = 0, zy = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                zx = 1;
                break;
            }
            
        }
        for (int j = 0; j < cols; ++j) {
            if (matrix[0][j] == 0) {
                zy = 1;
                break;
            }
            
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        //? 注意起始位置
        for (int i = 1; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < cols; ++j) matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < cols; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < rows; ++i) matrix[i][j] = 0;
            }
        }
        //cout<<"zx = "<<zx<<endl;
        //cout<<"zy = "<<zy<<endl;
        if (zx == 1) {
            for (int i = 0; i < rows; ++i) matrix[i][0] = 0;
        }
        if (zy == 1) {
            
            for (int j = 0; j < cols; ++j) matrix[0][j] = 0;
        }
    }
};

// @lc code=end

