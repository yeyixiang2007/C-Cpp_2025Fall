#include <iostream>
using namespace std;

int main()
{
    // === 单个数据读取 ===
    int a;
    cin >> a;        // C++ Style
    scanf("%d", &a); // C Style
    // %d 表示输入一个整数，&a 表示将输入的值存储到变量 a 中。

    // === 多组数据读取 ===
    // 第一行输入一个整数 n，表示有 n 组数据。
    // 接下来 n 行，每行输入一组数据。
    int n;
    cin >> n;
    while (n--)
    {
        // Code
    }

    // === 单行多个数据读取 ===
    // 用空格隔开的多个数据
    int a, b, c;
    cin >> a >> b >> c;            // C++ Style
    scanf("%d %d %d", &a, &b, &c); // C Style
    // 用逗号隔开的多个数据
    int a, b, c;
    // C++ 处理逗号隔开的多个数据较为麻烦，不如直接用 scanf
    scanf("%d,%d,%d", &a, &b, &c); // C Style
}
