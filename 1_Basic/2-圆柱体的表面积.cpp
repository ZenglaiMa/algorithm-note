
// 题目: 输入底面半径r和高h, 输出圆柱体的表面积, 保留3位小数.
// 样例输入: 3.5 9
// 样例输出: Area = 274.889

#include <stdio.h>
#include <math.h>

int main(void) {

    const double pi = acos(-1.0);
    double r, h, s1, s2;
    scanf("%lf%lf", &r, &h);
    s1 = pi * r * r * 2; // 底面两个圆的面积
    s2 = 2 * pi * r * h; // 侧面积
    printf("%.3f\n", s1 + s2);

    return 0;
}

// note: 1. 计算π值: const double pi = acos(-1.0); 
//       2. acos(double x)用来计算 x 的反余弦弧度值, 其定义在<math.h>中;
//       3. double类型在输入时用 %lf.
