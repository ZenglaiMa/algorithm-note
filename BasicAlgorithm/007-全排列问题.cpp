
/*
    全排列(Full Permutation问题, 算法笔记P115): 比如 1 2 3 的全排列为: 123 132 213 231 312 321.
        若只想求解最后结果, 更便捷的方式是使用 <algorithm> 头文件下的 next_permutation() 函数.
*/

#include <cstdio>

const int maxn = 15;
int P[maxn], hashTable[maxn] = { false }, n;

void generateP(int index) {
    if(index == n) {
        for(int i = 0; i < n; i++) {
            printf("%d", P[i]);
        }
        printf("\n");
        return ;
    }
    for(int x = 1; x <= n; x++) {
        if(hashTable[x] == false) {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
        }
    }
}

int main(void) {

    scanf("%d", &n); // 欲输出 1~n 的全排列
    generateP(0); // 从 P[0] 位置开始填充

    return 0;
}
