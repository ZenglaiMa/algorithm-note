
// 题目: 输入三角形3条边的长度值(均为正整数), 判断是否能组成直角三角形, 能则输出yes, 不能则输出no, 
//       如果根本无法构成三角形, 输出 not a triangle.

#include <stdio.h>

int main(void) {

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a + b > c && a + c > b && b + c > a) {
        if(a * a + b * b == c * c || a * a + b * b == c * c || b * b + c * c == a * a) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    } else {
        printf("not a triangle\n");
    }
    
    return 0;
}