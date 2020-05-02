/*
    最长公共子序列(Longest Common Subsequence, LCS): 给定两个字符串(或数字序列)A和B, 求一个字符串, 使得
        这个字符串是A和B的最长公共部分(子序列可以不连续). 如 "sadstory" 和 "adminsorry" 的最长公共子序列为 "adsory", 长度为6.
    思路: 令 dp[i][j] 表示字符串A的 i 号位和字符串B的 j 号位之前(包括i号位和j号位本身的字符)的LCS长度(下标从1开始).
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100;
char A[N], B[N];
int dp[N][N];

int main(int argc, char *argv[]) {

    scanf("%s", A + 1); // 从下标为1开始读入
    scanf("%s", B + 1);
    int lenA = strlen(A + 1), lenB = strlen(B + 1); // 由于从下标为1开始读入, 所以读取长度也从+1开始
    // 边界 dp[i][0] = dp[0][j] = 0 (0<=i<=n, 0<=j<=m)
    for(int i = 0; i <= lenA; i++) {
        dp[i][0] = 0;
    }
    for(int j = 0; j <= lenB; j++) {
        dp[0][j] = 0;
    }
    // 状态转移方程
    for(int i = 1; i <= lenA; i++) {
        for(int j = 1; j <= lenB; j++) {
            if(A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    // dp[lenA][lenB] 即为LCS长度
    printf("%d\n", dp[lenA][lenB]);

    return 0;
}
