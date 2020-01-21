
// 题目: 输入一个字符串, 判断它是否为回文串或者镜像串. 输入字符串保证不含数字0. 所谓回文串,
//       就是反转以后和原串相同, 如abba、madam. 所谓镜像串, 就是左右镜像之后和原串相同,
//       如2S、3AIAE. 注意, 并不是每个字符在镜像之后都能得到一个合法字符.
//       每个字符的镜像如下所示:
/*
    Character  Reverse  Character  Reverse  Character  Reverse
        A         A         M         M         Y         Y
        B                   N                   Z         5
        C                   O         O         1         1
        D                   P                   2         S
        E         3         Q                   3         E
        F                   R                   4         
        G                   S         2         5         Z
        H         H         T         T         6         
        I         I         U         U         7         
        J         L         V         V         8         8
        K                   W         W         9         
        L         J         X         X         
*/
// 输入每行包含一个字符串(保证只有上述字符, 不含空白字符), 判断它们是否为回文串和镜像串(共4种组合).
// 每组数据之间输出一个空行.
/* 样例输入:
    NOTAPALINDROME
    ISAPALINILAPASI
    2A3MEAS
    ATOYOTA
*/
/* 样例输出:
    NOTAPALINDROME -- is not a palindrome.

    ISAPALINILAPASI -- is a regular palindrome.

    2A3MEAS -- is a mirrored string.

    ATOYOTA -- is a mirrored palindrome.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char rev[] = {"A   3  HIL JM O   2TUVWXY51SE Z  8 "}; // 题目中给出的A~Z和1~9的镜像字符
const char* msg[] = {"is not a palindrome.", "is a regular palindrome.", 
    "is a mirrored string.", "is a mirrored palindrome."}; // 定义4中输出信息

char getMirror(char ch) {
    if(isalpha(ch)) // int isalpha(char ch) 判断ch是否为字母, 定义在<ctype.h>中.
        return rev[ch - 'A']; // ch - 'A' 是求大写字母字符 ch 在rev中的下标
    return rev[ch - '0' + 25]; // ch - '0' + 25 是求数字字符 ch 在rev中的下标(无数字0, 所以是+25)
}

int main(void) {

    char s[30];
    while(scanf("%s", s) == 1) {
        int len = strlen(s);
        int isMirrored = 1, isPalindrome = 1;
        for(int i = 0; i < (len + 1) / 2; i++) {
            if(s[i] != s[len - 1 - i])
                isPalindrome = 0; // 不是回文串
            if(getMirror(s[i]) != s[len - 1 - i])
                isMirrored = 0; // 不是镜像串
        }
        printf("%s -- %s\n\n", s, msg[isMirrored * 2 + isPalindrome]); // 体会这句话的含义.
    }

    return 0;
}

// note: 1. 求回文串: 将第i个字符和倒数第i个字符作比较, 如果都相等, 则是回文串;
//       2. 求镜像串: 将第i个字符的镜像字符和倒数第i个字符作比较, 如果都相等, 则是镜像串.
//       3. 由于ASCII码表中大写字母、小写字母和数字都是连续的, 所以如果字符 ch 为大写字母字符,
//          则 ch - 'A' 就表示字符ch在字母表中的序号, 如 'B' - 'A' 结果为1, 则字符B的序号为1;
//          同理, 数字字符 ch - '0' 结果就是ch代表的数字, 如 '5' - '0' 结果为数字 5.
