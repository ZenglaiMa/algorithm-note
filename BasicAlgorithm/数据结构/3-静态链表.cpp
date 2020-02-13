/*
    静态链表: 对应有些问题来说, 结点的地址是比较小的整数, 这样就没必要去建立动态链表, 而应使用方便得多的静态链表.
    原理: 静态链表的实现原理是 hash, 即通过建立一个结构体数组, 并令数组的下标直接表示结点的地址, 来达到
        直接访问数组中的元素就能访问结点的效果. 另外, 静态链表是不需要头结点的.
*/

#define ElemType int
const int size = 100010;

typedef struct {
    ElemType data;
    int next;
} SeqList;

SeqList node[size];