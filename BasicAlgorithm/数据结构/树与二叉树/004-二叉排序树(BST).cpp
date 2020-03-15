/**************************************************************************************************************************
*    二叉查找树(BST), 又称二叉排序树, 二叉搜索树:                                                                            *
*        ① 要么BST是一颗空树;                                                                                               *
*        ② 要么BST由根结点、左子树和右子树组成, 其中左子树和右子树都是BST, 且左子树上所有结点数据域均小于或等于根结点数据域,      *
*          右子树上所有结点数据域均大于根结点数据域.                                                                          *
*        例:                                                                                                               *
*                5                                                                                                         *
*               / \                                                                                                        *
*              3   7                                                                                                       *
*             /\   /\                                                                                                      *
*            2  4  6 8                                                                                                     *
*     二叉查找树的一个重要性质: 对BST进行中序遍历, 得到的结果是有序的.                                                         *
**************************************************************************************************************************/

#include <cstdio>
#include <cstdlib>

#define ElemType int

typedef struct BTNode {
    ElemType data;
    struct BTNode * lchild;
    struct BTNode * rchild;
} BTNode, *BTree;

// BST的查找: 在BST中查找给定的数据x, 查找成功返回true, 否则返回false.
// n个结点的BST查找的时间复杂度为 O(log2n), 类似于折半查找; 当BST完全不平衡时退化为 O(n), 即顺序查找.
bool search(BTree root, ElemType x) {
    if(!root) {
        return false;
    }

    if(root->data == x) {
        return true;
    } else if(root->data < x) {
        search(root->rchild, x);
    } else {
        search(root->lchild, x);
    }
}

// BST的插入: 在BST中插入给定的数据x, 插入位置即为查找失败的位置, 当查找成功时无需插入.
// 显然插入是基于查找过程的, 因此对于一棵有n个结点的BST插入结点的时间复杂度也为 O(log2n).
void insert(BTree *root, ElemType x) {
    if(!(*root)) { // 查找失败, 在该位置插入
        (*root) = (BTree)malloc(sizeof(BTNode));
        (*root)->data = x;
        (*root)->lchild = NULL;
        (*root)->rchild = NULL;
    }

    if((*root)->data == x) { // 查找成功, 说明数据存在, 无需插入
        return ;
    } else if((*root)->data < x) {
        insert(&((*root)->rchild), x);
    } else {
        insert(&((*root)->lchild), x);
    }
}

// BST的建立: 就是在一棵空树中先后插入结点的过程, 建树完成后返回树根结点
BTree create(ElemType data[], int n) {
    BTree root = NULL;
    for(int i = 0; i < n; i++) {
        insert(&root, data[i]);
    }

    return root;
}

// BST的删除(*): 删除以root为根结点的BST中权值为x的结点, 删除失败返回false, 成功返回true, 分析思路详见算法笔记P313.
// 辅助函数①: BTree findMax(BTree root) 在以root为根结点的BST中寻找最大权值结点;
// 辅助函数②: BTree findMin(BTree root) 在以root为根结点的BST中寻找最小权值结点.
BTree findMax(BTree root) {
    while(root->rchild) {
        root = root->rchild; // 不断往右找
    }

    return root;
}

BTree findMin(BTree root) {
    while(root->lchild) {
        root = root->lchild; // 不断往左找
    }

    return root;
}

bool deleteNode(BTree *root, ElemType x) {
    if(!(*root)) { // 要删除的结点不存在
        return false;
    }

    if((*root)->data == x) { // 找到欲删除结点
        if((*root)->lchild == NULL && (*root)->rchild == NULL) { // 欲删除结点为叶子结点, 直接删除即可
            *root = NULL; // 将*root地址赋为NULL, 其父结点就引用不到它了
            free(*root); // 释放*root空间
            return true;
        } else if((*root)->lchild) { // 如果左子树存在(优先通过前驱覆盖, 前驱不存在再通过后继覆盖)
            BTree pre = findMax((*root)->lchild); // 找root前驱
            (*root)->data = pre->data; // 用前驱覆盖root
            deleteNode(&((*root)->lchild), pre->data); // 在左子树中删除前驱结点
        } else { // 如果左子树不存在且右子树存在
            BTree next = findMin((*root)->rchild); // 找root后继
            (*root)->data = next->data; // 用后继覆盖root
            deleteNode(&((*root)->rchild), next->data); // 在右子树中删除后继结点
        }
    } else if((*root)->data < x) {
        deleteNode(&((*root)->rchild), x);
    } else {
        deleteNode(&((*root)->lchild), x);
    }
}

/***************************************************************************************************************************************************
*   优化: deleteNode函数可不用递归实现, 现提供这样一种思路:                                                                                           *
*       我们可以在在找到欲删除结点root的后继结点next后, 不进行递归, 而是采用如下手段直接删除该后继: 假设next结点的父结点为S, 显然结点next必是结点S的左孩子, *
*       并且next结点一定没有左子树, 这样便可以直接把next的右子树直接代替结点next成为S的左子树, 这样就删去了结点next. 前驱同理. 这样优化时需要在结点定义中   *
*       额外记录每个结点的父结点的地址.                                                                                                              *
****************************************************************************************************************************************************/

// BST重要性质: 中序遍历BST得到的序列有序.
void inOrder(BTree root) {
    if(!root) {
        return ;
    }

    inOrder(root->lchild);
    printf("%d\n", root->data);
    inOrder(root->rchild);
}
