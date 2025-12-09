// 计算两个整数的和
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        // C style
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);

        // C++ style
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
}

// 多行数据如何处理？
// int n;
// cin >> n;
// while (n--)
// {
//     // Your Code Here
// }
