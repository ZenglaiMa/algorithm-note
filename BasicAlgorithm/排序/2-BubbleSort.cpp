/*
    冒泡排序: 时间复杂度为 O(n^2), 空间复杂度为 O(1), 稳定. 一般不采用, 因为速度慢.
        (最好时间复杂度可达到 O(n)).
*/

#include <cstdio>

void bubbleSort(int arr[], int len) {
    int change = 1;
    for(int i = 0; i < len - 1 && change; i++) {
        change = 0;
        for(int j = 0; j < len - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                change = 1;
            }
        }
    }
}


int main(void) {

    int arr[10] = { 5, 3, 6, 8, 1, 7, 9, 4, 2, 5 };
    bubbleSort(arr, 10);
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

