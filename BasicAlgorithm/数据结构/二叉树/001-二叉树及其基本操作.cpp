/*
    二叉树及其常用操作:
        1. 二叉树定义: 
            ① 要么二叉树无结点, 是一棵空树;
            ② 要么二叉树由根节点, 左子树, 右子树组成, 且左子树和右子树都是二叉树.
        2. 二叉树的性质:
            ① 在二叉树的第 i 层上最多有 2^(i-1) 个结点;
            ② 深度为 k 的二叉树最多有 2^k-1 个结点(此时称为满二叉树); 
            ③ 对于任意一棵二叉树, 若其叶子数为 n0, 度为2的结点数为 n2, 则 n0 = n2 + 1;
            ④ 具有 n 个结点的完全二叉树的深度为 floor(log2n)+1;
            ⑤ 对于一棵有 n 个结点的完全二叉树的结点按层序编号(从1到n), 对任一结点 i, 有:
                a. 若 i=1, 则结点 i 是二叉树的根, 无双亲; 若 i>1, 则其双亲结点是 i/2;
                b. 若 2i>n, 则结点 i 为叶子结点, 无左孩子; 否则其左孩子结点为 2i;
                c. 若 2i+1>n, 则结点 i 无右孩子; 否则其右孩子结点为 2i+1.
*/

#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

#define ElemType int

// 二叉树的存储
typedef struct BiTNode {
    ElemType data;
    struct BiTNode * lchild;
    struct BiTNode * rchild;
} BiTNode, *BiTree;

// 二叉树的先序遍历(DFS)
void preOrder(BiTree root) {
    if(!root) {
        return ;
    }

    printf("%d\n", root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

// 二叉树的中序遍历(DFS)
void inOrder(BiTree root) {
    if(!root) {
        return ;
    }

    inOrder(root->lchild);
    printf("%d\n", root->data);
    inOrder(root->rchild);
}

// 二叉树的后序遍历(DFS)
void postOrder(BiTree root) {
    if(!root) {
        return ;
    }

    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d\n", root->data);
}

// 二叉树的层序遍历(BFS)
void layerOrder(BiTree root) {
    if(!root) {
        return ;
    }

    queue<BiTree> q;
    q.push(root);
    while(!q.empty()) {
        BiTree top = q.front();
        q.pop();
        printf("%d\n", top->data);
        if(top->lchild != NULL) {
            q.push(top->lchild);
        }
        if(top->rchild != NULL) {
            q.push(top->rchild);
        }
    }
}

// 求整个二叉树的深度(后序): max(左子树深度, 右子树深度) + 1(根)
int BiTreeDepth(BiTree root) {
    int depth, leftDepth, rightDepth;
    if(!root) {
        depth = 0;
    } else {
        leftDepth = BiTreeDepth(root->lchild);
        rightDepth = BiTreeDepth(root->rchild);
        depth = max(leftDepth, rightDepth) + 1;
    }

    return depth;
}

// 给定一棵二叉树的先序序列和中序序列, 重构这棵二叉树, 函数返回重构完成的二叉树(算法笔记P204~P295)
const int maxn = 100;
ElemType pre[maxn], in[maxn];

BiTree create(int preL, int preR, int inL, int inR) { // 先序序列区间为[preL, preR], 中序序列区间为[inL, inR]
    if(preL > preR) { // 先序序列长度小于0时直接返回NULL
        return NULL;
    }

    BiTree root = (BiTree)malloc(sizeof(BiTNode)); // 构造新结点来存放根结点
    if(!root) {
        return NULL;
    }
    root->data = pre[preL]; // 根结点的数据为先序序列的第一个元素值

    int k;
    for(k = inL; k <= inR; k++) { // 在中序序列中寻找 in[k] = pre[preL] 的结点, k 位置的这个结点将二叉树分为左右子树
        if(in[k] == pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL; // 左子树结点的个数

    // 构建左子树, 左子树的先序序列区间为[preL + 1, preL + numLeft], 中序序列区间为[inL, k - 1]
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    // 构建右子树, 右子树的先序序列区间为[preL + numLeft + 1, preR], 中序序列区间为[k + 1, inR]
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    
    return root;
}