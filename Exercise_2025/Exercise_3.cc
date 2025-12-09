#include <iostream>
#include <vector>
using namespace std;

namespace YFan
{
    void draw_chessboard(int m, int n, const vector<int> &q_vec, const vector<int> &k_vec)
    {
        vector<bool> row_has_line(m, false);
        vector<bool> col_has_line(n, false);

        for (int x : q_vec)
        {
            if (x >= 1 && x <= m)
            {
                row_has_line[x - 1] = true;
            }
        }

        for (int x : k_vec)
        {
            if (x >= 1 && x <= n)
            {
                col_has_line[x - 1] = true;
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool r = row_has_line[i];
                bool c = col_has_line[j];

                if (r && c)
                    cout << "+";
                else if (r)
                    cout << "-";
                else if (c)
                    cout << "|";
                else
                    cout << "0";
            }
            cout << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, q, k;
    if (!(cin >> m >> n >> q >> k))
        return 0;

    vector<int> q_vec, k_vec;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        q_vec.push_back(x);
    }
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        k_vec.push_back(x);
    }
    YFan::draw_chessboard(m, n, q_vec, k_vec);
    return 0;
}
