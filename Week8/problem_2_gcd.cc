// 最大公约数
#include <iostream>
using namespace std;

namespace YFan
{
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b); // 辗转相除法
    }

    int modern_gcd(int a, int b)
    {
        return b ? modern_gcd(b, a % b) : a;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << YFan::gcd(a, b) << endl;
    }
}
