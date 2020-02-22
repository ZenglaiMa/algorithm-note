/*
    Q: 给定一个 m*n 大小的迷宫, 其中 "0" 代表不可通过的墙壁, "1" 代表平地, S表示起点, T表示终点. 移动过程中,
       如果当前位置是(x,y)(下标从0开始), 且每次只能前往上下左右(x, y+1), (x, y-1), (x+1, y), (x-1, y)四个位置的平地,
       求从起点 S 到达终点 T 的最小步数. 例如:
                                            1 1 1 1 1
                                            1 0 1 0 1
                                            1 0 S 0 1
                                            1 0 0 0 1
                                            1 1 1 T 0
       在该例中, S坐标为(2, 2), T坐标为(4, 3), S到T的最小步数为 11.
    
    思路: 由于求的是最小步数, 而BFS就是通过层次的顺序来遍历的, 因此可以从起点开始遍历每一层, 那么终点所在的层数就是要求解的最小步数.
*/

#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
    int x;
    int y;
    int step;
} Coordinate;

const int maxn = 100;
int maze[maxn][maxn];
int m, n;
bool inq[maxn][maxn] = { false };
int X[4] = { 0, 0, 1, -1 }; // 增量数组
int Y[4] = { 1, -1, 0, 0 };

bool judge(int x, int y) { // 判断某位置是否需要访问
    if(x < 0 || x >= m || y < 0 || y >= n) { // 越界, 注意: x y轴方向
        return false;
    }
    if(maze[x][y] == 0 || inq[x][y]) { // 相应位置为0, 或者该位置已经入过队
        return false;
    }

    return true;
}

int BFS(Coordinate begin, Coordinate end) {
    queue<Coordinate> q;
    q.push(begin);
    inq[begin.x][begin.y] = true;
    Coordinate top, temp;
    
    while(!q.empty()) {
        top = q.front();
        q.pop();
        if(top.x == end.x && top.y == end.y) { // 到达终点, 返回步数
            return top.step;
        }
        for(int i = 0; i < 4; i++) { // 将当前top元素的下一层依次入队
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX, newY)) { // 判断该位置是否可走
                temp.x = newX;
                temp.y = newY;
                temp.step = top.step + 1;
                q.push(temp);
                inq[newX][newY] = true;
            }
        }
    }

    return -1;
}

int main(void) {

    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    Coordinate begin, end;
    scanf("%d%d%d%d", &begin.x, &begin.y, &end.x, &end.y);
    begin.step = 0;

    printf("min step = %d\n", BFS(begin, end));

    return 0;
}