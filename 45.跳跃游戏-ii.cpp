/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using  namespace std;

// class Solution {
// public:
//     int ret = INT_MAX;
//     int tmp = 0;
//     void jumpC(vector<int> nums, int i, int tmp) {
//         if (i >= nums.size() - 1) {
//             ret = min(ret, tmp);
//             //cout<<"ret = "<<ret<<endl;
//             return;
//         }
//         for (int j = 1; j <= nums[i]; ++j) {
//             if (tmp > ret) continue;
//             tmp++;
//             jumpC(nums, i + j, tmp);
//             tmp--;
//         } 
//     }
//     int jump(vector<int>& nums) {
//         jumpC(nums, 0, tmp);
//         //cout<<"ret = "<<ret<<endl;
//         return ret;
//     }
// };

//todo 每次维护一个当前位置，以及下一个能到达的最远位置，当走到当前位置时
//todo 就将当前能走的位置更新到下一个能到达的位置，每走一步都更新最远位置
//todo 当i == cur时就说明需要跳了
class Solution {
public:
    int jump(vector<int>& nums) {
        int curDistance = 0;    
        int ans = 0;           
        int nextDistance = 0;   
        //? 为什么是nums.size() - 1 
        //! 因为如果走到最后一个位置时，如果cur == nums.size() - 1时，就会再次更新ans，然而显然已经走到终点，无需再跳了
        for (int i = 0; i < nums.size() - 1; i++) { 
            nextDistance = max(nums[i] + i, nextDistance);
            if (i == curDistance) {                
                curDistance = nextDistance;         
                ans++;
                if (curDistance >= nums.size() - 1) break;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0;    
        int ans = 0;            
        int nextDistance = 0;   
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance);  
            if (i == curDistance) {                         
                if (curDistance != nums.size() - 1) {       
                    ans++;                                 
                    curDistance = nextDistance;            
                    if (nextDistance >= nums.size() - 1) break; 
                } else break;                               
            }
        }
        return ans;
    }
};
// @lc code=end

