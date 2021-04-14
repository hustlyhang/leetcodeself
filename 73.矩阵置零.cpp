/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

// class Solution {
// public:
//     vector<int> rows;
//     vector<int> cols;
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         if (n == 0 || m == 0) return;
//         rows.assign(n, 0);
//         cols.assign(m, 0);
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 if (matrix[i][j] == 0) {
//                     rows[i] = 1;
//                     cols[j] = 1;
//                     //cout<<"i = "<< i<<endl;
//                     //cout<<"j = "<< j<<endl;

//                 }
//             }
//         }
//         for (int i = 0; i < n; ++i) {
//             if (rows[i]) {
//                 for (int j = 0; j < m; ++j) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         for (int j = 0; j < m; ++j) {
//             if (cols[j]) {
//                 for (int i = 0; i < n; ++i) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         return;
//     }
// };
class Solution {
    public： void setZeroes(int[][] mat) {
        int m = mat.length, n = mat[0].length;

        // 1. 扫描「首行」和「首列」记录「首行」和「首列」是否该被置零
        boolean r0 = false, c0 = false;
        for (int i = 0; i < m; i++) {
            if (mat[i][0] == 0) {
                r0 = true;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (mat[0][j] == 0) {
                c0 = true;
                break;
            }
        }

        // 2.1 扫描「非首行首列」的位置，如果发现零，将需要置零的信息存储到该行的「最左方」和「最上方」的格子内
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = mat[0][j] = 0;
                }
            }
        }
        // 2.2 根据刚刚记录在「最左方」和「最上方」格子内的置零信息，进行「非首行首列」置零
        for (int j = 1; j < n; j++) {
            if (mat[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    mat[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (mat[i][0] == 0) {
                Arrays.fill(mat[i], 0);
            }
        }
        
        // 3. 根据最开始记录的「首行」和「首列」信息，进行「首行首列」置零
        if (r0) for (int i = 0; i < m; i++) mat[i][0] = 0;
        if (c0) Arrays.fill(mat[0], 0);
    }
}

// @lc code=end

