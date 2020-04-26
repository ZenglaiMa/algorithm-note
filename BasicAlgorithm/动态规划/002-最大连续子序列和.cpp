/*
    最大连续子序列和: 给定一个数字序列 A1,A2,…,An, 求 i, j(1<=i<=j<=n), 使得 Ai+……+Aj 最大, 求这个最大的和.
	时间复杂度: O(n)
    样例: -2 11 -4 13 -5 -2
    显然 11+(-4)+13=20 为和最大的选取情况, 因此最大和为20.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
int A[MAXN], dp[MAXN]; // A[i]存放序列, dp[i]存放以A[i]为结尾的连续序列的最大和

int main(void) {

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) { // 给定数字序列
        scanf("%d", &A[i]);
    }

    dp[0] = A[0]; // 边界
    for(int i = 1; i < n; i++) {
        dp[i] = max(A[i], dp[i - 1] + A[i]); // 状态转移方程
    }

    int max = dp[0];
    for(int i = 1; i < n; i++) {
        if(dp[i] > max) {
            max = dp[i];
        }
    }
    printf("%d\n", max);

    return 0;
}
