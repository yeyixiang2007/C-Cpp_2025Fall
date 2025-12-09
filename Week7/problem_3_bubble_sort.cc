// 冒泡排序
#include <iostream>

namespace YFan
{
    void sort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++) // 冒泡排序的趟数
        {
            // 每次冒泡排序都将最大的元素“冒泡”到最后面，因此每一趟都可以少排序一次
            for (int j = 0; j < n - i - 1; j++) // 每趟冒泡排序的次数
            {
                // 如果当前元素大于下一个元素，则交换它们
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

int main()
{
    int n;
    std::cin >> n;

    while (n--)
    {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        int arr[4] = {a, b, c, d};
        YFan::sort(arr, 4);
        std::cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << std::endl;
    }
}
