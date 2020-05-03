/*
    DAG最长路, 即AOE网的关键路径: 给定一个有向无环图, 求解整个图的所有路径中权值之和最大的那条.
    思路: dp[i] 表示从 i 号顶点出发能获得的最长路径长度, dp[i] = max{dp[j] + length[i->j]}
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 1000;
const int INF = 0x3fffffff;
int G[MAXV][MAXV], n;
int dp[MAXV]; // dp[i] 表示从 i 号顶点出发能获得的最长路径长度, 其中最大的一个即为图的最长路径长度
int choice[MAXV]; // 记录最长路径上顶点的后继顶点

// 求解 dp[i]
int DP(int i) {
    if(dp[i] > 0) { // dp[i]已经得到
        return dp[i];
    }
    for(int j = 0; j < n; j++) { // 遍历i的所有出边
        if(G[i][j] != INF) {
            int temp = DP(j) + G[i][j]; // dp[i] = max{dp[j] + length[i->j]}
            if(temp > dp[i]) {
                dp[i] = temp;
                choice[i] = j; // i 的后继为 j
            }
        }
    }

    return dp[i];
}

// 打印最长路径
void printPath(int i) {
    printf("%d", i);
    while(choice[i] != -1) {
        i = choice[i];
        printf("->%d", i);
    }
}

int main(void) {

    fill(G[0], G[0] + MAXV * MAXV, INF); // 初始化图G
    fill(dp, dp + MAXV, 0); // 初始化dp[]为0
    fill(choice, choice + MAXV, -1); // 初始化choice[]为-1

    scanf("%d", &n); // 输入顶点数
    int m;
    scanf("%d", &m); // 输入边数
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w); // 输入 u->v 权值为 w
        G[u][v] = w;
    }

    for(int i = 0; i < n; i++) { // 求 dp[i]
        dp[i] = DP(i);
    }

    int k = 0;
    for(int i = 0; i < n; i++) { // 所有 dp[i] 中最大的那个即为最长路径长度
        if(dp[i] > dp[k]) {
            k = i;
        }
    }
    printf("最长路径长度 = %d\n", dp[k]);
    printf("最长路径为: ");
    printPath(k);

    printf("\n");

    return 0;
}
