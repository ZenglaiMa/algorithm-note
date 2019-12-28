
// 题目: 在n*n方阵里填入1 2 3 ... n*n, 要求填成蛇形, n<=8, 如 4*4 方针:
//  10 11 12 1
//   9 16 13 2
//   8 15 14 3
//   7  6  5 4

#include <stdio.h>
#include <string.h>

int arr[10][10];

int main(void) {

    int n, x, y, tot;
    scanf("%d", &n);
    memset(arr, 0, sizeof(arr)); // arr初始化都填充0
    x = 0; y = n - 1; // 起点
    tot = arr[x][y] = 1;
    while(tot < n * n) {
        while(x + 1 < n && !arr[x + 1][y]) { // 向下
            arr[++x][y] = ++tot;
        }
        while(y - 1 >= 0 && !arr[x][y - 1]) { // 向左
            arr[x][--y] = ++tot;
        }
        while(x - 1 >= 0 && !arr[x - 1][y]) { // 向上
            arr[--x][y] = ++tot;
        }
        while(y + 1 < n && !arr[x][y + 1]) { // 向右
            arr[x][++y] = ++tot;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// note: 思路: 首先确定起点, 由题意可知方阵的最右上角为起点, 这个位置为 arr[0][n-1] = 1, 
//             然后按照下左上右的顺序填满整个方阵, 当最后一个数为n*n时表示填满整个方阵, 程序结束. 
//             解释中间4条while语句中的第一个, 其他的类似.
//             第一个while是不断向下走并填数, 原则是: 先判断再移动, 
//             即先判断下一个位置是否越界且下一个位置是否未被填充过, 如果下一个位置未越界且没有被填充过(值为0),
//             则移动并填数. 注意我们总是先预判, 判断符合条件以后再进行操作, 而不是先操作, 发现问题再回退.
