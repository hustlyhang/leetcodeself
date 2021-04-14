/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
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
    vector<int> ret;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        ret.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode *root) {
        inorder(root);
        if (ret.size() <= 1) return true;
        int tmp = ret[0];
        for (int i = 1; i < ret.size(); ++i) {
            if (ret[i] > tmp) {
                tmp = ret[i];
            }
            else return false;
        } 
        
        return true;
    }
};
class solution2{
public:
    bool isCore(TreeNode* root, long lower, long upper) {
        //! 递归出口 如果是叶子节点那么为真
        if (root == nullptr) return true;

        //! 如果超过了范围就返回错误
        if (root->val <= lower || root->val >= upper) return false;

        //! 然后对叶子节点进行判断
        return isCore(root->left, lower, root->val) && isCore(root->right, root->val, upper);

    }
    bool isValidBST(TreeNode *root) {
        return isCore(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end
