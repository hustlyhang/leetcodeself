/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <vector>
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
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int curDistance = 0;    // ��ǰ���ǵ���Զ�����±�
//         int ans = 0;            // ��¼�ߵ������ 
//         int nextDistance = 0;   // ��һ�����ǵ���Զ�����±� 
//         for (int i = 0; i < nums.size() - 1; i++) { // ע��������С��nums.size() - 1�����ǹؼ�����
//             nextDistance = max(nums[i] + i, nextDistance); // ������һ�����ǵ���Զ�����±�
//             if (i == curDistance) {                 // ������ǰ���ǵ���Զ�����±�
//                 curDistance = nextDistance;         // ���µ�ǰ���ǵ���Զ�����±�
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0;    // ��ǰ������Զ�����±�
        int ans = 0;            // ��¼�ߵ������
        int nextDistance = 0;   // ��һ��������Զ�����±�
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance);  // ������һ��������Զ�����±�
            if (i == curDistance) {                         // ������ǰ������Զ�����±�
                if (curDistance != nums.size() - 1) {       // �����ǰ������Զ�����±겻���յ�
                    ans++;                                  // ��Ҫ����һ��
                    curDistance = nextDistance;             // ���µ�ǰ������Զ�����±꣨�൱�ڼ����ˣ�
                    if (nextDistance >= nums.size() - 1) break; // ��һ���ĸ��Ƿ�Χ�Ѿ����Դﵽ�յ㣬����ѭ��
                } else break;                               // ��ǰ������Զ�����±��Ǽ����յ㣬������ans++�����ˣ�ֱ�ӽ���
            }
        }
        return ans;
    }
};
// @lc code=end

