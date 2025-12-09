// 学号进制转换
#include <iostream>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

namespace YFan
{
    // 将字符串转换为数组
    vector<int> to_arr(string s)
    {
        vector<int> res;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                res.push_back(s[i] - '0'); // 0~9
            else if (s[i] >= 'A' && s[i] <= 'F')
                res.push_back(s[i] - 'A' + 10); // 10~15
        }
        return res;
    }

    // 将数组转换为十进制数
    ll to_dec(string s, int base)
    {
        ll res = 0;
        // 位权展开
        vector<int> arr = to_arr(s);
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            res += arr[i] * pow(base, arr.size() - 1 - i);
        }
        return res;
    }

    // 将十进制数转换为任意进制字符串
    string convert(ll n, int base)
    {
        if (n == 0)
            return "";

        string res = "";
        int rem = n % base;
        if (rem < 10)
            res = convert(n / base, base) + to_string(rem);
        else
            res = convert(n / base, base) + (char)('A' + rem - 10);
        return res;
    }
}

int main()
{
    int a, b;
    string s;
    cin >> a >> s >> b;

    if (a == 0)
        cout << "0" << endl;
    else
        cout << YFan::convert(YFan::to_dec(s, a), b) << endl;
}
