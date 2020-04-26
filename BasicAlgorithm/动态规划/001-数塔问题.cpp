/*
    数塔问题: 将一些数字排成数塔的形状, 其中第一层有一个数字, 第二层有两个数字……第n层有n个数字. 现在要从第一层走到底n层,
        每次只能走向下一层连接的两个数字中的一个, 问: 最后将路径上所有数字相加后得到的和最大是多少?
                            5
                          8   3
                        12  7   16
                      4   10  11   6
                    9   5    3   9   4
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
int f[MAXN][MAXN]; // 存储数塔
int dp[MAXN][MAXN]; // dp[i][j] 表示从第 i 层第 j 个数字出发的到达最底层的所有路径中能得到的最大和

int main(void) {

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) { // 构建数塔
        for(int j = 0; j <= i; j++) {
            scanf("%d", &f[i][j]);
        }
    }

    for(int i = 0; i < n; i++) { // 边界: 数塔最后一层的 dp 值等于元素值本身
        dp[n - 1][i] = f[n - 1][i];
    }
    for(int i = n - 2; i >= 0; i--) { // 从第 n-1 层不断向上计算得出 dp[i][j]
        for(int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j]; // 状态转移方程
        }
    }
    
    printf("%d\n", dp[0][0]); // dp[0][0]即为答案

    return 0;
}
