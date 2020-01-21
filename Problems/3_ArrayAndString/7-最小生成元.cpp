
// 题目: 如果 x 加上 x 的各位数字之和得到 y, 就说 x 是 y 的一个生成元. 输入n(1<=n<=100000),
//       输出 n 的最小生成元, 无解输出 0. 例如 n=216, 121, 2005 时的解分别为 198, 0, 1979.

/*
    思路: 1. 设所求生成元为 m, 易知 m < n, 枚举所有 m<n, 看看有没有一个数 m 是 n 的生成元.
          2. 思路1效率并不高, 因为每计算一个生成元都要枚举好多, 可以进行如下优化:
             我们可以一次性枚举 100000以内的所有正整数 m, 
             标记"m 加上 m 的各位数字之和得到的数有一个生成元是 m". 然后我们根据输入的数字查表即可.
    注意: 当循环多次输入数 n 求其最小生成元时, 思路2效率更高, 因为它就进行了一次枚举, 以后就查表了,
          但不是循环输入(只输入一次)时, 思路1效率更高, 因为它一旦找到最小生成元循环就结束了.
*/

#include <stdio.h>
#include <string.h>

int ans[100005];

int main(void) {

    // 思路1
    /*int n, flag = 0;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int m = i, sum = i;
        while (m > 0) {
            sum += m % 10;
            m /= 10;
        }
        if(sum == n) {
            printf("%d\n", i);
            flag = 1;
            break;
        }
    }
    if(!flag)
        printf("%d\n", 0);*/

    // 思路2
    memset(ans, 0, sizeof(ans));
    for(int m = 1; m < 100000; m++) {
        int x = m, sum = m;
        while(x > 0) { // 该循环作用是将 m 和 m 的各位数字相加
            sum += x % 10;
            x /= 10;
        }
        if(ans[sum] == 0 || m < ans[sum]) // 此时 m 即是 sum 的一个生成元, 第二个判断条件保证最小生成元
            ans[sum] = m;
    }

    int n;
    scanf("%d", &n);
    printf("%d\n", ans[n]);

    return 0;
}
