/*
    插入排序: 插入排序是简单排序(选泡插)中最好的一种, 时间复杂度为 O(n^2), 空间复杂度为 O(1), 稳定.
        (最好时间复杂度可达到 O(n), 即数组有序时).
*/

#include <cstdio>

void InsertionSort(int arr[], int len) {
    for(int i = 1; i < len; i++) {
        int temp = arr[i], j;
        for(j = i; j > 0; j--) {
            if(temp < arr[j - 1]) {
                arr[j] = arr[j - 1];
            } else {
                break;
            }
        }
        arr[j] = temp;
    }
}


int main(void) {

    int arr[10] = { 5, 3, 6, 8, 1, 7, 9, 4, 2, 5 };
    int length = sizeof(arr) / sizeof(int);
    InsertionSort(arr, length);
    for(int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}