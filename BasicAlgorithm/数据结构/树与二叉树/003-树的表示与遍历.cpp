/*
    树的表示与遍历: 为了方便, 我们一般用静态方式表示一棵树.
*/

#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

#define ElemType int

const int maxn = 110;

// 树的表示
typedef struct {
    ElemType data; // 数据域
    vector<int> child; // "指针"域, 存放所有子结点的下标
} Tree;

Tree TNode[maxn]; // 结点数组, maxn为结点上限个数

// 树的先根遍历(DFS)
void preOrder(int root) {
    printf("%d\n", TNode[root].data);
    for(int i = 0; i < TNode[root].child.size(); i++) {
        preOrder(TNode[root].child[i]);
    }
}

// 树的层序遍历(BFS)
void layerOrder(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        printf("%d\n", TNode[top].data);
        for(int i = 0; i < TNode[top].child.size(); i++) {
            q.push(TNode[top].child[i]);
        }
    }
}

int main(void) {

/*
                    1
                 /  |   \
                2   3    4
               / \  |  / | \
              5   6 7 8  9  10
*/

    for(int i = 1; i <= 10; i++) {
        TNode[i - 1].data = i;
    }
    TNode[0].child.push_back(1);
    TNode[0].child.push_back(2);
    TNode[0].child.push_back(3);
    TNode[1].child.push_back(4);
    TNode[1].child.push_back(5);
    TNode[2].child.push_back(6);
    TNode[3].child.push_back(7);
    TNode[3].child.push_back(8);
    TNode[3].child.push_back(9);

    printf("先根遍历:\n");
    preOrder(0);

    printf("层序遍历:\n");
    layerOrder(0);

    return 0;
}
