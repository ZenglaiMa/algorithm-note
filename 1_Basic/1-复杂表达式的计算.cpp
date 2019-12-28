
// 计算：1+2√3/(5-0.1)

#include <stdio.h>
#include <math.h>

int main(void) {

    printf("%.6f\n", 1 + 2 * sqrt(3.0) / (5 - 0.1));

    return 0;
}

// note: double sqrt(double x) 函数用来计算 x 的算术平方根, 其定义在 <math.h> 中.