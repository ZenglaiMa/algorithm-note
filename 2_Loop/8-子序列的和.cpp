
// 题目: 输入两个正整数 n<m<10^6, 输出 1/n^2+1/(n+1)^2+...+1/m^2, 保留5位小数. 输入包含多组数据, 
//       结束标记为 n=m=0.
// 输入样例:
//  2 4
//  65536 655360
//  0 0
// 输出样例:
//  Case 1: 0.42361
//  Case 2: 0.00001

#include <stdio.h>

int main(void) {

    int n, m, kase = 0;
    while(scanf("%d%d", &n, &m) == 2) {
        double sum = 0;
        if(n == 0 && m == 0)
            break;
        for(long long i = n; i <= m; i++) { // 注意此处循环变量i的类型为 long long, 目的是防止溢出.
            sum += 1.0 / (i * i);
        }
        printf("Case %d: %.5f\n", ++kase, sum);
    }

    return 0;
}

// note: 该题中输入的值的范围在进行平方运算时可能会出现溢出, 只需换用能表示更大范围的类型即可.