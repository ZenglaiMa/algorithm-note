/*
    PAT A1052 Linked List Sorting: 算法笔记P265.
    题目大意: 给出N个结点的地址, 数据域和指针域, 然后给出链表的首地址, 要求把在这个链表上的结点按data值从小到大输出.
    思路: 算法笔记P263-P264提供该类题目的完整思路.
    注意: 输入的结点可能是无效结点, 即不在链表上的结点, 排序和统计链表结点个数时要去除这些无效结点.
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

typedef struct {
    int address;
    int data;
    int next;
    bool flag; // 标志是否为无效结点
} SeqList;

SeqList node[maxn];

bool cmp(SeqList a, SeqList b) {
    if(a.flag == false || b.flag == false) { // 将无效结点排在最后边
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}

int main(void) {

    for(int i = 0; i < maxn; i++) { // 初始化flag域为false
        node[i].flag = false;
    }

    int n, s;
    scanf("%d%d", &n, &s);
    int address, data, next;
    for(int i = 0; i < n; i++) { // 构造链表
        scanf("%d%d%d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    
    int count = 0;
    for(int p = s; p != -1; p = node[p].next) { // 标记有效结点并统计其个数
        node[p].flag = true;
        count++;
    }

    if(count == 0) { // 无有效结点
        printf("0 -1\n");
    } else {
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", count, node[0].address); // 输出有效结点个数和首结点地址
        for(int i = 0; i < count; i++) {
            if(i != count - 1) {
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address); // 注意此时下一个结点的地址即为 node[i + 1].address
            } else {
                printf("%05d %d -1\n", node[i].address, node[i].data);
            }
        }
    }
    
    return 0;
}

