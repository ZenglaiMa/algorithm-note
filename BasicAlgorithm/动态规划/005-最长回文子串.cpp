/*
    最长回文子串: 给出一个字符串S, 求S的最长回文子串的长度. 例如字符串 "PATZJUJZTACCBCC" 的最长回文子串为 "ATZJUJZTA", 长度为 9.
    思路: 令 dp[i][j] 表示 S[i] 至 S[j] 这个子串是否是回文子串, 是则为 true, 否则为 false:
            ① 若 S[i]==S[j], 那么只要 S[i+1] 至 S[j-1] 是回文子串, S[i] 至 S[j] 就是回文子串, 否则就不是；
            ② 若 S[i]!=S[j], 那么 S[i] 至 S[j] 一定不是回文子串.
         边界: dp[i][i]=true, dp[i][i+1]=(S[i]==S[i+1])?true:false
*/
#include <cstdio>
#include <cstring>

const int MAXN = 1010;
char S[MAXN];
bool dp[MAXN][MAXN] = { false }; // dp[i][j] 表示 S[i] 至 S[j] 这个子串是否是回文子串, 是则为 true, 否则为 false

int main(void) {

    scanf("%s", S);
    int len = strlen(S), ans = 1; // ans记录最长回文子串长度
// int start = 0, end = 0; // 记录最长回文子串的开始和结束位置
    // 边界
    for(int i = 0; i < len; i++) {
        dp[i][i] = true;
        if(i < len - 1) {
            if(S[i] == S[i + 1]) {
                dp[i][i + 1] = true;
                ans = 2;
// start = i;
// end = i + 1;
            }
        }
    }
    // 状态转移方程
    for(int L = 3; L <= len; L++) { // 从长度为3开始枚举子串长度
        for(int i = 0; i + L - 1 < len; i++) { // 枚举子串的起始端点
            int j = i + L - 1; // 子串右端点
            if(S[i] == S[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                ans = L; // 更新最长回文子串长度
// start = i;
// end = j;
            }
        }
    }
    printf("%d\n", ans);

// strncpy(S, S + start, end - start + 1);
// S[end - start + 1] = '\0';
// printf("%s\n", S);

    return 0;
}
