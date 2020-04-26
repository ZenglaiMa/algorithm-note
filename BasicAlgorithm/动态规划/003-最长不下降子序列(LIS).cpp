/*
    最长不下降子序列(Longest Increasing Sequence, LIS): 在一个数字序列中, 找到一个最长的子序列(可以不连续), 
        使得这个子序列是不下降(非递减)的.
    时间复杂度: O(n^2).
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100;
int A[MAXN], dp[MAXN]; // A[i]存放序列, dp[i]表示以A[i]结尾的最长不下降子序列的长度

int main(void) {

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) { // 输入序列
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < n; i++) {
        dp[i] = 1; // 边界初始条件: 每个元素自成一个子序列
        for(int j = 0; j < i; j++) {
            if(A[j] <= A[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1; // 状态转移方程
            }
        }
    }

    int max = dp[0];
    for(int i = 1; i < n; i++) {
        if(dp[i] > max) {
            max = dp[i];
        }
    }
    printf("最长不下降子序列长度 = %d\n", max);

    return 0;
}
