/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start

//Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    void flattenCore(TreeNode* root)
    {
        if (root == nullptr) return;
        // 先用一个临时节点保存根节点右孩子
        TreeNode* right = root->right;
        // 然后递归处理左子树
        flattenCore(root->left);
        // 处理完后将其连接到root->right
        root->right = root->left;
        root->left = nullptr;
        // 然后要找到当前根节点右子树叶节点，将之前的右子树连接上来
        
        while (root->right) {
            root = root->right;
        }
        TreeNode* tmp = root;
        flattenCore(tmp);
        root->right = tmp;
    }
    void flatten(TreeNode *root)
    {
        flattenCore(root);
    }
};
// @lc code=end
