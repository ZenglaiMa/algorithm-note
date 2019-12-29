
// 问题: 如果一个字符串可以由某个长度为k的字符串重复多次得到, 则称该串以k为周期. 例如:
//       abcabcabcabc 以3为周期(注意, 它也以6和12为周期). 输入一个长度不超过80的字符串,
//       输出其最小周期.
/*
    思路: 易知, 周期数必然是字符串长度len的约数, 所以从1开始枚举len的约数k, 目标就是找到符合条件的最小k.
          将整个串分成 len/k 组, 如果第1组和其他组的对应位置的字符都相等, 则得解.
*/

#include <stdio.h>
#include <string.h>

char s[100];

int main(void) {

    int len, k;
    scanf("%s", s);
    len = strlen(s);
    for(k = 1; k <= len; k++) {
        if(len % k != 0) // k不是len的约数, 直接continue
            continue;
        int flag = 1;
        for(int i = 1; i < len / k; i++) { // 每一组都和第一组进行比较
            for(int j = 0; j < k; j++) {
                if(s[j] != s[j + i * k]) { // 如果有一个不相等, 所有的组就都不用比较了
                    flag = 0;
                    break;
                }
            }
            if(!flag)
                break;
        }
        if(flag)
            break;
    }
    printf("%d\n", k);

    return 0;
}
