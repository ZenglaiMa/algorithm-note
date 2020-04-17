// Dijkstra算法解决图的单源最短路径问题(邻接表法表示图).
// 单源最短路径是指从给定起点到其他所有顶点的最短路径.

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXV = 1000; // 图的最大顶点数
const int INF = 0x3fffffff; // 设INF是一个很大的数, 表示两顶点不可达

struct Node {
    int v; // 顶点编号
    int weight; // 边权
    Node(int _v, int _weight) : v(_v), weight(_weight) {}
};

vector<Node> Adj[MAXV]; // 图
int n; // 图的顶点数
int d[MAXV]; // 起点到达各点的最短路径
bool vis[MAXV] = { false }; // 标记某顶点是否被访问, vis[i] = true 表示顶点i被访问

void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) {
            return ;
        }
        vis[u] = true;
        for(int j = 0; j < Adj[u].size(); j++) { // 此处与邻接矩阵不同, 因为通过邻接表可直接获得u能到达的顶点
            int v = Adj[u][j].v;
            if(!vis[v] && d[u] + Adj[u][j].weight < d[v]) {
                d[v] = d[u] + Adj[u][j].weight;
            }
        }
    }
}

int main(void) {

    n = 6;
    Adj[0].push_back(Node(1, 1));
    Adj[0].push_back(Node(3, 4));
    Adj[0].push_back(Node(4, 4));
    Adj[1].push_back(Node(3, 2));
    Adj[2].push_back(Node(5, 1));
    Adj[3].push_back(Node(2, 2));
    Adj[3].push_back(Node(4, 3));
    Adj[4].push_back(Node(5, 3));

    Dijkstra(0);

    for(int i = 0; i < n; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");

    return 0;
}
