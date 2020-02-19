/*
    大整数(big number)运算:
        对于一道A+B的题目, 如果A和B都是有着1000位的整数, 那么现有的数据类型是无法表示他的, 所以需要我们通过某种
        手段去模拟它的存储和运算.
*/

#include <cstring>

/*
    大整数的存储, 比如定义int型数组d[1000], 数组的每一位都代表大整数的每一位上的数值, 如 235813 存储到数组中则为:
    d[0]=3, d[1]=1, d[2]=8, d[3]=5, d[4]=3, d[5]=2, 即整数的高位存在数组的高位, 整数的低位存在数组的低位, 这样存储的
    原因是, 在进行运算时都是从整数的低位到高位依次进行枚举的, 便于操作. 为了方便随时获取大整数的长度, 可以配合定义一个
    int型变量作为其长度.
*/
typedef struct bign {
    int d[1000];
    int len;
    bign() {   // 构造函数进行初始化参数
        memset(d, 0, sizeof(d));
        len = 0;
    }
} BigN;

/*
    我们输入大整数时, 一般通过一个字符串读入, 然后将该字符串存到定义的大整数结构体中, 由于字符串是从高位到低位依次存储的,
    所以在转换时要逆序转换.
*/
BigN changeToBigN(char str[]) {
    BigN num;
    num.len = strlen(str);
    for(int i = 0; i < num.len; i++) {
        num.d[i] = str[num.len - 1 - i] - '0'; // 逆着赋值
    }
    
    return num;
}

/*
    比较两个BigN类型的大整数的大小: 首先判断长度, 长度长的数字大; 如果长度相等, 从高到低依次判断, 直到出现一位不相等, 
        即可判断大小.
*/
int compare(BigN a, BigN b) { // 若 a<b, 返回 -1; 若a==b, 返回 0; 若 a>b, 返回 1.
    if(a.len > b.len) {
        return 1;
    } else if(a.len < b.len) {
        return -1;
    } else {
        for(int i = a.len - 1; i >= 0; i--) { // 从高位向低位依次比较
            if(a.d[i] > b.d[i]) {
                return 1;
            } else if(a.d[i] < b.d[i]) {
                return -1;
            }
        }
        return 0;
    }
}

/*
    高精度加法: 依次从低位到高位, 将该位上两个数字与进位相加, 得到的结果取个位数作为该位结果, 取十位数作为新的进位.
*/
BigN add(BigN a, BigN b) {
    BigN c;
    int carry = 0; // 进位
    for(int i = 0; i < a.len || i < b.len; i++) { // 以较长的为界限
        int temp = a.d[i] + b.d[i] + carry;  // 该位上两个数字和进位相加
        c.d[c.len++] = temp % 10;  // 结果的个位数作为该位结果
        carry = temp / 10;  // 十位数作为新的进位
    }
    if(carry != 0) { // 如果最后进位不为0, 直接赋给结果的最高位
        c.d[c.len++] = carry;
    }

    return c;
}

/*
    高精度减法: 依次从低位到高位, 比较被减位和减位, 如果够减, 则直接减; 如果不够减, 则另该被减位的高一位减 1, 该被减位
        加 10 再进行相减. 注意运算结束后, 要保证结果至少有一位数, 同时去掉高位多余的0.
*/
BigN sub(BigN a, BigN b) {
    BigN c;
    for(int i = 0; i < a.len || i < b.len; i++) {
        if(a.d[i] < b.d[i]) { // 如果不够减
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while(c.len > 1 && c.d[c.len - 1] == 0) { // 去除高位多余的 0, 同时至少保留一位最低位
        c.len--;
    }

    return c;
}

/*
    高精度与低精度乘法: 即 BigN 类型与 int 类型的乘法. 依次从低位到高位, 取 BigN 的某位与 int 型整体相乘, 再与进位相加,
        所得结果的个数作为改为结果, 高位部分作为新的进位.
*/
BigN multi(BigN a, int b) {
    BigN c;
    int carry = 0; // 进位
    for(int i = 0; i < a.len; i++) {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while(carry != 0) { // 与加法不同, 乘法的进位可能不止一位, 因此用 while
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }

    return c;
}

/*
    高精度与低精度除法: 即 BigN 类型与 int 类型的除法. 依次从高位到低位, 对于某一步, 上一步余数乘以 10 加上该步的位, 
        得到该步临时的被除数, 将其与除数进行比较: 不过不够除, 则该位商 0; 如果够除, 商即为对应的商, 余数即为对应的余数.
        注意运算结束后, 要保证结果(商)至少有一位数, 同时去掉高位多余的0.
*/
BigN div(BigN a, int b, int &r) { // r 为余数, 因为有时可能要得到这个余数, 所以此处定义为引用类型, 运算结束后 r 的值即为余数. 只需定义一个 r = 0 将 r 传入即可.
    BigN c;
    c.len = a.len; // 被除数的每一位和商的每一位是一一对应的, 故先令两者长度相等
    for(int i = a.len - 1; i >= 0; i--) {
        r = r * 10 + a.d[i]; // 上一步余数乘以 10 加上该步的位得到该步临时的被除数
        if(r < b) {
            c.d[i] = 0; // 不够除, 则该位商 0
        } else {
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while(c.len > 1 && c.d[c.len - 1] == 0) { // 去除高位多余的 0, 同时至少保留一位最低位
        c.len--;
    }

    return c;
}
