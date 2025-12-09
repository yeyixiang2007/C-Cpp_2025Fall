// 素数判断
#include <iostream>
using namespace std;

namespace YFan
{
    bool is_prime(int n)
    {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        if (YFan::is_prime(a))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
