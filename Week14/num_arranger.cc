// n个不同整数的所有组合
//
// 思路：
// 1. 每个数都有两种情况：包含在组合中或不包含在组合中
// 2. 递归处理每个数，每次递归有两种分支：包含当前数或不包含当前数
// 3. 当处理完所有数时，打印当前组合
//
#include <iostream>
#include <vector>
using namespace std;

int n;
int a[15];    // 存储输入的数
int temp[15]; // 存储当前的组合

namespace YFan
{
    // 深度优先搜索的递归函数
    void dfs(int idx, int cnt)
    {
        if (idx == n)
        {
            cout << "-->";
            for (int i = 0; i < cnt; i++)
            {
                cout << " " << temp[i];
            }
            cout << endl;
            return;
        }

        temp[cnt] = a[idx];
        dfs(idx + 1, cnt + 1);
        dfs(idx + 1, cnt);
    }
}

int main()
{
    int m;
    if (cin >> m)
    {
        while (m--)
        {
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            YFan::dfs(0, 0);
        }
    }
    return 0;
}
