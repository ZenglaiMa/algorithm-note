
// 题目: 对于任意大于1的自然数n, 若n为奇数, 则将n变为3n+1, 否则变为n的一半.
//       经过若干次这样的变化, 一定会使n变为1. 输入n, 输出变换的次数. n<=10^9.
// 样例输入: 3
// 样例输出: 7

#include <stdio.h>

int main(void) {

    long long n;
    int count = 0;
    scanf("%lld", &n);
    while(n > 1) {
        if(n % 2 == 1) {
            n = 3 * n + 1;
        } else {
            n /= 2;
        }
        count++;
    }
    printf("%d\n", count);
    
    return 0;
}

// note: 因为n的上界10^9只比int类型最大值(2^31-1)小一点, 所以对它进行操作时很容易溢出, 此时我们可以选用范围更大的
//       long long 类型(-2^63~2^63-1), long long 使用 %lld 格式进行输入输出. 
//       但是, 在VC中, long long 类型的输入输出要使用 %I64d 格式, 要注意这一点.
//		 当题目中规定的数值范围很大时, 要及时考虑溢出问题!