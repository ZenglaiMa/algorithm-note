/*
    最大公约数
        a 和 b 的最大公约数一般表示为 gcd(a, b), 根据欧几里得算法(辗转相除法)可得到: gcd(a, b) = gcd(b, a % b).
        又: 0 和 任意一个整数 a 的最大公约数都是 a 本身, 所以 得到递归式和递归边界:
        ① gcd(a, b) = gcd(b, a % b)
        ② gcd(a, 0) = a
*/

#include <cstdio>

int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(void) {

    int m, n;
    while(scanf("%d%d", &m, &n) != EOF)
        printf("%d\n", gcd(m, n));

    return 0;
}
