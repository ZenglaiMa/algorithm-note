/*
    并查集(Union Find Set)
        并查集是一种维护集合的数据结构, 它支持两种操作:
            ① 合并: 合并两个集合;
            ② 查找: 判断两个元素是否属于同一集合.
        并查集一般用一个数组实现 int father[N]; father[i]表示元素 i 的父结点, 可以规定当 father[i] == i 
        时元素 i 为该集合的根结点, 对同一集合来说只存在一个根结点且将其作为所属集合的标识.
    注意
        并查集中关注的并不是元素结点之间的相互关系, 而是关注查找某结点所属集合的根结点这一过程, 这一点对于优化算法十分必要.
*/

#define N 100

int father[N];

// 1. 初始化并查集, 一开始每个元素都是一个独立的集合.
void init() {
    for(int i = 1; i <= N; i++) {
        father[i] = i;
    }
}

// 2. 查找, 查找某个元素所属集合的根结点.
int findFather(int x) {
    while(father[x] != x) {
        x = father[x];
    }

    return x;
}

/*
    3. 合并, 将两个元素所属的集合合并成一个集合.
        在合并过程中, 只对两个不同的集合进行合并, 如果两个元素在同一个集合中, 那么就不对他们进行操作.
        这就保证了在同一个集合中一定不会产生环, 即并查集产生的每一个集合都是一棵树.
*/
void _union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) { // 如果不属于同一集合再进行合并
        father[faA] = faB;
    }
}

/*
    通过路径压缩对findFather函数进行优化
        上面写的findFather函数在极端情况下效率较低: 如果并查集中元素数量很多(>10^5级别)且形成一条链, 而我们要进行10^5次查询,
        这样每次查询都要从后依次向前查找直到找到根结点, 那么这个这个查找函数的效率就会变得非常的低. 这时就要进行优化: 
        由于findFather函数的目的就是为了找到某个元素所在集合的根结点, 那我们索性就把每一个结点直接和根结点相连即可,
        即每一个结点的父结点都指向根结点, 这样查询的复杂度可以降为 O(1). 可以认为在查找时把寻找根结点的路径压缩了.
*/
int _findFather(int x) {
    
    int a = x;

    while(father[x] != x) {
        x = father[x];
    }

    while(father[a] != a) {
        int z = a;
        a = father[a];
        father[z] = x;
    }

    return x;
}
