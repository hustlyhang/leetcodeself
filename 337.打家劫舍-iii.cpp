/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
class Solution {
public:
    unordered_map<TreeNode* , int> umap; // ��¼������Ľ��
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;
        if (umap[root]) return umap[root]; // ���umap���Ѿ��м�¼��ֱ�ӷ���
        // ͵���ڵ�
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right); // ����root->left
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right); // ����root->right
        // ��͵���ڵ�
        int val2 = rob(root->left) + rob(root->right); // ����root�����Һ���
        umap[root] = max(val1, val2); // umap��¼һ�½��
        return max(val1, val2);
    }
};
// @lc code=end

