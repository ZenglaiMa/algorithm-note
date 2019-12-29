
// 问题: 给出一种物质的分子式, 求分子量. 本题中的分子式只包含4中原子, 分别为 C, H, O, N, 
//       原子量分别为 12.01, 1.008, 16.00, 14.01(单位: g/mol). 例如, C6H5OH的分子量是 94.108g/mol.
// 思路: 查看当前字符的下一个是否为数字, 如果是下一个字符存在且为数字(即不是字母), 
//       就用当前字符的原子量乘以数字即可, 否则乘以1.0, 最后将它们累加起来即可.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char ch[100];

double getAtom(const char ch) {
    if(ch == 'C')
        return 12.01;
    if(ch == 'H')
        return 1.008;
    if(ch == 'O')
        return 16.00;
    if(ch == 'N')
        return 14.01;
}

int main(void) {

    double sum = 0;
    scanf("%s", ch);
    int len = strlen(ch);
    for(int i = 0; i < len; i++) {
        double atom = getAtom(ch[i]);
        if(ch[i + 1] && !isalpha(ch[i + 1])) { // 判断下一个字符是否存在且是否为数字(不是字母即为数字)
            int n = ch[i + 1] - '0';
            sum += atom * n;
            i++;
            continue;
        } else {
            sum += atom * 1.0;
        }
    }
    
    printf("%.3fg/mol\n", sum);

    return 0;
}