/*
    选择排序: 时间复杂度为 O(n^2), 空间复杂度为 O(1), 不稳定. 一般不采用, 因为不稳定.
*/

#include <cstdio>

void selectionSort(int arr[], int len) {
    for(int i = 0; i < len - 1; i++) {
        int minPos = i;
        for(int j = i + 1; j < len; j++) {
            if(arr[j] < arr[minPos])
                minPos = j;
        }
        int t = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = t;
    }
}


int main(void) {

    int arr[10] = { 5, 3, 6, 8, 1, 7, 9, 4, 2, 5 };
    selectionSort(arr, 10);
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

