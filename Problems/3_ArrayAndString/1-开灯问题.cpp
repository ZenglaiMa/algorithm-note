
// 题目: 有 n 盏灯, 编号为 1~n. 第1个人把所有灯都打开, 第2个人按下所有编号为2的倍数的灯的开关(对应的灯被关掉),
//       第3个人按下所有编号为3的倍数的灯的开关(对应编号的灯如果开着则被关上, 如果关着则被打开), 以此类推.
//       一共有 k 个人, 问最后有哪些灯开着. 输入 n 和 k, 输出开着的灯的编号. k <= n <= 1000;
// 样例输入:
//  7 3
// 样例输出:
//  1 5 6 7

#include <stdio.h>
#include <string.h>

int arr[1010]; // 定义的数组的容量要比题设中的最大范围再稍微大一些.

int main(void) {

    int n, k, first = 1;
    scanf("%d%d", &n, &k);
    memset(arr, 0, sizeof(arr)); // 向arr数组中填充0, 该函数定义在<string.h>中.
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            if(j % i == 0) { // 第i个人操作编号为i的倍数的灯.
                arr[j] = !arr[j]; // 按下对应编号的灯的开关, 开着的关上, 关着的打开, 即切换到其对立状态.
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(arr[i]) {
            if(first) {  // first变量用来防止输出多余空格, 第一个输出前无空格, 其余输出前都有一个空格隔开.
                printf("%d", i);
                first = 0;
            } else {
                printf(" %d", i);
            }
        }
    }
    printf("\n");
    
    return 0;
}

// note: 1. 思路: 用arr[1], arr[2], arr[3]...arr[n]表示编号为1, 2, 3...n的灯是否开着, 值为0表示关着, 非0表示开着.
//       2. memcpy函数定义在 <string.h>中, memcpy(b, a, sizeof(int)*k) 表示从数组a中复制k个int类型元素到数组b中,
//          如果要把数组a中元素全部复制到数组b中, 可以 memcpy(b, a, sizeof(a)).