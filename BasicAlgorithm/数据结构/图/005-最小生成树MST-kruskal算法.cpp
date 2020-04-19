/*
    Kruskal算法采用边贪心策略解决最小生成树问题: 
        初始状态隐去图中所有边, 这样图中每个顶点都自成一个连通块, 然后执行如下步骤:
        ① 对所有边按边权从小到大进行排序;
        ② 按边权从小到大测试所有边, 如果当前测试边所连接的两个顶点不在同一连通块中, 则把这条边加入最小生成树中,
          否则, 将边舍弃(因为该边的加入会形成环);
        ③ 执行步骤②, 直到最小生成树中的边数等于总顶点数减 1 或是测试完所有边时结束. 
          如果当结束时最小生成树的边数小于总顶点数减 1, 说明该图不连通.
    需要用到并查集: 如果把每个连通块当做一个集合, 那么判断测试边的两个端点是否在不同的连通块中就可以转换为判断
        两个顶点是否在同一集合, 将测试边加入到最小生成树即把测试边的两个端点所在集合合并.
    Kruskal算法的复杂度主要来自对边的排序, 因此Kruskal算法适合在顶点数较多而边数较少的图(稀疏图)中使用.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 100; // 最大顶点数
const int MAXE = 10000; // 最大边数

struct Edge {
    int u, v; // 每条边所连接的两端顶点
    int cost; // 边权
};
Edge edge[MAXE]; // edge[] 保存所有的边
int father[MAXV]; // 并查集数组

// 排序函数, 按边权从小到大
bool cmp(Edge a, Edge b) {
    return a.cost < b.cost;
}

// 并查集查询函数, 查询集合的根结点
int findFather(int x) {
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    // 路径压缩
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }

    return x;
}

// Kruskal算法求解最小生成树, 返回边权之和
int kruskal(int n, int m) { // n为顶点数, m为边数
    int ans = 0, edgeNum = 0; // ans为边权之和, edgeNum为当前生成树边数
    sort(edge, edge + m, cmp); // 按边权从小到大对所有边进行排序
    for(int i = 0; i < n; i++) { // 初始化并查集, 顶点范围是[0, n-1]
        father[i] = i;
    }
    for(int i = 0; i < m; i++) { // 枚举所有边
        int faU = findFather(edge[i].u); // 查询当前边的两个端点所在并查集的根结点
        int faV = findFather(edge[i].v);
        if(faU != faV) { // 如果不在一个集合, 即两端点不在一个连通块中
            father[faU] = faV; // 合并集合, 即把当前边加入最小生成树中
            ans += edge[i].cost; // 增加边权
            edgeNum++; // 当前生成树边数加 1
            if(edgeNum == n - 1) { // 如果边数等于顶点数减 1, 说明最小生成树生成完毕, 结束算法
                break;
            }
        }
    }
    if(edgeNum != n - 1) { // 所有边都枚举后, 如果边数不等于顶点数减 1, 说明不是连通图
        return -1;
    } else { // 返回边权之和
        return ans;
    }
}

int main(void) {

    int n, m;
    printf("请输入顶点数、边数：\n");
    scanf("%d%d", &n, &m);
    printf("请输入每条边的两个端点编号、边权：\n");
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].cost);
    }
    
    printf("最小生成树的边权之和为 %d\n", kruskal(n, m));

    return 0;
}
