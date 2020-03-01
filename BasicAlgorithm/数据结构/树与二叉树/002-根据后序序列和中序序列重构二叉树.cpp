/*
    算法笔记P296: PAT-A1020: 给出一棵二叉树的后序序列和中序序列, 求这棵二叉树的层序遍历序列. (数据域为 int 类型)
    思路: 参照文件 "001-二叉树及其基本操作.cpp" 的类似问题.
*/

#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

typedef struct BiTNode {
    int data;
    struct BiTNode * lchild;
    struct BiTNode * rchild;
} BiTNode, *BiTree;

const int maxn = 100;
int post[maxn], in[maxn];

BiTree create(int postL, int postR, int inL, int inR) { // 根据后序序列和中序序列构造二叉树
    if(postL > postR) { // 后序序列长度小于等于0时直接返回NULL
        return NULL;
    }

    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    if(!root) {
        return NULL;
    }
    root->data = post[postR];

    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == post[postR]) {
            break;
        }
    }
    int leftCount = k - inL;

    // 创建左子树, 左子树后序序列区间为[postL, postL + leftCount - 1], 中序序列区间为[inL, k - 1]
    root->lchild = create(postL, postL + leftCount - 1, inL, k - 1);
    // 创建右子树, 右子树后序序列区间为[postL + leftCount, postR - 1], 中序序列区间为[k + 1, inR]
    root->rchild = create(postL + leftCount, postR - 1, k + 1, inR);

    return root;
}

void layerOrder(BiTree root) { // 层序遍历
    if(!root) {
        return ;
    }

    queue<BiTree> q;
    q.push(root);
    int flag = 0; // 控制打印空格的个数
    while(!q.empty()) {
        BiTree top = q.front();
        q.pop();

        if(flag == 0) {
            printf("%d", top->data);
            flag = 1;
        } else {
            printf(" %d", top->data);
        }

        if(top->lchild) {
            q.push(top->lchild);
        }
        if(top->rchild) {
            q.push(top->rchild);
        }
    }
}

int main(void) {

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    BiTree root = create(0, n - 1, 0, n - 1);
    layerOrder(root);
    printf("\n");

    return 0;
}
