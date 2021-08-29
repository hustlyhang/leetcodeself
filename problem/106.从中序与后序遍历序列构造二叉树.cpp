/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start

// Definition for a binary tree node.
#include <unordered_map>
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
    //?需要中序遍历
    unordered_map<int, int> m;
    TreeNode *buildTreeCore(vector<int> &inorder, vector<int> &postorder, int end, int left, int right) {
        if (left > right) return nullptr;
		
		//? 查找后序遍历节点在中序遍历中的节点位置；
		int k = m[postorder[end]];
		TreeNode* root = new TreeNode(inorder[k]);

		root->right = buildTreeCore(inorder, postorder, end - 1, k + 1, right);
		root->left = buildTreeCore(inorder, postorder, end - (right - k) - 1, left, k - 1); 
		return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        //? 为了方便在后序遍历中找到该节点在中序遍历中的位置，利用map来辅助查找
        for (int i = 0; i < inorder.size(); ++i) {
			m[inorder[i]] = i;
        }
		return buildTreeCore(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
    }
};
// @lc code=end
