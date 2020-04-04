/*
    以邻接表形式存储图时, 图的DFS和BFS.
*/

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxv = 1000; // 最大顶点数
vector<int> Adj[maxv]; // 图G的邻接表
bool vis[maxv] = { false }; // 标志某顶点 i 是否已被访问, DFS时使用, 初值为 false, vis[i]==true 表示顶点 i 已被访问
bool inq[maxv] = { false }; // 标志某顶点 i 是否已入过队, BSF时使用, 初值为 false, inq[i]==true 表示顶点 i 已入过队

// 深度优先搜索(DFS). 注意, 在DFS中, 如果给定的图是一个连通图, 则只需要一次DFS就能完成遍历.
void DFS(int u, int depth) { // u为当前访问结点, depth 为深度
    vis[u] = true;
    /*如果需要对 u 进行一些操作, 可以在此处进行*/
    for(int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        if(!vis[v]) {
            DFS(v, depth + 1);
        }
    }
}

void DFSTrave(int n) { // n 为图的顶点个数
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            DFS(i, 1);
        }
    }
}

// 广度优先搜索(BFS)
void BFS(int u) { // BFS单个连通块
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        /*如果需要对 top 进行一些操作, 可以在此处进行*/
        for(int i = 0; i < Adj[top].size(); i++) {
            int v = Adj[top][i];
            if(!inq[v]) {
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

void BFSTrave(int n) { // n 为图的顶点个数
    for(int i = 0; i < n; i++) {
        if(!inq[i]) {
            BFS(i);
        }
    }
}
