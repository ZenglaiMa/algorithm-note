
#include <cstdio>

// 两有序数组(以递增为例)合并成一个有序数组, 返回新数组的长度.
int merge(int A[], int B[], int C[], int lenA, int lenB) {
    int i = 0, j = 0, index = 0; // 双"指针", i指向A[], j指向B[]
    while(i < lenA && j < lenB) { // 两个序列均未扫描完毕
        if(A[i] <= B[j]) // 若A[i] <= B[j], 将A[i]加入C[]中, 并令 i++
            C[index++] = A[i++];
        else
            C[index++] = B[j++]; // 若A[i] > B[j], 将B[j]加入C[]中, 并令 j++
    }
    while(i < lenA) // 若B[]扫描完毕而A[]还有元素, 将A[]中元素直接放在C[]中
        C[index++] = A[i++];
    while(j < lenB) // 若A[]扫描完毕而B[]还有元素, 将B[]中元素直接放在C[]中
        C[index++] = B[j++];

    return index; // 返回新序列C[]的长度
}

