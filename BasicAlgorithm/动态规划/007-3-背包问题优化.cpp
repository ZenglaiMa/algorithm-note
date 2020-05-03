/*
    背包问题优化: 将二维 dp[][] 换成一维 dp[], 使空间复杂度达到 O(V).
    状态转移方程(01背包和完全背包相同): dp[v] = max{ dp[v], dp[v-w[i]]+c[i] }
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100;
const int maxv = 1000;
int w[maxn], c[maxn], dp[maxv];

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
        dp[v] = 0;
    }
    // 求 dp[v]
    for(int i = 1; i <= n; i++) {
        /**逆序枚举 v 则是求解01背包问题; 正序枚举 v 则是求解完全背包问题**/
        //for(int v = V; v >= w[i]; v--) { // 求解01背包问题
        for(int v = w[i]; v <= V; v++) { // 求解完全背包问题
            dp[v] = max(dp[v], dp[v - w[i]] + c[i]); // 状态转移方程
            if(dp[v] > maxValue) {
                maxValue = dp[v];
            }
        }
    }
    
    printf("%d\n", maxValue);

    return 0;
}
