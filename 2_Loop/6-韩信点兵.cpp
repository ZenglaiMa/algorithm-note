
// 题目: 相传韩信才智过人, 从不直接清点自己军队的人数, 只要让士兵先后以三人一排、五人一排、七人一排地变换队形,
//       而他每次只掠一眼队伍的排尾就知道总人数了. 输入包含多组数据, 每组数据包含3个非负整数a, b, c, 表示
//       每种队形排位的人数(a<3 b<5 c<7), 输出总人数的最小值(或报告无解), 已知总人数不小于10不超过100.
// 输入样例: 
//  2 1 6
//  2 1 3
// 输出样例:
// Case 1: 41
// Case 2: No answer

#include <stdio.h>

int main(void) {

    int a, b, c, kase = 0, flag;
    while(scanf("%d%d%d", &a, &b, &c) == 3) {
        flag = 0;
        for(int i = 10; i <= 100; i++) {
            if(i % 3 == a && i % 5 == b && i % 7 == c) {
                flag = 1;
                printf("Case %d: %d\n", ++kase, i);
                break;
            }
        }
        if(!flag) {
            printf("Case %d: No answer\n", ++kase);
        }
    }

    return 0;
}

// note: scanf()的返回值为int类型, 表示成功输入变量的个数, 用以上方法可实现循环输入.