/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

// @lc code=start

//Definition for a binary tree node.
#include <vector>
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class BSTIterator
{
private:
    int i = 0;
public:
    vector<int> ret;
    void inordered(TreeNode* root) {
        if (root == nullptr) return;
        inordered(root->left);
        ret.push_back(root->val);
        inordered(root->right);
    }
    BSTIterator(TreeNode *root)
    {
        i = 0;
        inordered(root);
    }

    int next()
    {
        return ret[i++];
    }

    bool hasNext()
    {
        if (i < ret.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
