
// 题目: 把手放在键盘上时, 稍不注意就会往右错一位. 这样, Q会变成W, J会变成K等.
//       输入一个错位后敲出的字符串(所有字母均大写), 输出本来正确的句子.
//       保证输入合法, 即一定是错位后的字符串, 例如输入中不会出现 A.
// 样例输入:
//  O S, GOMR YPFSU/
// 样例输出:
//  I AM FINE TODAY.

#include <stdio.h>

char s[] = {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};

int main(void) {

    int c;
    while((c = getchar()) != EOF) {
        int i;
        for(i = 1; s[i] && s[i] != c; i++) ; // 寻找和输入的字符相同的s[i]
        if(s[i]) {
            putchar(s[i - 1]);
        } else {
            putchar(c);
        }
    }

    return 0;
}