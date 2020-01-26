/*
    随机选择算法:
        讨论这样一个问题: 如何从一个无序序列中求出第K大的数. 例如对数组{5,12,7,2,9,3}来说, 第3大的数是5, 第5大的数是9.
        最直接的想法是对数组先排一下序, 然后直接取第K个元素即可, 但这样的时间复杂度最好为 O(nlogn). 但我们可以换一个思路:
        在快排算法中, 当对A[left, right]执行一次randPartition函数之后, 主元左侧的元素个数就是确定的且小于主元, 假设此时
        主元为A[p], 那么A[p]就是A[left, right]中的第 p-left+1 大的数. 不妨令 M = p - left + 1, 如果K==M, 那么说明第K大
        的数就是A[p], 如果 K<M, 说明第K大的数在主元左侧, 即 A[left...(p-1)] 中的第K大, 往左侧递归即可; 如果 K>M, 则说明
        第K大的数在主元右侧, 即A[(p+1)...right]中的第K-M大, 往右侧递归即可. 这样我们可以得到 O(n) 的时间复杂度.
    注意: 这样的问题, 最好还是使用第一种思想进行求解, 即先对数组排序, 然后直接取数即可, 当时间效率不够用时, 再考虑此算法.
*/

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

// 快排算法中的 randPartition
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

// 随机选择算法, 从 A[left, right] 中返回第 K 大的数
// 最坏时间复杂度为 O(n^2), 但是对于任意输入的期望时间复杂度却是 O(n)
int randSelect(int A[], int left, int right, int K) {
    if(left == right)
        return A[left];
    int p = randPartition(A, left, right);
    int M = p - left + 1;
    if(K == M)
        return A[p];
    if(K < M)
        return randSelect(A, left, p - 1, K);
    else
        return randSelect(A, p + 1, right, K - M);
}

int main(void) {

    srand((unsigned)time(NULL));
    int arr[6] = { 5, 12, 7, 2, 9, 3 };
    printf("%d\n", randSelect(arr, 0, 5, 5));

    return 0;
}
