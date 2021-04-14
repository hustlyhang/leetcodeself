/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start

// Definition for a binary tree node.

#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> ino; //? 用来存放中序遍历中节点对应的下标，方便查找

    /*
    ! 构建一颗树需要中序和先序遍历，每次从先序遍历中找到根节点然后在中序遍历中找到这个根节点
    ! 然后再分别在左右两边构建子树
    */
    /*
     * 递归需要的参数为，两中遍历数组，这棵树在中序遍历中的起始点，以及在先序遍历中的根节点
    */
    TreeNode* buildTreeCore(vector<int> pre, vector<int> in, int l, int r, int g) {
        //* 递归出口条件 
        if (l > r) return nullptr;
        //* 构建根节点
        TreeNode* root = new TreeNode(pre[g]);

        /*
            * 然后递归得构建根节点的左右子树
            * 左子树需要知道根节点位置以及在中序遍历中的范围
            * 右子树同理
        */ 
        //* 获得当前根节点在中序遍历中位置
        int m = ino[pre[g]];
        //* 这就知道了左右子树在中序遍历中的起始点了， 接下来找到左右子树的根节点
        int lp = g + 1; //? 左子树的根节点就在先序遍历其父节点的下一个节点
        int rp = g + (m - l) + 1; //? 右子树需要在先序遍历中跳过左子树节点个数
        root->left = buildTreeCore(pre, in, l, m - 1, lp);
        root->right = buildTreeCore(pre, in, m + 1, r, rp);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            ino[inorder[i]] = i;
        }
        return buildTreeCore(preorder, inorder, 0, inorder.size() - 1, 0);
    }
};
// @lc code=end
