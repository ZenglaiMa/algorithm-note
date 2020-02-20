/*
    广度优先搜索(BFS): 一般由队列实现, 且总是按层次的顺序进行遍历.
    一个经典问题: 给出一个 m*n 矩阵, 矩阵中的元素为0或1. 称位置(x, y)与其上下左右四个位置(x, y+1), (x, y-1), (x+1, y), (x-1, y)是相邻的.
        如果矩阵中有若干个 1 是相邻的(不必两两相邻), 则称这些 1 构成了一个"块". 求给定矩阵中"块"的个数.
        例如, 给定如下 6*7 矩阵中, "块"的个数为4:
                    0 1 1 1 0 0 1
                    0 0 1 0 0 0 0
                    0 0 0 0 1 0 0
                    0 0 0 1 1 1 0
                    1 1 1 0 1 0 0
                    1 1 1 1 0 0 0

    思路: 经典的广搜思路: 枚举每一个位置的元素, 如果为 0, 则跳过; 如果为 1, 则使用BFS算法查询与该位置相邻的4个位置(当然不能出界), 判断这些位置是否为 1,
        如果某个相邻位置为 1, 则以同样的方法去查询与该位置相邻的4个位置, 直到整个 "1" 块访问完毕. 在BFS中, 为了防止走回头路, 一般可以设置一个
        bool 型的数组 inq 来记录每个位置是否在 BFS 过程中已入过队.
*/

#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
    int x;
    int y;
} Coordinate;

Coordinate c;
const int maxn = 100;
int m, n, matrix[maxn][maxn], inq[maxn][maxn] = { false };
int X[4] = { 0, 0, 1, -1 }; // 增量数组, 表示4个方向
int Y[4] = { 1, -1, 0, 0 }; // 增量数组, 表示4个方向

bool judge(int x, int y) { // 判断某个位置是否需要访问
    if(x < 0 || x >= n || y < 0 || y >= m) { // 越界
        return false;
    }
    if(matrix[x][y] == 0 || inq[x][y]) { // 该位置数据为 0, 或者该位置数据已经入过队
        return false;
    }

    return true;
}

void BFS(int x, int y) { // BFS访问(x, y)位置所在的块, 将该块中所有 "1" 的inq都置为true
    queue<Coordinate> q;
    c.x = x;
    c.y = y;
    q.push(c);
    inq[x][y] = true;

    while(!q.empty()) {
        Coordinate top = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) { // 枚举4个方向
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX, newY)) { // 如果需要访问
                c.x = newX;
                c.y = newY;
                q.push(c);
                inq[newX][newY] = true;
            }
        }
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
            if(matrix[i][j] == 1 && inq[i][j] == false) { // 若该位置为 1 且还没入过队, 再进行BFS
                ans++;
                BFS(i, j);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}