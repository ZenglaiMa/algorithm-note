/*
    拓扑排序: 就是将有向无环图(DAG)的所有顶点排成一个线性序列, 是的对图G中的任意两个顶点u、v, 如果存在边u->v,
        那么序列中 u 一定在 v 的前面, 这个序列就称为拓扑序列.
    求解步骤:
        ① 定义一个队列Q, 并把所有入度为0的结点加入队列;
        ② 取队首节点加入拓扑序列. 然后删除所有从它出发的边, 并令这些边到达的顶点的入度减 1, 如果某个顶点的入度减为 0, 则将其加入队列;
        ③ 返回执行②, 直到队列为空. 如果队列为空时入过队的结点数目恰好为图的顶点数目N, 则拓扑排序成功, 图G为有向无环图;
          否则, 拓扑排序失败, 说明图G中有环.
    应用: 判断给定的图是否为有向无环图(DAG).
*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXV = 1000;
vector<int> Adj[MAXV]; // 邻接表
int n, inDegree[MAXV]; // 顶点数、每个顶点的入度
vector<int> topo_seq; // 拓扑序列

bool topologicalSort() {
    int num = 0; // 记录加入到拓扑序列中的顶点数
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front(); // 去队首元素
        topo_seq.push_back(u); // 加入拓扑序列
        q.pop();
        for(int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i]; // u的后继结点v
            inDegree[v]--; // 顶点v的入度减1
            if(inDegree[v] == 0) { // 顶点v的入度减为0则入队
                q.push(v);
            }
        }
        // Adj[u].clear(); // 清除顶点u的出边(无必要可不写)
        num++; // 加入到拓扑序列中的顶点数加1
    }
    if(num == n) {
        return true;
    } else {
        return false;
    }
}

// 测试
int main(void) {

    n = 9;
    Adj[0].push_back(3);
    Adj[0].push_back(4);
    Adj[0].push_back(5);
    Adj[1].push_back(5);
    Adj[2].push_back(3);
    Adj[2].push_back(8);
    Adj[3].push_back(6);
    Adj[3].push_back(7);
    Adj[4].push_back(8);
    Adj[5].push_back(7);
    Adj[5].push_back(8);
    Adj[6].push_back(7);

    inDegree[0] = 0;
    inDegree[1] = 0;
    inDegree[2] = 0;
    inDegree[3] = 2;
    inDegree[4] = 1;
    inDegree[5] = 2;
    inDegree[6] = 1;
    inDegree[7] = 3;
    inDegree[8] = 3;

    printf("是否是DAG:%d\n拓扑序列为\n", topologicalSort());
    for(int i = 0; i < n; i++) {
        printf("%d ", topo_seq[i]);
    }
    printf("\n");

    return 0;
}
