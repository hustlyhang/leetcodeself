/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;


/*
    * 滑动窗口
    * 查找|a - b| <= t，所以插入b得时候，是否满足，也就是
    * 看set中是否含有 >= a - t 得数，且小于a + t
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> s;
        for (int i = 0; i < nums.size(); ++i) {
            //? 注意防止整形溢出，计算式中一个数得变为long
            long long tmp1 = (long long)nums[i] - t;
            long long tmp2 = (long long)nums[i] + t;
            auto pos = s.lower_bound(tmp1);
            if (pos != s.end() && *pos <= tmp2) {
                return true;
            }
            s.insert((long long)nums[i]);
            if (s.size() > k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};

/*
    * 桶排序
    * 相当于将所有得数字映射到t+1的范围，然后用一个大桶装小桶
    * 就相当于每隔t+1就建一个桶
    * 注意负数可能不太一样
    * 
*/
typedef long long ll;
class Solution {
public:
    int getID(int num, int t){
        return num < 0 ? (num + 1ll) / (t + 1ll) - 1 : num / (t + 1ll);
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(getID(nums[i], t))) {
                return true;
            }
            else if (m.count(getID(nums[i], t) - 1) && abs((ll)nums[i] - m[getID(nums[i], t) - 1]) <= t) {
                return true;
            }
            else if (m.count(getID(nums[i], t) + 1) && abs((ll)nums[i] - m[getID(nums[i], t) + 1]) <= t) {
                return true;
            }
            m[getID(nums[i], t)] = nums[i];
            if (i >= k) {
                m.erase(getID(nums[i - k], t));
            }
        }
        return false;
    }
};

// @lc code=end

