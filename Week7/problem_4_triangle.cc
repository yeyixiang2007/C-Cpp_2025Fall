// 打印三角形
// *****
//  ***
//   *
#include <iostream>
using namespace std;

namespace YFan
{
    void triangle(int layer)
    {
        for (int i = 0; i < layer; i++)
        {
            for (int j = 0; j < i; j++)
                cout << " ";
            for (int j = 0; j < (2 * (layer - i)) - 1; j++)
                cout << "*";
            cout << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int layer;
        cin >> layer;
        YFan::triangle(layer);
    }
}
