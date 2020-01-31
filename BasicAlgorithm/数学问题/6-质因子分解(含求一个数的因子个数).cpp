/*
    质因子分解: 指将一个正整数 n 写成一个或多个质数的乘积的形式, 如6=2*3, 8=2*2*2, 180=2*2*3*3*5...
*/

#include <cstdio>
#include <cmath>

// 表示: 由于每个质因子都可以不止出现一次, 因此可以定义一个结构体, 用来存放质因子及其个数.
// 例如对 180=2*2*3*3*5来说, 有: fac[0].x=2, fac[0].count=2; fac[1].x=3, fac[1].count=2; fac[2].x=5, fac[2].count=1.
typedef struct {
    int x;
    int count;
} Fac;

Fac fac[10]; // 考虑到 2*3*5*7*11*13*17*19*23*29 就已经超过了int范围, 因此对于一个int类型的数来说, Fac数组开10个就够了
int num = 0; // Fac的个数

const int goal = 1000000;
int prime[goal], index = 0;
bool p[goal] = { false };

void findPrime() { // 获取质数表(使用埃氏筛选法)
    for(int i = 2; i <= goal; i++) {
        if(p[i] == false) {
            prime[index++] = i;
            for(int j = i + i; j <= goal; j += i) {
                p[j] = true;
            }
        }
    }
}

/*
    对于一个整数 n 来说, 如果它存在[2, n]范围内的质因子, 要么这些质因子全部小于等于sqrt(n), 要么只存在一个大于sqrt(n)的质因子,
    而其余质因子全部小于等于sqrt(n).
    思路: 1.枚举1~sqrt(n)范围内的所有质因子p, 判断p是否为n的因子, 如果是, 那么给fac数组中增加质因子p, 并初始化其个数为0, 
            然后只要p还是n的因子, 就让n不断除以p, 每次操作令p的个数加一, 直到p不再是n的因子为止.
          2. 如果上面步骤结束后n仍然大于1, 说明n有且仅有一个大于sqrt(n)的质因子(可能是n本身), 这是需要把这个质因子加入Fac数组, 并令其个数为1.
*/
void primeFactorization(int n) {
    findPrime();
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 0; prime[i] <= sqr; i++) {
        if(n % prime[i] == 0) {
            fac[num].x = prime[i];
            fac[num].count = 0;
            while(n % prime[i] == 0) {
                fac[num].count++;
                n /= prime[i];
            }
            num++;
        }
        if(n == 1) {
            break;
        }
    }
    if(n > 1) {
        fac[num].x = n;
        fac[num].count = 1;
        num++;
    }
}

/*
    扩展: 求一个正整数N的因子个数, 只需要对其进行质因子分解, 得到各质因子 pi 的个数分别为 e1, e2...ek, 
        于是N的因子个数就是 (e1+1)*(e2+1)*...*(ek+1).
*/
int getFactorCount(int n) {
    int count = 1;
    primeFactorization(n);
    for(int i = 0; i < num; i++) {
        count *= (fac[i].count + 1);
    }

    return count;
}

int main(void) {

    int n;
    scanf("%d", &n);
    //printf("%d 的因子个数为 %d\n", n, getFactorCount(n));
    primeFactorization(n);
    printf("%d = ", n);
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < fac[i].count; j++) {
            printf("%d ", fac[i].x);
        }
    }
    printf("\n");

    return 0;
}
