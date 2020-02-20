/*
    用DFS解决矩阵块数问题
*/

#include <cstdio>

const int maxn = 100;
int m, n, matrix[maxn][maxn];
bool isVisit[maxn][maxn] = { false }; // 标识某个位置是否被访问过
int X[4] = { 0, 0, 1, -1 }; // 增量数组, 表示4个方向
int Y[4] = { 1, -1, 0, 0 };

void DFS(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= n) {
        return ;
    }
    if(matrix[x][y] == 0 || isVisit[x][y]) {
        return ;
    }

    isVisit[x][y] = true;

    for(int i = 0; i < 4; i++) {
        DFS(x + X[i], y + Y[i]);
    }
}

int main(void) {

    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++) { // 初始化矩阵
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++) { // 枚举每一个位置
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 1 && isVisit[i][j] == false) { // 若该位置为 1 且还没被访问过, 再进行DFS
                ans++;
                DFS(i, j);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}