/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start

// Definition for a binary tree node.
#include <cmath>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int ret = INT_MAX;
    void Core(TreeNode *root) {
        if (root == nullptr)
            return;
        if (root->left) {
            TreeNode *tmp = root->left;
            while (tmp->right) {
                tmp = tmp->right;
            }
            ret = min(ret, abs(root->val - tmp->val));
            Core(root->left);
        }
        if (root->right) {
            TreeNode *tmp = root->right;
            while (tmp->left) {
                tmp = tmp->left;
            }
            ret = min(ret, abs(root->val - tmp->val));
            Core(root->right);
        }
    }
    int getMinimumDifference(TreeNode *root) {
        Core(root);
        return ret;
    }
};
// @lc code=end
