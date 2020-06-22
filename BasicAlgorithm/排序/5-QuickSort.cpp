
// 快速排序: 平均时间复杂度为 O(nlogn), 最坏时间复杂度为 O(n^2)(当序列基本有序时).
//           空间复杂度为 O(logn)~O(n).
//           不稳定.

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

// 对区间 [left, right] 进行划分, 以A[left]为主元, 使得A[left]左边的元素都比它小, 右边的元素都比它大,
// 返回划分完成后A[left]所在的下标.
int partition(int A[], int left, int right) {
    int temp = A[left];
    while(left < right) { // 只要left与right不相遇
        while(left < right && A[right] > temp) // 若当前A[right]值大于主元值, 反复左移right
            right--;
        A[left] = A[right]; // 将A[right]挪到A[left]
        while(left < right && A[left] <= temp) // 若当前A[left]值小于等于主元值, 反复右移left
            left++;
        A[right] = A[left]; // 将A[left]挪到A[right]
    }
    A[left] = temp; // left与right相遇时, 跳出循环, 将主元值temp放到相遇处

    return left; // 返回相遇位置下标
}

// 随机选择主元, 对区间 [left, right] 进行划分
// 快排算法当序列中元素的排列比较随机时效率最高, 但当序列中元素接近有序时时间复杂度会退化到 O(n^2),
// 产生这种情况的主要原因是主元没有把当前区间划分成两个长度接近的子区间, 一个解决办法就是我们不总以
// A[left]作为主元, 而是在序列中随机选择主元.
int randPartition(int A[], int left, int right) {
    // 生成[left, right]内的随机数 r
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

// 快速排序
void quickSort(int A[], int left, int right) {
    if(left < right) {
        int pos = partition(A, left, right);
        //int pos = randPartition(A, left, right);
        quickSort(A, left, pos - 1);
        quickSort(A, pos + 1, right);
    }
}

int main(void) {

    srand((unsigned) time(NULL));

    int arr[11] = { 35,18,16,72,24,65,12,88,46,28,55 };
    quickSort(arr, 0, 11 - 1);
    for(int i = 0; i < 11; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
