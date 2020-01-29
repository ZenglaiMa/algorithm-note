/*
    分数的表示和化简及其四则运算
        1. 分数的表示: 最简单的表示方法是以假分数形式表示, 这样用一个结构体就可以了, 人为制订3项规则:
            ① 使分母非负: 如果分数为负, 那么令分子为负即可;
            ② 如果该分数恰为0, 那么规定其分子为0, 分母为1;
            ③ 分子和分母没有除了1以外的公约数, 即最简分数形式.
*/

#include <cstdio>
#include <cmath>

// 分数的表示
typedef struct {
    int up;     // 分子
    int down;   // 分母
} Fraction;

// 求最大公约数
int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// 2. 分数的化简:
//     对应三条规则: ① 若分母为负, 则令分子和分母都变为其相反数;
//                  ② 如果分子为0, 则令分母为1;
//                  ③ 约分: 求出分子分母绝对值的最大公约数, 然后分子分母同时除以最大公约数即可.
Fraction reduction(Fraction result) {
    if(result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }

    return result;
}

/*
    3. 分数的四则运算(设两个分数为f1, f2)
        加法: f1 + f2 = (f1.up*f2.down + f2.up*f1.down) / (f1.down*f2.down)
        减法: f1 - f2 = (f1.up*f2.down - f2.up*f1.down) / (f1.down*f2.down)
        乘法: f1 * f2 = (f1.up*f2.up) / (f1.down*f2.down)
        除法: f1 / f2 = (f1.up*f2.down) / (f2.up*f1.down)
*/

// 加法
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;

    return reduction(result);
}

// 减法
Fraction sub(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;

    return reduction(result);
}

// 乘法
Fraction multi(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;

    return reduction(result);
}

// 除法
Fraction div(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f2.up * f1.down;

    return reduction(result);
}

/*
    4. 分数的输出: 根据题目要求进行, 大致有如下几个:
        ① 输出分数前, 要先对其进行化简;
        ② 如果一个分数的分母为1, 说明该分数是整数, 直接输出这个整数即可;
        ③ 一个一个分数的分子up的绝对值大于分母down, 说明该分数为假分数, 此时按带分数形式输出, 
          即整数部分为 up/down, 分子部分为 abs(up)%down, 分母部分为 down;
        ④ 如果以上均不满足时说明分数为真分数, 原样输出即可.
*/
void showResult(Fraction r) {
    r = reduction(r);
    if(r.down == 1) {
        printf("%d\n", r.up);
    } else if(abs(r.up) > r.down) {
        printf("%d %d/%d\n", r.up / r.down, abs(r.up) % r.down, r.down);
    } else {
        printf("%d/%d\n", r.up, r.down);
    }
}
