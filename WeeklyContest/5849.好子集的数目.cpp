#include <vector>
using namespace std;

typedef long long LL;
const int MOD = 1e9 + 7;


class Solution {
public:
    int s[31] = {0};    // 记录每个数字出现的次数
    int g[31][31] = {0};// 记录两个点互质就连接一条边
    int st[31] = {0};   // 记录每个点能不能选
    vector<int> path;   // 记录路径
    int C = 1;          // 1的次数

    // 最大公约数
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    int dfs(int u, int sum) {
        if (sum == 0) return 0;
        if (u > 30) {
            if (path.empty()) return 0;
            return sum * (LL)C % MOD;   // 防止爆int，所以转LL
        }

        int ret = dfs(u + 1, sum);
        if (!st[u]) {
            bool flg = true;
            for (auto x : path) {
                if (g[x][u]) {
                    flg = false;
                    break;
                }
            }
            if (flg) {
                path.push_back(u);
                ret = (ret + dfs(u + 1, sum * (LL)s[u] % MOD))%MOD;
                path.pop_back();
            }
        }
        return ret;
    }


    int numberOfGoodSubsets(vector<int>& nums) {
        for (auto x :nums) s[x] ++;
        // 记录有多少个1，每个1都可以任意加入结果中，所以是2^num倍数
        for (int i = 0; i < s[1]; ++i) C = C * 2 % MOD;

        // 去除不能选的点
        for (int i = 2; i * i <= 30; ++i) {
            for (int j = 1; j * i * i <= 30; ++j) {
                st[j * i * i] = 1;
            }
        }


        for (int i = 1; i <= 30; ++i) {
            for (int j = 1; j <= 30; ++j) {
                if (gcd(i, j) > 1)
                    g[i][j] = 1;
            }
        }

        return dfs(2, 1);
    }
};