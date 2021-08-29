/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start

// Definition for a binary tree node.
#include <algorithm>
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
    int ret = 0;
    int getDepth(TreeNode* root) {
        //! 递归出口
        if(root == nullptr) return 0;
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        ret = max(ret, l + r);
        return 1 + max(l , r);
    }
    int diameterOfBinaryTree(TreeNode *root) {
        int len = getDepth(root);
        return ret;
    }
};
// @lc code=end
