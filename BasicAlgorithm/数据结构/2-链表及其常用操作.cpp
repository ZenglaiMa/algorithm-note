#include <cstdio>
#include <cstdlib>

#define ElemType int

typedef struct node {
    ElemType data;
    struct node * next;
} LNode, *LinkList;

// 初始化链表(带头结点)
bool InitList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(LNode));
    if(*L == NULL) {
        return false;
    }
    (*L)->next = NULL;

    return true;
}

// 销毁链表
void DestroyList(LinkList *L) {
    LinkList temp;
    while(*L) {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

// 判断链表是否为空
bool isEmpty(LinkList L) {
    if(!(L->next))
        return true;

    return false;
}

// 向链表中插入元素: 在 i 位置插入元素 e, 其中 1 <= i <= L.length() + 1
bool ListInsert(LinkList L, int i, ElemType e) {
    LinkList p = L, s;
    int j = 0;

    while(p && j < i - 1) { // 找到待插入位置的前一个结点
        p = p->next;
        j++;
    }
    if(!p || j > i - 1) {
        return false;
    }

    s = (LinkList)malloc(sizeof(LNode));
    if(s == NULL) {
        return false;
    }

    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}

// 删除链表的第 i 个结点, 将删除的结点的data域放在e中, 其中 1 <= i <= L.length()
bool ListDelete(LinkList L, int i, ElemType &e) {
    LinkList p = L, q;
    int j = 0;

    while(p->next && j < i - 1) { // 找到待删除位置的前一个结点
        p = p->next;
        j++;
    }
    if(!(p->next) || j > i - 1) {
        return false;
    }

    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);

    return true;
}

// 删除data域为e的所有结点
void ListDelete(LinkList L, ElemType e) {
    LinkList p = L->next, pre = L;
    while(p) {
        if(p->data == e) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

// 得到链表的第 i 个元素, 将其放入 e 中, 1 <= i <= L.length()
bool GetElem(LinkList L, int i, ElemType &e) {
    LinkList p = L->next;
    int j = 1;

    while(p && j < i) {
        p = p->next;
        j++;
    }
    if(!p || j > i) {
        return false;
    }
    e = p->data;

    return true;
}


// 遍历链表
void ListTraverse(LinkList L) {
    LinkList p = L->next;
    while(p) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

// 统计链表长度(元素个数)
int ListLength(LinkList L) {
    LinkList p = L->next;
    int length = 0;
    while(p) {
        length++;
        p = p->next;
    }

    return length;
}

// 链表逆置
void reverse(LinkList L) {
    LinkList p = L->next, q = NULL;
    while(p) {
        LinkList temp = p;
        p = p->next;
        temp->next = q;
        q = temp;
    }
    L->next = q;
}

// 单链表冒泡排序
void ListSort(LinkList L) {
    if(L->next == NULL)
        return ;
    
    LinkList end = NULL;
    LinkList pre, cur, next, temp;

    while(L->next != end) { // 从链表头开始将最大值往后沉
        pre = L;
        cur = pre->next;
        next = cur->next;
        while(next != end) {
            if(cur->data > next->data) {
                cur->next = next->next;
                pre->next = next;
                next->next = cur;
                temp = next;
                next = cur;
                cur = temp;
            }
            pre = pre->next;
            cur = cur->next;
            next = next->next;
        }
        end = cur;
    }
}