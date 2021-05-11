/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    void leaf(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        if (root->left == nullptr && root->right == nullptr) {
            nums.push_back(root->val);
            return;
        }
        if (root->left) leaf(root->left, nums);
        if (root->right) leaf(root->right, nums);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1, nums2;
        leaf(root1, nums1);
        leaf(root2, nums2);
        if (nums1.size() != nums2.size()) return false;
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] != nums2[i]) return false;
        }
        return true;
    }
};
// @lc code=end

