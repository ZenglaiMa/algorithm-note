
// algorithm 头文件下的常用函数

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {

/*
    1. max(), min(), abs()
        ① max(x, y) 和 min(x, y) 分别返回 x, y 中的最大值和最小值, 参数必须是两个(可以是浮点数). 如果要返回 x,y,z 三个中的最大值可以 max(x, max(y, z)), 最小值同理.
        ② abs(x) 返回 x 的绝对值, 此处的 x 必须是整数, 如果要返回一个浮点数的绝对值, 要使用 <math.h> 下的 fabs(x).
*/
                                /*
                                    int x = 5, y = 1, z = 9;
                                    printf("max = %d\n", max(x, y));
                                    printf("min = %d\n", min(x, z));
                                    printf("max = %d\n", max(x, max(y, z)));

                                    printf("abs = %d\n", abs(9));
                                    printf("abs = %d\n", abs(-2));

                                    printf("fbas = %.2f\n", fabs(-3.14));
                                */


/*
    2. swap(x, y): 用来交换 x, y 的值.
*/
                                /*
                                    int x = 3, y = 5;
                                    swap(x, y);
                                    printf("x = %d, y = %d\n", x, y);

                                    double a = 3.14, b = 9.42;
                                    swap(a, b);
                                    printf("a = %.2f, b = %.2f\n", a, b);
                                */


/*
    3. reverse(it1, it2): 将数组指针在 [it1, it2) 内的元素或容器的迭代器在 [it1, it2) 内的元素进行翻转.
*/
                                /*
                                    int arr[5] = { 1, 2, 3, 4, 5 };
                                    reverse(arr, arr + 5);
                                    for(int i = 0; i < 5; i++) {
                                        printf("%d ", arr[i]);
                                    }
                                    printf("\n");

                                    char s[20] = "Hello world";
                                    reverse(s, s + strlen(s));
                                    printf("%s\n", s);

                                    string str = "abcdefghijk";
                                    reverse(str.begin(), str.end());
                                    cout << str << endl;
                                    reverse(str.begin() + 3, str.begin() + 9);
                                    cout << str << endl;
                                */


/*
    4. next_permutation(): 给出一个序列在全排列中的下一个序列. 如当 n==3 时全排列为: 123,132,213,231,312,321, 那么 231 的下一个序列就是 312.
*/
                                /*
                                    int arr[5] = { 1, 2, 3, 4 };
                                    do {
                                        printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
                                    } while(next_permutation(arr, arr + 4));
                                */


/*
    5. fill(): 可以把数组或容器中的某一段区间赋为某个相同的值.
*/
                                /*
                                    int arr[5];
                                    fill(arr, arr + 5, 0);
                                    for(int i = 0; i < 5; i++)
                                        printf("%d ", arr[i]);
                                    printf("\n");

                                    fill(arr, arr + 5, 1);
                                    for(int i = 0; i < 5; i++)
                                        printf("%d ", arr[i]);
                                    printf("\n");

                                    fill(arr, arr + 5, -1);
                                    for(int i = 0; i < 5; i++)
                                        printf("%d ", arr[i]);
                                    printf("\n");

                                    fill(arr, arr + 5, 929);
                                    for(int i = 0; i < 5; i++)
                                        printf("%d ", arr[i]);
                                    printf("\n");

                                    fill(arr + 3, arr + 5, 3);
                                    for(int i = 0; i < 5; i++)
                                        printf("%d ", arr[i]);
                                    printf("\n");
                                */


/*
    6. sort(): 排序函数, sort(首元素地址(必填), 尾元素地址的下一个地址(必填), 比较函数(非必填)), 基本类型默认为从小到大排序; 结构体排序需要在
            比较函数中指定排序关键字及排序规则; 标准STL容器中, 只有 vector, string 等可以使用sort排序, 因为像 set, map 这种容器底层用红黑树实现,
            元素本身已经有序, 故不需要再排.
*/


/*
    7. lower_bound() 和 upper_bound(): 必须在有序序列(数组或容器)中才能使用.
            ① lower_bound(first, last, val): 在数组或容器的 [first, last) 范围内寻找第一个值大于等于(>=) val 的元素的位置, 如果是数组,
                    返回该位置的指针; 如果是容器, 返回该位置的迭代器.
            ② upper_bound(first, last, val): 在数组或容器的 [first, last) 范围内寻找第一个值大于(>) val 的元素的位置, 如果是数组,
                    返回该位置的指针; 如果是容器, 返回该位置的迭代器.
            ③ 如果数组或容器中没有需要寻找的元素, 则 lower_bound() 和 upper_bound() 两者均返回可以插入该元素的位置的指针或迭代器(即假设
              该元素存在时, 它应当在的位置).
            ④ 如果只想获得欲查询元素的下标, 就可以不使用指针, 而是: 直接令返回值减去数组首地址即可.
*/
                                /*
                                    int arr[10] = { 1, 2, 2, 3, 3, 3, 5, 5, 5, 5 };
                                    printf("%d %d\n", lower_bound(arr, arr + 10, 3) - arr, upper_bound(arr, arr + 10, 3) - arr);
                                    printf("%d %d\n", lower_bound(arr, arr + 10, 4) - arr, upper_bound(arr, arr + 10, 4) - arr);
                                */
    

    return 0;
}
