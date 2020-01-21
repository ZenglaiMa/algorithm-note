
// 题目: 输入正整数n(n<360), 输出n度的正弦值和余弦值.

#include <stdio.h>
#include <math.h>

int main(void) {

    int n;
    const double pi = acos(-1.0);
    scanf("%d", &n);
    printf("sin(n) = %.3f, cos(n) = %.3f\n", sin(n * 1.0 / 180 * pi), cos(n * 1.0 / 180 * pi));
    
    return 0;
}

// note: 1. double sin(double x)、double cos(double x) 计算 x 弧度的正余弦值, 其定义在<math.h>中.
//       2. 角度制和弧度制转换关系: 弧度 = 角度 / 180 * π.
