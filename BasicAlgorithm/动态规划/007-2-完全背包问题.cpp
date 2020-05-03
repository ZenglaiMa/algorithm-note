/*
    完全背包问题: 有 n 种物品, 每种物品的单件重量为 w[i], 价值为 c[i]. 现有一个容量为 V 的背包, 问如何选取物品放入背包,
        使得背包内物品的总价值最大. 其中每种物品都有无穷件.
    思路: 跟01背包一样, 令 dp[i][v] 表示前 i 件物品恰好放入容量为 v 的背包中所获得的最大价值. 但
        dp[i][v] = max{ dp[i-1][v], dp[i][v-w[i]]+c[i] }
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100;
const int maxv = 1000;
int w[maxn], c[maxn], dp[maxn][maxv];

int main(void) {

    int n, V, maxValue = 0;
    scanf("%d%d", &n, &V);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    // 边界
    for(int v = 0; v <= V; v++) {
        dp[0][v] = 0;
    }
    // 求 dp[i][v]
    for(int i = 1; i <= n; i++) {
        for(int v = w[i]; v <= V; v++) {
            dp[i][v] = max(dp[i - 1][v], dp[i][v - w[i]] + c[i]); // 状态转移方程
            if(dp[i][v] > maxValue) {
                maxValue = dp[i][v]; // 更新 maxValue
            }
        }
    }

    printf("%d\n", maxValue);

    return 0;
}
