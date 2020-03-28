/*
    堆排序: 对大顶堆排序结果递增, 对小顶堆排序结果递减, 这里以对序列递增排序为例.
        因为一个大顶堆的堆顶元素永远是堆中权值最大的, 于是堆排序的基本思路就是从堆的最后一个元素开始, 将其与堆顶元素进行交换, 然后
        对堆顶元素进行向下调整即可. 具体实现为逆向遍历 heap, 假设当前访问的是 i 号位, 那么将 i 号元素与堆顶元素交换, 然后对堆顶元素
        进行在 [1, i-1] 范围内的向下调整即可.
    时间复杂度: O(nlogn)
    空间复杂度: O(1)
    稳定性: 不稳定
*/

#include <algorithm>
using namespace std;

// 向下调整
void downAdjust(int heap[], int low, int high) {
    int i = low, j = 2 * i;
    while(j <= high) {
        if(j + 1 <= high && heap[j + 1] > heap[j]) {
            j = j + 1;
        }
        if(heap[j] > heap[i]) {
            swap(heap[i], heap[j]);
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
}

// 建堆(堆化)
void createHeap(int heap[], int n) {
    for(int i = n / 2; i >= 1; i--) {
        downAdjust(heap, i, n);
    }
}

// 堆排序, arr 为待排序序列, 下标从 1 开始; n 为序列中元素个数
void heapSort(int arr[], int n) {
    createHeap(arr, n);
    for(int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);
        downAdjust(arr, 1, i - 1);
    }
}
