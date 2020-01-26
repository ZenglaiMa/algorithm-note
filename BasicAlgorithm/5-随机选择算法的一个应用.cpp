/*
    随机选择算法的一个应用:
        给定一个由整数组成的集合, 集合中的整数各不相同, 现在要将他们分为两个子集合, 使得这两个子集合的并为原集合, 
        交为空集, 同时在两个子集合的元素个数n1与n2之差的绝对值|n1-n2|尽可能的小的前提下, 要求它们各自的元素之和
        S1和S2之差的绝对值|S1-S2|尽可能大, 求这个 S1 - S2 等于多少.
*/

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

/*
    思路①: 对原集合(长度为n)进行排序(从小到大), 然后从 n/2 处分成两个子集合, 前 n/2 个元素作为一个子集合, 剩下的元素
          作为另一个子集合即可. 时间复杂度为 O(nlogn).
*/
int classicSolution(int A[], int len) {
    int sum = 0, sum1 = 0;
    sort(A, A + len);
    for(int i = 0; i < len; i++)
        sum += A[i];
    for(int i = 0; i < len / 2; i++)
        sum1 += A[i];
    
    return (sum - sum1) - sum1;
}

/*
    思路②: 利用随机选择算法, 原问题相当于求集合中第 n/2 大的数, 同时将原集合分为两部分: 其中一个子集合中的每个数都小于
          等于这个数, 另一个子集合中的每个数都大于这个数, 至于这两个集合内部的顺序不去关心. 因此只需要用随机选择算法
          求出第 n/2 大的数即可, 该算法会自动切分好两个集合, 期望时间复杂度为 O(n).
*/
int randPartition(int A[], int left, int right) {
    int r = floor((1.0 * rand() / RAND_MAX * (right - left) + left) + 0.5);
    swap(A[left], A[r]);
    int temp = A[left];
    while(left < right) {
        while(left < right && A[right] > temp)
            right--;
        A[left] = A[right];
        while(left < right && A[left] <= temp)
            left++;
        A[right] = A[left];
    }
    A[left] = temp;

    return left;
}

void randSelect(int A[], int left, int right, int K) {
    if(left == right)
        return ;
    int p = randPartition(A, left, right);
    int M = p - left + 1;
    if(K == M)
        return ;
    if(K < M)
        return randSelect(A, left, p - 1, K);
    else
        return randSelect(A, p + 1, right, K - M);
}

int main(void) {

    srand((unsigned)time(NULL));

    // 思路①
    int arr[11] = { 5, 12, 7, 2, 9, 3, 8, 10, 6, 1, 15 };
    printf("%d\n", classicSolution(arr, 11));

    // 思路②
    int brr[11] = { 5, 12, 7, 2, 9, 3, 8, 10, 6, 1, 15 };
    int sum = 0, sum1 = 0;
    for(int i = 0; i < 11; i++)
        sum += brr[i];
    randSelect(brr, 0, 11 - 1, 11 / 2);
    for(int i = 0; i < 11 / 2; i++)
        sum1 += brr[i];
    printf("%d\n", (sum - sum1) - sum1);

    return 0;
}
