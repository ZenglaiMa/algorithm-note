
/*
    按要求输入如下格式的杨辉三角:

    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1
    1 5 10 10 5 1

    最多输出10层

    输入
    输入只包含一个正整数n, 表示将要输出的杨辉三角的层数.

    输出
    对应于该输入, 请输出相应层数的杨辉三角, 每一层的整数之间用一个空格隔开.
*/

#include <cstdio>
#include <cstring>

int arr[15][15];

int main(void) {

    int n;
    scanf("%d", &n);
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < n; i++) {
        arr[i][0] =  arr[i][i] = 1;
        for(int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    for(int i = 0; i < n; i++) {
        int flag = 1;
        for(int j = 0; j < i + 1; j++) {
            if(flag) {
                printf("%d", arr[i][j]);
                flag = 0;
            } else {
                printf(" %d", arr[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
