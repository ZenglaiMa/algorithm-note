/*
    有一种常见的问题可以用DFS思想解决: 给定一个序列, 枚举这个序列中所有子序列(可以不连续). 例如对序列 {1,2,3} 来说, 它的所有子序列为 {1}, {2}, {3},
        {1,2}, {1,3}, {2,3}, {1,2,3}. 枚举所有子序列的目的就是可以从中选出一个"最优"的子序列, 使它的某个特征是所有子序列中最优的. 这类问题也等价于:
        枚举从N个整数中选择K个数的所有方案.

    一个具体的问题: 给定N个整数, 从中选择K个数, 使得这K个数之和恰好等于一个给定的整数 X; 如果有多种方案, 选择它们中元素平方和最大的一个.
        例如, 从序列 {2,3,3,4} 中选择2个数, 使它们的和为6, 显然有两种方案 {2,4} 和 {3,3}, 其中平方和最大的方案是 {2,4}.
    思路: 对于第index号的数, 有两种方案, 要么选择它, 要么不选择它, 这样就能根据DFS思想去解决.
*/

#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 30;
int n, k, x, maxSqu = 0, A[maxn];
vector<int> ans, temp;

void DFS(int index, int nowK, int sum, int squ) {
    if(nowK == k && sum == x) { // 边界: 已经选了k个数并且和为x, 即已经找到了一组方案
        if(squ > maxSqu) { // 选择平方和最大的一组方案
            maxSqu = squ;
            ans = temp;
        }
        return ;
    }
    if(index == n || nowK > k || sum > x) // 边界: 已经处理完了n个数, 或者选的数的个数超过了k, 或者和超过了x
        return ;

    DFS(index + 1, nowK, sum, squ); // 不选第 index 号的数, 直接处理 index+1 号的数

    temp.push_back(A[index]); // 选择第 index 号的数
    DFS(index + 1, nowK + 1, sum + A[index], squ + A[index] * A[index]); // 处理第 index+1 号的数
    temp.pop_back();
}


int main(void) {

    // 从5个数中选3个数, 使得这3个数之和为8
    n = 5, k = 3, x = 8; 
    // 4个数分别为
    A[0] = 2;
    A[1] = 3;
    A[2] = 3;
    A[3] = 4;
    A[4] = 2;

    DFS(0, 0, 0, 0);
    
    printf("最优方案为:\n");
    for(int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
