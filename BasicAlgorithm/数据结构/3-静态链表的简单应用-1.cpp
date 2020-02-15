/*
    PAT A1032 Sharing: 算法笔记P261
    题目大意: 给出两条链表的首地址以及若干结点的地址、数据、下一个结点的地址, 求两条链表的首个共用结点的地址, 若无共用结点, 返回 -1.
    思路: 遍历第一条链表, 将第一条链表的所有结点的flag域值为true, 然后遍历第二条链表, 判断每一个结点的flag, 如果为ture, 则该结点地址即为所求,
        若没出现flag为true的结点, 则说明两条链表无共用结点, 返回 -1.
*/
#include <cstdio>

const int maxn = 100010;

typedef struct {
    char data;
    int next;
    bool flag; // 标志结点是否在链表中出现过, 出现过为true, 否则为false.
} SeqList;

SeqList node[maxn];

int main(void) {

    for(int i = 0; i < maxn; i++) { // 初始化flag域为false
        node[i].flag = false;
    }

    int s1, s2, n;
    scanf("%d%d%d", &s1, &s2, &n);
    int address, next;
    char data;
    for(int i = 0; i < n; i++) { // 构造链表
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }

    int p;
    for(p = s1; p != -1; p = node[p].next) { // 遍历第一条链表, 置flag为true
        node[p].flag = true;
    }
    for(p = s2; p != -1; p = node[p].next) { // 遍历第二条链表, 寻找flag为true的那个结点
        if(node[p].flag) {
            break;
        }
    }
    if(p == -1) { // 没找到, 说明两条链表无共用结点, 输出 -1
        printf("-1\n");
    } else { // 找到了, 输出该结点的地址
        printf("%05d\n", p);
    }

    return 0;
}
