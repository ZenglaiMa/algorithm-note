
// 归并排序: 时间复杂度为 O(nlogn), 空间复杂度为 O(n), 稳定.
//      归并排序用途十分广泛, 比如Java和Python中对于对象的排序就默认使用(改进的)归并排序(Java中使用改进的归并排序: TimSort), 
//      之所以不使用快速排序, 是因为对象排序一般要求稳定, 而快排不稳定.

#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100

// 将数组A的[L1, R1]和[L2, R2]区间合并为有序区间(L2即为R1+1)
void merge(int A[], int L1, int R1, int L2, int R2) {
    int i = L1, j = L2, temp[maxn], index = 0;
    while(i <= R1 && j <= R2) {
        if(A[i] <= A[j])
            temp[index++] = A[i++];
        else
            temp[index++] = A[j++];
    }
    while(i <= R1)
        temp[index++] = A[i++];
    while(j <= R2)
        temp[index++] = A[j++];
    for(int i = 0; i < index; i++)
        A[L1 + i] = temp[i];
}

// 1. 归并排序(递归实现)
void MergeSort1(int A[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        MergeSort1(A, left, mid);
        MergeSort1(A, mid + 1, right);
        merge(A, left, mid, mid + 1, right);
    }
}

// 2. 归并排序(非递归实现): 
//      思想: 每次分组时组内元素的个数上限都是2的幂次. 于是令步长step初值为2, 然后将数组中每step个元素作为一组,
//            将其内部进行排序, 然后再令 step*2, 重复上面操作, 直到 step/2 超过元素个数n.
void MergeSort2(int A[], int len) {
    // step为组内元素个数
    for(int step = 2; step / 2 < len; step *= 2) {
        // 每一组有step个元素, 中点为 mid=(step-1)/2, 左右区间进行合并
        for(int i = 0; i < len; i += step) { // 对于每一组
            int mid = i + (step - 1) / 2;
            if(mid + 1 < len) { // 如果右区间还存在元素, 则进行归并
                merge(A, i, mid, mid + 1, min(len - 1, i + step - 1));
            }
        }
    }
}

int main(void) {

    int arr[10] = { 66,12,33,57,57,64,27,18,5,20 };
    MergeSort1(arr, 0, 10 - 1);
    printf("排序结果(递归方式):\n");
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int brr[13] = { 66,12,33,57,57,64,27,18,5,20,20,18,28 };
    MergeSort2(brr, 13);
    printf("排序结果(非递归方式):\n");
    for(int i = 0; i < 13; i++)
        printf("%d ", brr[i]);
    printf("\n");

    return 0;
}
