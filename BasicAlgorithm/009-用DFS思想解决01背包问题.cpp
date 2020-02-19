/*
    深度优先搜索(DFS): 深度优先搜索是一种枚举所有完整路径以遍历所有情况的搜索方法.
*/

/*
    使用DFS思想解决01背包问题(该方法并不是最优, 只是为了体现深搜的思想).
        背包问题: 有n件物品, 每件物品的重量为 w[i], 价值为 c[i]. 现在需要选出若干件物品放入一个容器为 V 的背包中, 使得在选入背包的物品重量和不超过
            容量 V 的前提下, 让背包中的物品价值之和最大, 求最大价值(1 <= n <= 20).
        分析: 对于第index件物品, 有两种情况, 要么选中该物品, 要么不选该物品, 根据这一点即可运用深搜的思想进行解决.
*/

#include <cstdio>

const int maxn = 30;
int n, V, maxValue = 0, w[maxn], c[maxn];

void DFS(int index, int sumW, int sumC) {
    if(index == n) {
        return ;
    }
    DFS(index + 1, sumW, sumC); // 不选index号物品, 直接处理index+1号物品
    if(sumW + w[index] <= V) { // 选index号物品(要满足物品重量和不超过容量V这一条件)
        if(sumC + c[index] > maxValue) {
            maxValue = sumC + c[index];
        }
        DFS(index + 1, sumW + w[index], sumC + c[index]); // 处理index+1号物品
    }
}

int main(void) {

    // 有5件物品, 背包容量为8
    n = 5, V = 8; 

    // 重量分别为
    w[0] = 3;
    w[1] = 5;
    w[2] = 1;
    w[3] = 2;
    w[4] = 2;

    // 价值分别为
    c[0] = 4;
    c[1] = 5;
    c[2] = 2;
    c[3] = 1;
    c[4] = 3;

    DFS(0, 0, 0);

    printf("maxValue = %d\n", maxValue);

    return 0;
}
