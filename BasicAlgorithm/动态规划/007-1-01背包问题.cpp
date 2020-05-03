/*
    01背包问题: 有n件物品, 每件物品重量为 w[i], 价值为 c[i]. 现有一个容量为 V 的背包, 问如何选取物品放入背包,
        使得背包内物品的总价值最大? 其中每种物品都只有1件.
    思路: 令 dp[i][v] 表示前 i 件物品恰好装入容量为 v 的背包中所能获得的最大价值, dp[i][v]=max{dp[i-1][v],dp[i-1][v-w[i]]+c[i]},
        边界为 dp[0][v]=0, 即前0件物品放入任何容量为v的背包中获得价值都为0.
    时间复杂度: O(nV); 空间复杂度: O(nV), 使用滚动数组优化后空间复杂度可达到 O(V).
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100; // 物品最大件数(n的上限)
const int maxv = 1000; // 背包最大容量(v的上限)
int w[maxn], c[maxn], dp[maxn][maxv];

int main(void) {

    int n, V, maxValue = 0; // maxValue为最大价值
    scanf("%d%d", &n, &V); // 输入物品件数 n 和背包最大容量 V
    for(int i = 1; i <= n; i++) { // 输入每件物品的重量 w[i](i从1开始)
        scanf("%d", &w[i]);
    }
    for(int i = 1; i <= n; i++) { // 输入每件物品的价值 c[i](i从1开始)
        scanf("%d", &c[i]);
    }
    // 边界
    for(int v = 0; v <= V; v++) {
        dp[0][v] = 0;
    }
    // 求 dp[i][v]
    for(int i = 1; i <= n; i++) {
        for(int v = w[i]; v <= V; v++) {
            dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - w[i]] + c[i]); // 状态转移方程
            if(dp[i][v] > maxValue) {
                maxValue = dp[i][v]; // 更新最大价值
            }
        }
    }
    
    printf("%d\n", maxValue);

    return 0;
}
