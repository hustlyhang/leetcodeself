/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
 */

// @lc code=start

// Definition for a binary tree node.

#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int ret = INT_MAX;
    void Core(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left) {
            TreeNode* tmp = root->left;
            while (tmp->right) {
                tmp = tmp->right;
            }
            ret = min(ret, abs(root->val - tmp->val));
            Core(root->left);
        }
        if (root->right) {
            TreeNode* tmp = root->right;
            while (tmp->left) {
                tmp = tmp->left;
            }
            ret = min(ret, abs(root->val - tmp->val));
            Core(root->right);
        }
    }
    int minDiffInBST(TreeNode *root) {
        Core(root);
        return ret;
    }
};
// @lc code=end
