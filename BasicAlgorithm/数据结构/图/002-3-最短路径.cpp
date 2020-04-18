/*
    以上讨论的是利用Dijkstra算法求解从给定顶点到其它各顶点的最短距离, 还没有谈到最短路径本身怎么求解,
    此处就说一下这个问题. 详见算法笔记 P375.
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 1000;
const int INF = 0x3fffffff;
int G[MAXV][MAXV], n, d[MAXV];
bool vis[MAXV];

int pre[MAXV]; // 新增pre[], 用来存放从起点s到顶点v的最短路径上v的前一个顶点

void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++) { // 新增, 设初始状态每个顶点的前驱为自身
        pre[i] = i;
    }
    for(int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if(u == -1) {
            return ;
        }
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(!vis[v] && G[u][v] != INF && G[u][v] + d[u] < d[v]) {
                d[v] = G[u][v] + d[u];
                pre[v] = u; // 新增, 记录顶点v的前驱为u
            }
        }
    }
}

// 求从起点s到终点v的最短路径
void shortestPath(int s, int v) {
    if(s == v) {
        printf("%d\n", s);
        return ;
    }
    shortestPath(s, pre[v]);
    printf("%d\n", v);
}

int main(void) {

    n = 6;

    fill(G[0], G[0] + MAXV * MAXV, INF);
    G[0][1] = 1;
    G[0][3] = 4;
    G[0][4] = 4;
    G[1][3] = 2;
    G[2][5] = 1;
    G[3][2] = 2;
    G[3][4] = 3;
    G[4][5] = 3;

    Dijkstra(0);

    printf("V0到V5的最短路径为: \n");
    shortestPath(0, 5);

    return 0;
}