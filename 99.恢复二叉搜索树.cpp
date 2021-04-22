/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

// @lc code=start

//  Definition for a binary tree node.
#include <vector>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };

class Solution {
  public:
    vector<int> nums;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

    pair<int, int> find(vector<int>& nums){
        int len = nums.size();
        int x = 0, y = 0;
        bool flg = false;
        for (int i = 0; i < len - 1; ++i)  {
            if (!flg && nums[i] > nums[i + 1]) {
                x = nums[i];
                y = nums[i + 1];
                flg = true;
                if (i == len - 2) {
                    y = nums[i + 1];
                    break;
                }
                continue;
            }
            if (flg && nums[i] > nums[i + 1]) {
                y = nums[i + 1];
                break;
            }
        }
        return {x, y};
    }
    void recoverTreeCore(TreeNode* root,int count, int x, int y) {
        if (root) {
            if (root->val == x || root->val == y) {
                root->val = root->val == x ? y:x;
                if (--count == 0) return;
            }
            recoverTreeCore(root->left, count, x, y);
            recoverTreeCore(root->right, count, x, y);
        }
    }
    void recoverTree(TreeNode *root) {
        inorder(root);
        auto p = find(nums);
        cout<<p.first<<' '<<p.second<<endl;
        recoverTreeCore(root, 2, p.first, p.second);
    }
};
// @lc code=end
