
// 题目: 已知鸡和兔的总数为 n, 总腿数为 m. 输入 n 和 m, 依次输出鸡的数目和兔的数目.
// 样例输入: 14 32
// 样例输出: 12 2
// 样例输入: 10 16
// 样例输出: No answer

#include <stdio.h>

int main(void) {

    int chicken, rabbit, n, m;
    scanf("%d%d", &n, &m);
    rabbit = (m - 2 * n) / 2; // 通过联立方程得到的数学表达式
    chicken = n - rabbit;
    if(m % 2 == 1 || chicken < 0 || rabbit < 0)
        printf("No answer\n");
    else
        printf("%d %d\n", chicken, rabbit);

    return 0;
}
