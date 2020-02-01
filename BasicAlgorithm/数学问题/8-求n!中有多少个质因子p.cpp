/*
    关于 n! 的一个问题: 求 n! 中有多少个质因子 p. 如 6!=1*2*3*4*5*6 = 1*2*3*2*2*5*2*3, 于是 6! 中有4个质因子2, 有2个质因子3, 有1个质因子5.
*/

#include <cstdio>

// 暴力解法: 计算从 1~n 每个数有多少个质因子p, 然后将结果累加, 这样的时间复杂度为 O(nlogn).
/*
int cal(int n, int p) {
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        int temp = i;
        while(temp % p == 0) {
            ans++;
            temp /= p;
        }
    }
    
    return ans;
}
*/

// 改进: n! 中有 (n/p+n/p^2+n/p^3+...) 个质因子 p, 其中除法均为向下取整(整除). 这样的时间复杂度为 O(logn).
//      该算法带入 cal(n, 5) 可以计算 n! 的末尾有多少个 0.
int cal(int n, int p) {
    int ans = 0;
    while(n > 0) {
        ans += n / p;
        n /= p;
    }

    return ans;
}

int main(void) {

    printf("%d\n", cal(10, 2));
    printf("%d\n", cal(20, 5)); // 求20!末尾有多少个0

    return 0;
}
