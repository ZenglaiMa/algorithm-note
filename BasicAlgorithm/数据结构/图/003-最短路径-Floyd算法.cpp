/*
    Floyd算法: 即弗洛伊德算法, 用来解决全源最短路径问题, 即对给定的图G(V,E), 求任意两顶点 u, v 之间的最短路径长度,
        时间复杂度为 O(n^3).
    思想: 如果存在顶点 k, 使得以 k 作为中介点时顶点 i 和顶点 j 的当前最短距离缩短, 则使用顶点 k 作为顶点 i 和顶点 j 的中介点,
        即当 dis[i][k] + dis[k][j] < dis[i][j] 时, 令 dis[i][j] = dis[i][k] + dis[k][j]. (dis[i][j]表示从顶点i到顶点j的最短距离.)
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 200; // 最大顶点数, 限制在200以内, 否则时间复杂度过大
const int INF = 0x3fffffff;
int dis[MAXV][MAXV], n; // dis[i][j]表示从顶点 i 到顶点 j 的最短距离, n 为顶点数

void floyd() {
    for(int i = 0; i < n; i++) {
        dis[i][i] = 0; // 顶点 i 到顶点 i (它本身)的距离为0
    }

    for(int k = 0; k < n; k++) { // 枚举顶点 k
        for(int i = 0; i < n; i++) { // 以 k 为中介点, 枚举所有顶点对(i, j)
            for(int j = 0; j < n; j++) {
                if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main(void) {

    fill(dis[0], dis[0] + MAXV * MAXV, INF);

    n = 6;
    dis[0][1] = 1;
    dis[0][3] = 4;
    dis[0][4] = 4;
    dis[1][3] = 2;
    dis[2][5] = 1;
    dis[3][2] = 2;
    dis[3][4] = 3;
    dis[4][5] = 3;

    floyd();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dis[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%3d ", dis[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
