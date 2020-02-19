/*
    最小公倍数
        a 和 b 的最小公倍数一般记为 lcm(a, b).
        最小公倍数是在最大公约数的基础上求解的. 先求出 a 和 b 的最大公约数 d, 然后用 ab / d 即可得最小公倍数,
        但 ab 有可能溢出, 所以一般写为 a / d * b. 因此有:
        lcm(a, b) = a / gcd(a, b) * b;
*/

#include <cstdio>

int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b) {
    int d = gcd(a, b);

    return a / d * b;
}

int main(void) {

    int m, n;
    while(scanf("%d%d", &m, &n) != EOF) {
        printf("%d 和 %d 的最小公倍数为 %d\n", m, n, lcm(m, n));
    }

    return 0;
}
