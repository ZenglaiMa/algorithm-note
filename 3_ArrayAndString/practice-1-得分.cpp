
// 问题: 给出一个由O和X组成的串(长度为1~80), 统计得分. 每个O的得分为目前连续出现的O的个数,
//       X的得分为0. 例如: OOXXOXXOOO 的得分为 1+2+0+0+1+0+0+1+2+3.
#include <stdio.h>
#include <string.h>

char s[90];

int main(void) {

    int count = 0, len, sum = 0;
    scanf("%s", s);
    len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(s[i] == 'O') {
            count++;
            sum += count;
        }
        if(s[i] == 'X')
            count = 0;
    }
    printf("%d\n", sum);

    return 0;
}