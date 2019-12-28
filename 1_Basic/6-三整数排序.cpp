
// 题目: 输入3个整数, 从小到大排序后输出.
// 样例输入: 20 7 33
// 样例输出: 7 20 33

#include <stdio.h>

int main(void) {

    int a, b, c, t;
    scanf("%d%d%d", &a, &b, &c);
    if(a > b) { // 该分支执行完毕后必有 a <= b
        t = a;
        a = b;
        b = t;
    }
    if(a > c) { // 该分支执行完毕后必有 a <= c
        t = a;
        a = c;
        c = t;
    }
    if(b > c) { // 该分支执行完毕后必有 b <= c
        t = b;
        b = c;
        c = t;
    }
    printf("%d %d %d\n", a, b, c);
    
    return 0;
}
