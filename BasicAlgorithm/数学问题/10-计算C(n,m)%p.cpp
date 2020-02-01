/*
    计算 C(n, m) % p. 该问题有多种方法解决, 其中最简单最常用的是基于计算组合数问题中的方法二, 只需要在原来代码中适当的位置对 p 取模即可.
    这种算法可以很好地支持 m<=n<=1000 的情况, 并对 p 的大小和素性没有额外限制.
*/

int res[1010][1010] = { 0 };

// ① 递归方式
int C(int n, int m, int p) {
    if(m == 0 || m == n) {
        return 1;
    }
    if(res[n][m] != 0) {
        return res[n][m];
    }

    return res[n][m] = (C(n - 1, m, p) + C(n - 1, m - 1, p)) % p;
}

// ② 递推方式: 获取 C(n, m) % p 的数表, 通过 res[n][m] 获取
void calC(int p) {
    const int n = 1000;
    for(int i = 0; i <= n; i++) {
        res[i][0] = res[i][i] = 1;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i / 2; j++) {
            res[i][j] = (res[i - 1][j] + res[i - 1][j - 1]) % p;
            res[i][i - j] = res[i][j];
        }
    }
}
