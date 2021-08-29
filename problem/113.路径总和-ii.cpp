/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    // 判断是否为叶节点， 如果是，就判断是否相等。 如果为空节点就直接返回
    void pathSumCore(TreeNode* root, int targetSum) {
        if (!root) return;
        if (!root->left && !root->right && targetSum == root->val) {
            tmp.push_back(root->val);
            ret.push_back(tmp);
            tmp.pop_back();
            return;
        }
        else {
            if (root->left) {
                tmp.push_back(root->val);
                pathSumCore(root->left, targetSum - root->val);
                tmp.pop_back();
            }
            if (root->right) {
                tmp.push_back(root->val);
                pathSumCore(root->right, targetSum - root->val);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        pathSumCore(root, targetSum);
        return ret;
    }
};
// @lc code=end

