// 换位置的次数
#include <iostream>
#include <vector>
using namespace std;

namespace YFan
{
    int bubble_sort(vector<int> arr)
    {
        int count = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr.size() - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    count++;
                }
            }
        }
        return count;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << YFan::bubble_sort(arr) << endl;
}
