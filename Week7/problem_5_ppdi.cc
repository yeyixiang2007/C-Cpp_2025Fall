// 水仙花数
#include <iostream>
#include <vector>
using namespace std;

namespace YFan
{
    bool is_ppdi(int n) // n 为 3 位整数
    {
        int a = (n / 100) % 10; // 百位数
        int b = (n / 10) % 10;  // 十位数
        int c = n % 10;         // 个位数
        return a * a * a + b * b * b + c * c * c == n;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m, n;
        cin >> m >> n;

        bool found = false;
        vector<int> ppdis;

        for (int i = m; i <= n; i++)
        {
            if (YFan::is_ppdi(i))
            {
                found = true;
                ppdis.push_back(i);
            }
        }

        if (found)
        {
            for (int i = 0; i < ppdis.size(); i++)
            {
                cout << ppdis[i] << (i == ppdis.size() - 1 ? "" : " ");
            }
            cout << endl;
        }
        else
            cout << "-1" << endl;
    }
}
