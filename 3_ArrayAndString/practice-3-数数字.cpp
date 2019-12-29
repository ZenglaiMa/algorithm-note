
// 问题: 把前n(n<=10000)个整数顺次写在一起: 12345678910111213141516..., 数一数 0~9各出现过多少次.
//       输入n, 输出10个整数, 分别是0,1,2...9出现的次数.
/*
    思路: 将 0~9 出现的次数存在数组中, 如 arr[0]=10, 表示数字0出现过10次. 枚举1~n, 对每一个数的
          每一位进行分离, 然后数组对应位置的值+1即可.
*/
#include <stdio.h>
#include <string.h>

int arr[15];

int main (void) {
    
    int n, first = 1;
    scanf("%d",&n);
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= n; i++) {
        int m = i;
        while(m > 0) {
            arr[m % 10]++;
            m /= 10;
        }
    }
    for(int i = 0; i <= 9; i++) {
        if(first) { // 判断是否是第一次输出, 第一次正常输出, 其余每个输出前有一个空格
            printf("%d", arr[i]);
            first = !first;
        } else {
            printf(" %d", arr[i]);
        }
    }
    printf("\n");

    return 0;
}