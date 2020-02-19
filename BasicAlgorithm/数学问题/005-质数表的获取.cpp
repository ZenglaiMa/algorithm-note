/*
    质数表的获取
        ① 非筛选法: 时间复杂度 O(n√n)
        ② 埃氏筛选法: 时间复杂度 O(nloglogn)
        ③ 欧拉筛选法: 时间复杂度 O(n)
*/

#include <cmath>
#include <cstdio>

const int goal = 1000; // goal表示获取的是goal以内的质数
int prime[goal], index = 0; // prime数组用来存放找到的质数, index表示质数表中质数的个数

bool p[goal] = { false }; // 如果i为质数, 则p[i]为false, 否则p[i]为true, 埃氏筛选算法中使用

/*
    ① 非筛选法获取质数表: O(n√n)
*/
bool isPrime(int n) {
    if(n <= 1) {
        return false;
    }
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

void findPrime() {
    for(int i = 1; i <= goal; i++) {
        if(isPrime(i)) {
            prime[index++] = i;
        }
    }
}

/*
    ② 埃氏筛选法获取质数表: O(nloglogn)
        思想: 从小到大枚举所有数, 对每一个质数(需要知道第一个质数为2), 筛去它的所有倍数, 剩下的就都是质数了.
            当从小到大到达某数 a 时, 如果 a 没有被前面步骤的数筛去, 那么 a 一定是质数. 这是因为, 如果 a 不是质数,
            那么 a 一定有小于 a 的质因子, 这样在之前的步骤中 a 一定会被筛掉, 所有, 如果当枚举到 a 时还没有被筛掉,
            那么 a 一定是质数.
*/
void eratosthenes() {
    for(int i = 2; i <= goal; i++) {
        if(p[i] == false) {
            prime[index++] = i;
            for(int j = i + i; j <= goal; j += i) { // 筛去所有i的倍数
                p[j] = true;
            }
        }
    }
}


int main(void) {

    findPrime();
    //eratosthenes();
    for(int i = 0; i < index; i++)
        printf("%d ", prime[i]);
    printf("\n");

    return 0;
}
