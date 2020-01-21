
// 题目: 输入n, 计算 S=1! + 2! + 3! + … + n! 的末6位. n<=10^6.
// 样例输入: 10
// 样例输出: 37913

#include <stdio.h>
#include <time.h>

int main(void) {

    const int MOD = 1000000;
    int n, sum = 0;
    scanf("%d", &n);
    /* 优化(仅对本题而言)
    if(n > 25)
        n = 25;
    */
    for(int i = 1; i <= n; i++) {
        int factorial = 1;
        for(int j = 1; j <= i; j++) {
            factorial = factorial * j % MOD;
        }
        sum = (sum + factorial) % MOD;
    }
    printf("%d\n", sum);

    // printf("Time used = %.3f\n", (double)clock() / CLOCKS_PER_SEC);
    
    return 0;
}

// note: 1. 要计算只包含加法、减法和乘法的整数表达式除以正整数 n 的余数, 
//			可以在每步计算之后对 n 取余, 结果不变, 这样还可以解决溢出问题.
//       2. 因为 25! 末尾有6个0, 所以26!, 27!, 28!...末尾必定都是6个0, 
//			所以从n=25开始，后面的所有项都不会影响末6位数字，
//          所以, if(n > 25) n = 25; 这样的话溢出和效率问题就都解决了.
//       3. 在<time.h>中定义的clock()函数, 在程序结束前调用
//			(double)clock() / CLOCKS_PER_SEC 可得到整个程序的运行时间, 以秒为单位.
//          但键盘输入的时间也会被计算在内, 为消除键盘输入时间的影响, 可以使用管道：
//			在命令行进入到当前目录下, 执行 echo 20 | abc, 系统会自动把20输入程序名为abc的程序中.
