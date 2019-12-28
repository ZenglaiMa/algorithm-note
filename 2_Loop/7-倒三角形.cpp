
// 题目: 输入正整数n, 输出一个n层的倒三角形, 如 n=5 时输出如下:
//  #########
//   #######
//    #####
//     ###
//      #

#include <stdio.h>

int main(void) {

    int n;
    scanf("%d", &n);
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < n - i; j++)
            printf(" ");
        for(int j = 0; j < 2 * i - 1; j++)
            printf("#");
        printf("\n");
    }

    return 0;
}