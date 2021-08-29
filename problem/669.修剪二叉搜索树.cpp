/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
 */

// @lc code=start

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (root == nullptr) return nullptr;

        //? 处理当前结点
        if (root->val < low) {
            //? 因为是二叉搜索树,节点.left < 节点 < 节点.right
            //? 节点数字比low小,就把左节点全部裁掉.
            root = root->right;
            //? 裁掉之后,继续看右节点的剪裁情况.剪裁后重新赋值给root.
            root = trimBST(root, low, high);
        }
        else if (root->val > high){
            //? 如果数字比high大,就把右节点全部裁掉.
            root = root->left;
            //? 裁掉之后,继续看左节点的剪裁情况
            root = trimBST(root, low, high);
        }
        else { 
            //? 如果数字在区间内,就去裁剪左右子节点.
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        return root;
    }
};
// @lc code=end
