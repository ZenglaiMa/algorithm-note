/*
    n皇后问题(算法笔记P116): 在一个 n*n 的国际象棋棋盘上放置 n 个皇后, 使得这 n 个皇后两两不在同一行、同一列、同一对角线上, 求合法的方案数.
*/

#include <cstdio>
#include <algorithm>

const int maxn = 10;
int P[maxn], hashTable[maxn] = { false }, n, count = 0;

// 暴力解法
void solve_1(int index) {
    if(index == n + 1) { // index 从 1 开始
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(abs(i - j) == abs(P[i] - P[j])) {
                    flag = false;
                }
            }
        }
        if(flag) {
            count++;
        }
        return ;
    }
    for(int x = 1; x <= n; x++) {
        if(hashTable[x] == false) {
            P[index] = x;
            hashTable[x] = true;
            solve_1(index + 1);
            hashTable[x] = false;
        }
    }
}

// 回溯法: 如果在到达递归边界之前, 由于一些事实导致已经不需要再往下继续递归, 就可以直接返回上一层.
void solve_2(int index) {
    if(index == n + 1) { // 能到达递归边界的一定是合法的
        count++;
        return ;
    }
    for(int x = 1; x <= n; x++) {
        if(hashTable[x] == false) {
            bool flag = true;
            for(int pre = 1; pre < index; pre++) {
                if(abs(index - pre) == abs(x - P[pre])) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                P[index] = x;
                hashTable[x] = true;
                solve_2(index + 1);
                hashTable[x] = false;
            }
        }
    }
}


int main(void) {

    n = 8;
    solve_2(1);
    printf("%d\n", count);

    return 0;
}
