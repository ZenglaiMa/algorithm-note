// Dijkstra算法解决图的单源最短路径问题(邻接矩阵法表示图, G[i][j]表示顶点i和顶点j之间路径的权值, INF表示不可达).
// 单源最短路径是指从给定起点到其他所有顶点的最短路径.

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 1000; // 图的最大顶点数
const int INF = 0x3fffffff; // 设INF是一个很大的数, 表示两顶点不可达
int n; // 图的顶点数
int G[MAXV][MAXV]; // 图
int d[MAXV]; // 起点到达各点的最短路径
bool vis[MAXV] = { false }; // 标记某顶点是否被访问, vis[i] = true 表示顶点i被访问

void Dijkstra(int s) { // s为起点
    fill(d, d + MAXV, INF); // 初始化d[]为INF
    d[s] = 0; // 起点s到自身的距离为0
    for(int i = 0; i < n; i++) { // 循环 n 次
        int u = -1, MIN = INF; // 寻找使d[u]最小且还未被访问过的顶点的标号 u
        for(int j = 0; j < n; j++) {
            if(!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) { // 没找到这样的顶点, 说明剩下的顶点和起点s不连通
            return ;
        }
        vis[u] = true; // 访问u
        for(int v = 0; v < n; v++) { // 优化以u为中介点使s到v的最短距离d[v]更优
            if(!vis[v] && G[u][v] != INF && G[u][v] + d[u] < d[v]) {
                d[v] = G[u][v] + d[u];
            }
        }
    }
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

    for(int i = 0; i < n; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");

    return 0;
}
