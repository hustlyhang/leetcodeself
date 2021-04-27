/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
 */

// @lc code=start

  
  //Definition for a binary tree node.
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    pair<TreeNode*, TreeNode*> Core(TreeNode* root) {
        if (root == nullptr) return pair{nullptr, nullptr};
        if (root->left == nullptr && root->right == nullptr) return pair{root, root};
        auto l = Core(root->left), r = Core(root->right);
        pair<TreeNode*, TreeNode*> ans(root, root);
        if (l.second) l.second->right = root;
        if (r.first) root->right = r.first;
        root->left = nullptr;
        if (l.first) ans.first = l.first;
        ans.second = r.first == nullptr? root:r.second;
        return ans;
    }
    TreeNode* increasingBST(TreeNode* root) {
        return Core(root).first;
    }
};
// @lc code=end

