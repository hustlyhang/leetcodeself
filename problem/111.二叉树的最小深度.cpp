/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
#include <queue>
using namespace std;
class Solution {
public:
    // queue<TreeNode*> tmp;
    // int ret = 0;
    // int minDepth(TreeNode* root) {
    //     if (root == nullptr) return ret;
    //     ret++;
    //     tmp.push(root);
    //     int c = 1, l = 0;
    //     while (!tmp.empty()) {
    //         if (c) {
    //             TreeNode* p = tmp.front();
    //             tmp.pop();
    //             c--;
    //             if (p->left) {tmp.push(p->left);l++;}
    //             if (p->right) {tmp.push(p->right);l++;}
    //             if (p->left == nullptr && p->right == nullptr) return ret;
    //         }
    //         else {
    //             ret++;
    //             c = l;
    //             l = 0;
    //         }

    //     }
    //     return ret;
    // }
   int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right != NULL) {
            return 1 + minDepth(root->right);
        }
        if (root->left != NULL && root->right == NULL) {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
// @lc code=end

