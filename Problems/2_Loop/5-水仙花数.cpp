
// 题目: 输出100~999中的所有水仙花数. 若3位数abc满足abc=a^3+b^3+c^3, 则称其为水仙花数.
//		 100内的水仙花数有 153、370、371、407.

#include <stdio.h>

int main(void) {

    int a, b, c;
    for(int i = 100; i <= 999; i++) {
        a = i / 100;
        b = i /10 % 10;
        c = i % 10;
        if(a * a * a + b * b * b + c * c * c == i)
            printf("%d\n", i);
    }

    return 0;
}