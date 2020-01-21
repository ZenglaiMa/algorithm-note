
// 题目: 近似计算 π/4 = 1 - 1/3 + 1/5 - 1/7 + …, 直到最后一项小于 10^-6.

#include <stdio.h>

int main(void) {

    double sum = 0;
    int flag = 1;
    for(int i = 1; ; i++) {
        double term = 1.0 / (2 * i - 1);
        if(flag) {
            sum += term;
        } else {
            sum -= term;
        }
        flag = !flag;
        if(term < 1e-6)
            break;
    }
    printf("%.6f\n", sum);
    
    return 0;
}

// note: 1. 加减符号依次变化 可以用一个标志位记录;
//       2. 1e-6 表示 10^-6.