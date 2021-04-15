/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start

// Definition for a binary tree node.
#include <unordered_map>
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
    unordered_map<TreeNode *, int> umap; 
    int rob(TreeNode *root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return root->val; // 如果是叶子节点，那么直接返回其值
        //? 递归会存在很多重复子问题，将已经求出来的节点保存，遇到了直接返回
        if (umap[root]) return umap[root]; 
        //? 偷取该节点
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right); 
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right); 
        //? 不偷取该节点
        int val2 = rob(root->left) + rob(root->right); 
        //? 那么该节点得值就等于两种情况得最大值
        umap[root] = max(val1, val2); 
        return umap[root];
    }
};
class Solution {
public:
    unordered_map<TreeNode*, int> f, g;
    //? f 记录偷了当前节点得话，最大值， g 代表不偷当前节点，最大值
    //? 相当于从树得底层网上，保存每个节点偷与不偷的最大值
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        dfs(root->right);
        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);
    }
    int rob(TreeNode *root) {
        dfs(root);
        return max(f[root], g[root]);
    }

};
/***************************进行空间优化**************************************/
//? 可以不用map
struct ss{
    int sel;
    int unsel;
};

class Solution {
    ss dfs(TreeNode* root) {
        if (!root) {
            return {0,0};
        }
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int s = root->val + l.unsel + r.unsel;
        int us = max(l.sel, l.unsel) + max(r.unsel, r.sel);
        return {s, us};
    }
    int rob(TreeNode *root) {
        auto ret = dfs(root);
        return max(ret.sel, ret.unsel);
    }
};
// @lc code=end
