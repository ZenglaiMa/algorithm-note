/*
    prim算法解决最小生成树(MST)问题, 即在一个给定的无向图G(V, E)中求一棵生成树T, 使得这棵树拥有图G中的所有顶点,
        且所有边都来自图G中的边, 并且满足整棵树的边权之和最小.
    prim算法与Dijkstra算法思想基本相同, 只是d[]的含义不同: Dijkstra算法中d[]表示起点s到达各顶点Vi的最短距离,
        而prim算法中d[]表示顶点Vi与集合S(已被访问的顶点的集合)的最短距离.
    prim算法适用在图的顶点数量较少而边数较多的情况下(即稠密图)来求解最小生成树问题.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 1000; // 最大顶点数
const int INF = 0x3fffffff; // INF表示无穷
int G[MAXV][MAXV], n; // 邻接矩阵表示的图, 图的顶点个数
int d[MAXV]; // 表示某顶点与集合S的最短距离
bool vis[MAXV] = { false }; // 标记某顶点是否被访问

// prim算法求解最小生成树, 返回最小生成树的边权之和
int prim(int s) { // 指定起点s
    fill(d, d + MAXV, INF);
    d[s] = 0; // s号顶点到集合S的距离为0, 其他都为INF
    int ans = 0; // 存放最小生成树的边权之和
    for(int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if(u == -1) { // 找不到小于INF的d[u], 说明剩下的顶点和集合S不连通
            return -1;
        }
        vis[u] = true;
        ans += d[u]; // 将与集合S距离最小的边加入最小生成树
        for(int v = 0; v < n; v++) {
            if(!vis[v] && G[u][v] != INF && G[u][v] < d[v]) {
                d[v] = G[u][v]; // 如果以u为中介点时可以使v离集合S更近, 则更新d[v]
            }
        }
    }
    
    return ans; // 返回最小生成树的边权之和
}

int main(void) {

    fill(G[0], G[0] + MAXV * MAXV, INF);

    n = 6;
    G[0][4] = G[4][0] = 1;
    G[0][5] = G[5][0] = 2;
    G[0][1] = G[1][0] = 4;
    G[4][5] = G[5][4] = 3;
    G[1][5] = G[5][1] = 3;
    G[3][4] = G[4][3] = 4;
    G[3][5] = G[5][3] = 5;
    G[2][5] = G[5][2] = 5;
    G[1][2] = G[2][1] = 6;
    G[2][3] = G[3][2] = 6;

    printf("最小生成树边权之和为 %d\n", prim(0));

    return 0;
}
