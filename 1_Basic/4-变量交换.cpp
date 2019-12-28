
// 题目: 输入两个整数a和b, 交换两者的值, 然后输出.

#include <stdio.h>

// 1. 三变量法
int main(void) {

    int a, b, t;
    scanf("%d%d", &a, &b);
    t = a;
    a = b;
    b = t;
    printf("%d %d\n", a, b);

    return 0;
}

// 2. 异或法(不推荐 但要知道!)
//int main(void) {
//
//    int a, b;
//    scanf("%d%d", &a, &b);
//    a = a ^ b;
//    b = a ^ b;
//    a = a ^ b;
//    // 上述三条语句可进一步简化为一句: a ^= b ^= a ^= b;
//    printf("%d %d\n", a, b);
//
//    return 0;
//}

// note: 经典的三变量交换必须掌握!