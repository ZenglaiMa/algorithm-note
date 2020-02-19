/*
    组合数的计算: 求 C(n, m).
        定义式为: C(n, m) = n! / (m!*(n-m)!)
        有: C(n, m) = C(n, n-m)
            C(n, 0) = C(n, n) = 1
*/

// 方法一: 通过定义直接计算: C(n, m)=n!/(m!*(n-m)!), 这样只需要先计算 n!, 然后令其分别除以 m! 和 (n-m)! 即可. 但因为阶乘相当庞大,
//      即使使用 long long 类型来存储也只能承受 n<=20 的数据范围.
long long C1(long long n, long long m) {
    long long ans = 1;
    for(long long i = 1; i <= n; i++) {
        ans *= i;
    }
    for(long long i = 1; i <= m; i++) {
        ans /= i;
    }
    for(long long i = 1; i <= n - m; i++) {
        ans /= i;
    }

    return ans;
}

// 方法二: 通过递推公式计算: C(n, m) = C(n-1, m) + C(n-1, m-1). 该方法在 n=67, m=33 时开始溢出.
long long res[67][67] = { 0 }; // 组合数表
// ① 递归代码
long long C2(long long n, long long m) {
    if(m == 0 || m == n) {
        return 1;
    }
    if(res[n][m] != 0) {
        return res[n][m];
    }
    return res[n][m] = C2(n - 1, m) + C2(n - 1, m - 1);
}

// ② 递推代码计算出整张表
void calC() {
    const int n = 60;
    for(int i = 0; i <= n; i++) {
        res[i][0] = res[i][i] = 1; // 初始化边界
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i / 2; j++) {
            res[i][j] = res[i - 1][j] + res[i - 1][j - 1]; // C(i, j) = C(i-1, j) + C(i-1, j-1)
            res[i][i - j] = res[i][j]; // C(i, i-j) = C(i, j)
        }
    }
}

// 方法三: 通过定义式的变形来计算, 了解即可.
long long C3(long long n, long long m) {
    long long ans = 1;
    for(long long i = 1; i <= m; i++) {
        ans = ans * (n - m + i) / i;  // 注意一定要先乘后除
    }

    return ans;
}