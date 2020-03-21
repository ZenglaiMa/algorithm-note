/*
    平衡二叉树(AVL树)
        如果为我们使用序列{1, 2, 3, 4, 5, 6...}去构建二叉排序树, 那么构建出来的二叉排序树是链式的, 这样就起不到使用二叉排序树来进行数据查询优化的目的.
        于是引入平衡二叉树, 使树的高度在每次插入后仍然保持 O(logn) 的级别, 这样能让查询操作仍然保持 O(logn) 的时间复杂度. 所谓平衡, 是指对AVL树的
        每一个结点来说, 其左右子树的高度之差的绝对值不超过 1, 左右子树的高度之差称为该结点的平衡因子.
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ElemType int

typedef struct BTNode {
    ElemType data;
    int height; // 记录以该结点为根结点的子树的高度
    struct BTNode * lchild;
    struct BTNode * rchild;
} BTNode, *AVL;

// 建立新结点
AVL createNode(ElemType data) {
    AVL root = (AVL)malloc(sizeof(BTNode));
    root->data = data;
    root->height = 1;
    root->lchild = NULL;
    root->rchild = NULL;

    return root;
}

// 获取以root为根结点的子树的高度
int getHeight(AVL root) {
    if(!root) {
        return 0;
    }

    return root->height;
}

// 获取root结点的平衡因子
int getBalanceFactor(AVL root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

// 更新以root为根结点的子树的高度: 结点root所在子树的高度等于其左子树高度与右子树高度的较大值加 1
void updateHeight(AVL root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

/*********************************************************************************
 * AVL树的查找操作: 因为AVL树是一棵二叉查找树, 所以AVL的查找操作和BST的查找操作相同   *
 *********************************************************************************/
bool search(AVL root, ElemType x) {
    if(!root) {
        return false;
    }

    if(root->data == x) {
        return true;
    } else if(root->data > x) {
        search(root->lchild, x);
    } else {
        search(root->rchild, x);
    }
}

/*******************************************************************************************************
 *           AVL树的插入的四种情况(BF表示平衡因子)                                                       *
 *       树型                  判定条件                         调整方法                                 *
 *       LL        BF(root)=2, BF(root->lchild)=1           对root进行右旋                              *
 *       LR        BF(root)=2, BF(root->lchild)=-1          先对root->lchild进行左旋, 再对root进行右旋   *
 *       RR        BF(root)=-2, BF(root->rchild)=-1         对root进行左旋                              *
 *       RL        BF(root)=-2, BF(root->rchild)=1          先对root->rchild进行右旋, 再对root进行左旋   *
 *******************************************************************************************************/

// 左旋
void leftRotate(AVL *root) {
    AVL temp = (*root)->rchild;
    (*root)->rchild = temp->lchild;
    temp->lchild = *root;
    updateHeight(*root);
    updateHeight(temp);

    (*root) = temp;
}

// 右旋
void rightRotate(AVL *root) {
    AVL temp = (*root)->lchild;
    (*root)->lchild = temp->rchild;
    temp->rchild = *root;
    updateHeight(*root);
    updateHeight(temp);

    (*root) = temp;
}

// 在AVL树中插入权值为x的结点
void insert(AVL *root, ElemType x) {
    if(!(*root)) {
        (*root) = createNode(x);
        return ;
    }

    if((*root)->data < x) {
        insert(&((*root)->rchild), x);
        updateHeight(*root);
        if(getBalanceFactor(*root) == -2) {
            if(getBalanceFactor((*root)->rchild) == -1) { // RR型
                leftRotate(root);
            } else if(getBalanceFactor((*root)->rchild) == 1) { // RL型
                rightRotate(&((*root)->rchild));
                leftRotate(root);
            }
        }
    } else {
        insert(&((*root)->lchild), x);
        updateHeight(*root);
        if(getBalanceFactor(*root) == 2) {
            if(getBalanceFactor((*root)->lchild) == 1) { // LL型
                rightRotate(root);
            } else if(getBalanceFactor((*root)->lchild) == -1) { // LR型
                leftRotate(&((*root)->lchild));
                rightRotate(root);
            }
        }
    }
}

/****************************************
   AVL树的建立, 就是插入n个结点的过程     *
*****************************************/
AVL createAVL(ElemType data[], int n) {
    AVL root = NULL;
    for(int i = 0; i < n; i++) {
        insert(&root, data[i]);
    }

    return root;
}

// 中序遍历AVL树序列有序
void inOrder(AVL root) {
    if(!root) {
        return ;
    }

    inOrder(root->lchild);
    printf("%d\n", root->data);
    inOrder(root->rchild);
}
