
#include <cmath>

/*
    质数的判断, 该方法的复杂度为 O(sqrt(n))
        注: 1 既不是质数也不是合数
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
