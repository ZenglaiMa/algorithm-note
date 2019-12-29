
// 题目: 长度为 n 的环状序列有 n 种表示法, 分别从某位置开始顺时针得到. 例如
//              C
//           T     G
//         C         A
//         G         G
//           A     T
//              C
//       有10种表示法: CGAGTCAGCT, GAGTCAGCTC, AGTCAGCTCG等. 这些表示法中,
//       字典序最小的称为"最小表示". 输入一个长度为 n(n <= 100)的环状DNA串(只包含ACGT),
//       输出该环状串的最小表示. 例如CTCC的最小表示是CCCT, CGAGTCAGCT的最小表示是AGCTCGAGTC.
//       所谓字典序, 就是字符串在字典中的顺序. 对于两个字符串, 从第一个字符开始比较, 当某一位置
//       的字符不同时, 该位置字符较小的串, 字典序较小(如: abc 比 bcd 字典序小); 如果其中一个字符
//       已经没有更多字符, 但另一个字符串还没结束, 则较短的字符串字典序较小(如: he 比 hello 字典序小).
//       字典序可以推广到任意序列, 如: 序列 1,2,4,7 比 1,2,5 的字典序小.
/*
    思路: 循环输入的串, 用一个变量ans表示到目前为止, 字典序最小的串在输入串中的起始位置, 不断更新ans.
          通过 %len 实现环形.
*/

#include <stdio.h>
#include <string.h>

char ch[110];

int isLess(const char s[], int p, int q) { // 判断在环形串s中, 起始位置为 p 的串是否比起始位置为 q 的串字典序小
    int len = strlen(s);
    for(int i = 0; i < len; i++) { // 比较两个串相应位置的字符
        if(s[(p + i) % len] != s[(q + i) % len])
            return s[(p + i) % len] < s[(q + i) % len];
    }
    return 0; // 两串相等
}


int main(void) {

    int len, ans = 0;
    scanf("%s", ch);
    len = strlen(ch);
    for(int i = 1; i < len; i++) {
        if(isLess(ch, i, ans))
            ans = i;
    }
    for(int i = 0; i < len; i++) {
        putchar(ch[(ans + i) % len]);
    }
    printf("\n");
    
    return 0;
}
