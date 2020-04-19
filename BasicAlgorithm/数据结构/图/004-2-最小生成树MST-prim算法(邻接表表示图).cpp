#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 1000;
const int INF = 0x3fffffff;

struct Node {
    int v; // 顶点
    int dis; // 边权
    Node (int _v, int _dis) : v(_v), dis(_dis) {}
};
vector<Node> Adj[MAXV];
int n;
int d[MAXV];
bool vis[MAXV] = { false };

int prim(int s) {
    fill(d, d + MAXV, INF);
    d[s] = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if(u == -1) {
            return -1;
        }
        vis[u] = true;
        ans += d[u];
        for(int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            if(!vis[v] && Adj[u][j].dis < d[v]) {
                d[v] = Adj[u][j].dis;
            }
        }
    }

    return ans;
}

int main(void) {

    n = 6;
    Adj[0].push_back(Node(4, 1));
    Adj[0].push_back(Node(1, 4));
    Adj[0].push_back(Node(5, 2));
    Adj[1].push_back(Node(0, 4));
    Adj[1].push_back(Node(5, 3));
    Adj[1].push_back(Node(2, 6));
    Adj[2].push_back(Node(1, 6));
    Adj[2].push_back(Node(5, 5));
    Adj[2].push_back(Node(3, 6));
    Adj[3].push_back(Node(4, 4));
    Adj[3].push_back(Node(5, 5));
    Adj[3].push_back(Node(2, 6));
    Adj[4].push_back(Node(0, 1));
    Adj[4].push_back(Node(5, 3));
    Adj[4].push_back(Node(3, 4));
    Adj[5].push_back(Node(0, 2));
    Adj[5].push_back(Node(1, 3));
    Adj[5].push_back(Node(2, 5));
    Adj[5].push_back(Node(3, 5));
    Adj[5].push_back(Node(4, 3));

    printf("最小生成树边权之和为 %d\n", prim(0));

    return 0;
}
