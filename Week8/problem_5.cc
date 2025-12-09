// 进制转换
#include <iostream>
#define ll long long
using namespace std;

namespace YFan
{
    string convert(ll n, int base)
    {
        if (n == 0)
            return "";

        string res = "";
        int rem = n % base;

        res = convert(n / base, base) + to_string(rem);
        return res;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ll a;
        int b;
        cin >> a >> b;
        if (a == 0)
            cout << "0" << endl;
        else
            cout << YFan::convert(a, b) << endl;
    }
}
