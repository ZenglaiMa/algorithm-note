/*
    算法笔记P247: codeup 1918: 简易计算器: 读入一个只包含 +, -, *, / 的非负整数计算表达式, 计算该表达式的值.
        输入格式: 输入包含若干测试用例, 每个测试用例占一行, 每行不超过200个字符, 整数和运算符之间用一个空格分隔, 无非法表达式, 一行中只输入0时结束.

    思路: 题目中输入的是中缀表达式, 计算它的值主要有两个步骤:
        (1) 中缀表达式转成后缀表达式:
            ① 设置一个运算符栈, 用来临时存放运算符; 设置一个队列, 用来存放后缀表达式.
            ② 从左到右扫描中缀表达式, 如果遇到操作数, 则将操作数入队(注意操作数不止一位), 即把操作数加入后缀表达式中.
            ③ 如果遇到运算符 op, 则将 op 的优先级与运算符栈的栈顶运算符的优先级作比较:
                a. 若 op 的优先级高于栈顶运算符的优先级, 则将 op 压入运算符栈;
                b. 若 op 的优先级小于等于栈顶运算符的优先级, 则将运算符栈的运算符不断弹出至后缀表达式队列中, 直至 op 的优先级高于栈顶运算符的优先级, 然后将 op 压入运算符栈.
            ④ 重复上述操作, 直至中缀表达式扫描完毕, 之后若运算符栈中还有元素, 则将它们依次弹出至后缀表达式中.
        (2) 计算后缀表达式:
            ① 从队首开始扫描后缀表达式队列.
            ② 如果是操作数, 则将操作数压入栈中.
            ③ 如果是运算符, 则连续从栈中弹出两个操作数(注意: 后弹出的为第一操作数, 先弹出的为第二操作数), 然后将两个数进行相应运算符计算, 将结果压入栈中.
            ④ 直至后缀表达式队列扫描完毕, 这时栈中只剩下一个数, 这个数就是答案.
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

typedef struct {
    bool flag;  // true 表示是操作数; false 表示是运算符
    double num; // 操作数
    char op;    // 运算符
} node;

string str; // 输入的计算式, 即中缀表达式
stack<node> s; // 运算符栈(后缀表达式的计算结果也保存到此栈中)
queue<node> q; // 后缀表达式队列
map<char, int> mp; // 用一个 map 来存放运算符的优先级: 乘法 == 除法 > 加法 == 减法.

// 中缀表达式转后缀表达式
void change() {
    node temp;
    for(int i = 0; i < str.length(); ) {
        if(str[i] >= '0' && str[i] <= '9') { // 如果是操作数
            temp.flag = true;
            temp.num = str[i] - '0';
            i++;
            while(i < str.length() && str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            q.push(temp);
        } else { // 如果是运算符
            temp.flag = false;
            while(!s.empty() && mp[str[i]] <= mp[s.top().op]) {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

// 计算后缀表达式
double cal() {
    double temp1, temp2;
    node cur, temp;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if(cur.flag == true) {
            s.push(cur);
        } else {
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            if(cur.op == '+') {
                temp.num = temp1 + temp2;
            } else if(cur.op == '-') {
                temp.num = temp1 - temp2;
            } else if(cur.op == '*') {
                temp.num = temp1 * temp2;
            } else if(cur.op == '/') {
                temp.num = temp1 / temp2;
            }
            temp.flag = true;
            s.push(temp);
        }
    }
    
    return s.top().num;
}

int main(void) {

    // 设定操作符优先级
    mp['+'] = mp['-'] = 0;
    mp['*'] = mp['/'] = 1;

    while(getline(cin, str) && str != "0") {
        for(string::iterator it = str.begin(); it != str.end(); it++) {
            if(*it == ' ') { // 去除表达式中所有的空格
                str.erase(it);
            }
        }
        while(!s.empty()) { // 清空栈, 因为每一轮运算结束后栈中会剩下一个元素.
            s.pop();
        }
        change();
        printf("result : %.2f\n", cal());
    }

    return 0;
}
