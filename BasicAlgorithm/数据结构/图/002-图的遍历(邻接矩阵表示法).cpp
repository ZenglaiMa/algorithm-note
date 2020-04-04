/*
    以邻接矩阵形式存储图时, 图的DFS和BFS.
*/

#include <queue>
using namespace std;

const int maxv = 1000; // 最大顶点数
int G[maxv][maxv] = { 0 }; // 邻接矩阵表示的图, 0表示两顶点不相连, 1表示相连
bool vis[maxv] = { false }; // 标志某顶点 i 是否已被访问, DFS时使用, 初值为 false, vis[i]==true 表示顶点 i 已被访问
bool inq[maxv] = { false }; // 标志某顶点 i 是否已入过队, BSF时使用, 初值为 false, inq[i]==true 表示顶点 i 已入过队

// 深度优先遍历DFS
void DFS(int u, int n, int depth) { // u为当前访问的顶点标号, n为图的顶点个数, depth为深度
    vis[u] = true;
    /*如果需要对 u 进行一些操作, 可以在这里进行*/
    for(int v = 0; v < n; v++) {
        if(!vis[v] && G[u][v] != 0) {
            DFS(v, n, depth + 1);
        }
    }
}

void DFSTrave(int n) {
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            DFS(i, n, 1);
        }
    }
}

// 广度优先遍历BFS
void BFS(int u, int n) { // u为当前访问的顶点标号, n为图的顶点个数
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        /*如果需要对 top 进行一些操作, 可以在这里进行*/
        for(int v = 0; v < n; v++) {
            if(!inq[v] && G[top][v] != 0) {
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

void BFSTrave(int n) {
    for(int i = 0; i < n; i++) {
        if(!inq[i]) {
            BFS(i, n);
        }
    }
}
