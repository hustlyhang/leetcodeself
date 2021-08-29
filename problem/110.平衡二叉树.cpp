/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start

//  Definition for a binary tree node.
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <unordered_set>
class Solution
{
public:
    std::unordered_set<int> re;
    int getDepth(TreeNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int leftDepth = getDepth(node->left);
        if (leftDepth == -1)
            return -1; // 说明左子树已经不是二叉平衡树
        int rightDepth = getDepth(node->right);
        if (rightDepth == -1)
            return -1; // 说明右子树已经不是二叉平衡树
        return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode *root)
    {
        return getDepth(root) == -1 ? false : true;
    }
};

class practice {
public:
    int getDepth(TreeNode* root) {
        //! 递归退出条件
        if (root == nullptr) return 0;
        int ld = getDepth(root->left);
        //! 如果左边子树已经不平衡了那么直接返回-1
        if (ld == -1) return -1;
        int rd = getDepth(root->right);
        if (rd == -1) return -1;
        return abs(ld - rd) > 1 ? -1 : 1 + max(ld, rd);
    }
    bool isBalance(TreeNode* root) {
        return getDepth(root) == -1 ? false : true;
    }
};

// @lc code=end
