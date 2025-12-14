// 01串压缩编码
//
// 思路：15 1 128
// 1.先把所有数字转换为8位二进制数
// 00001111 000000011 100000000
// 2.把所有二进制数连接起来，转换为字符串
// 0000111100000001110000000
// 3.识别相同的子串，使用数组保存其长度和任意一个字符
// 4.逐个生成压缩后的编码
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

namespace YFan
{
    // 把一个整数转换为8位二进制数
    string int_to_bin(ll x, int digit = 8)
    {
        string res = "";
        for (int i = 0; i < digit; i++)
        {
            if (x % 2 == 0)
                res += '0';
            else
                res += '1';
            x /= 2;
        }
        reverse(res.begin(), res.end()); // 反转字符串，得到正确的二进制数
        return res;
    }

    // 把一个二进制数转换为整数
    ll bin_to_int(string s)
    {
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            res += (s[i] - '0') * pow(2, s.size() - 1 - i);
        }
        return res;
    }

    typedef pair<int, int> pii;
    // 把字符串 s 压缩为编码，返回压缩后的编码
    vector<pii> compress(string s)
    {
        vector<pii> res;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // 统计连续相同字符的长度
            if (i == 0 || s[i] != s[i - 1])
            {
                if (count > 0)
                    res.push_back({count, s[i - 1] - '0'});
                count = 1;
            }
            else
                count++;
        }
        // 处理最后一个字符
        if (count > 0)
        {
            res.push_back({count, s.back() - '0'});
        }
        return res;
    }

    // 把压缩后的编码 p 解码为原始的 01 串
    string decode(pii p)
    {
        string s = "";
        s += p.second + '0';
        s += int_to_bin(p.first, 7);
        return s;
    }
}

int main()
{
    int n;
    cin >> n; // n = 8 * m
    n /= 8;

    string s = "";
    while (n--)
    {
        ll x;
        cin >> x;
        s += YFan::int_to_bin(x);
    }

    vector<YFan::pii> res = YFan::compress(s);
    for (auto p : res)
        cout << YFan::bin_to_int(YFan::decode(p)) << " ";
}
