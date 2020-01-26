
#include <cstdio>

// 给定一个递增的正整数序列和一个正整数M, 求序列中两个不同位置的数a和b,
// 使得他们的和恰好为M, 输出所有满足条件的方案. 如给定序列 {1,2,3,4,5,6} 和正整数 M=8,
// 就存在 2+6=8 和 3+5=8 存在.

// 1. 暴力解法
void ViolentSolution(int arr[], int len, int m) {
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if(arr[i] + arr[j] == m)
                printf("arr[%d] + arr[%d] = %d\n", i, j, m);
        }
    }
}

// 暴力解法存在的问题: 对于一个确定的arr[i]来说, 如果当前a[j]满足arr[i]+arr[j]>M, 则必然有arr[i]+arr[j+1]>M成立,
//      因为序列是递增的, 因此就不需要再对arr[j]之后的数进行枚举. 对某个arr[i]来说, 如果找到一个arr[j], 使得
//      arr[i]+arr[j]>M 恰好成立, 那么一定有arr[i+1]+arr[j]>M 成立, 因此arr[i]之后的元素也不必再去枚举.

// 2. 通过two pointers进行优化
void TwoPointersSolution(int arr[], int len, int m) {
    int i = 0, j = len - 1;
    while(i < j) {
        if(arr[i] + arr[j] == m) {
            printf("arr[%d] + arr[%d] = %d\n", i, j, m);
            i++;
            j--;
        } else if(arr[i] + arr[j] > m) {
            j--;
        } else {
            i++;
        }
    }
}
