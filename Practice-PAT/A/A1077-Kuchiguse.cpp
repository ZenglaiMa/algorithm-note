
/*
    问题: 给定N个字符串, 求它们的最长公共后缀, 如不存在则输出 "nai".
    思路: 1. 考虑到最长公共后缀需要从后往前枚举字符串, 因此不妨先将所有字符串反转, 这样就把问题转换成了求
             N个字符串的公共前缀, 方便解题. 其次, 要保证对字符串的访问不越界, 就需要事先求出所有字符串的
             最小长度 minLen, 这个值可以在读入字符串过程中获得.
          2. N个字符串的最短长度为 minLen, 因此枚举所有字符串在 [0, minLen) 内的字符, 判断相同位置字符
             是否相同. 如果相同, 统计公共前缀长度, 否则, 停止枚举. 最后根据最大公共前缀长度倒序输出即可.
*/

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char str[110][260]; // 存储读入的字符串
int minLen = 256; // 所有字符串的最小长度

void reverse(char s[]) { // 字符串反转函数
    int len = strlen(s);
    for(int i = 0; i < len / 2; i++) {
        char t = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = t;
    }
}

int main(void) {

    int n;
    scanf("%d", &n);
    getchar(); // 接收换行符, 因为不管是 gets() 还是 cin.getline() 都会将换行符读入
    for(int i = 0; i < n; i++) {
        // gets(str[i]); 
        // 注意: 在 C11 标准中 gets() 函数被正式删除, 所以该函数在遵循C11的编译器中无法编译通过, 可改成如下方式获取的字符串输入:
        //       cin.getline(), 该方式定义在C++标准中, 使用时要 #include <iostream> 同时 using namespace std;.
        cin.getline(str[i], 260);
        if(strlen(str[i]) < minLen)
            minLen = strlen(str[i]);
        reverse(str[i]);
    }

    int ans = 0; // 统计公共前缀字符个数
    for(int i = 0; i < minLen; i++) {
        char c = str[0][i];
        int same = 1;
        for(int j = 1; j < n; j++) {
            if(str[j][i] != c) {
                same = !same;
                break;
            }
        }
        if(same)
            ans++;
        else
            break;
    }

    if(ans == 0) { // 无公共前缀
        printf("nai");
    } else {
        for(int i = ans - 1; i >= 0; i--) // 因求的是公共后缀, 因此将公共前缀倒序输出
            printf("%c", str[0][i]);
    }
    printf("\n");

    return 0;
}