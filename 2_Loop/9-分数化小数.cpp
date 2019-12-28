
// 题目: 输入正整数a, b, c, 输出a/b的小数形式, 精确到小数点后c位. a,b<=10^6, c<=100. 
//       输入包含多组数据, 结束标记为 a=b=c=0.
// 样例输入:
//  1 6 4
//  0 0 0
// 样例输出:
//  Case 1: 0.1667

#include <stdio.h>

int main(void) {

    int a, b, c, kase = 0;
    while(scanf("%d%d%d", &a, &b, &c) == 3) {
        if(a == 0 && b == 0 && c == 0)
            break;
        printf("Case %d: %.*f\n", ++kase, c, a * 1.0 / b);
    }

    return 0;
}

// note: printf("%.*f\n", b, a); 输出浮点数a, 保留b位小数.