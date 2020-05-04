/*
    最长公共子串: 给定两个字符串A和B, 求它们的最长公共子串的长度. 注意子串必须是连续的(这与最长公共子序列是不同的).
    思路: 令dp[i][j]表示以A[i]和B[j]为结尾的最长公共子串的长度, 若A[i]==B[j], 则 dp[i][j]=dp[i-1][j-1]+1; 否则, dp[i][j]=0.
        边界 dp[i][0]=dp[0][j]=0.
*/

#include <cstdio>
#include <cstring>

const int maxn = 1000;
char A[maxn], B[maxn];
int dp[maxn][maxn]; // dp[i][j]表示以A[i]和B[j]为结尾的最长公共子串的长度

int main(void) {

    scanf("%s", A + 1); // 从1号位置开始读入
    scanf("%s", B + 1);
    int lenA = strlen(A + 1), lenB = strlen(B + 1), result = 0; // result 记录最长公共子串长度
    // 边界
    for(int i = 0; i <= lenA; i++) {
        dp[i][0] = 0;
    }
    for(int j = 0; j <= lenB; j++) {
        dp[0][j] = 0;
    }
    // 求dp[i][j], result
    for(int i = 1; i <= lenA; i++) {
        for(int j = 1; j <= lenB; j++) {
            if(A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // 状态转移方程
                if(dp[i][j] > result) {
                    result = dp[i][j];
                }
            } else {
                dp[i][j] = 0; // 状态转移方程
            }
        }
    }

    printf("%d\n", result);

    return 0;
}
