#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

namespace YFan
{
    // 定义字符集顺序：0-9, a-z
    // 0-9 映射到下标 0-9
    // a-z 映射到下标 10-35

    // 辅助函数：将字符映射到数组下标
    int get_index(char c)
    {
        if (isdigit(c))
            return c - '0';
        if (isalpha(c))
            return tolower(c) - 'a' + 10;
        return -1; // 非法字符
    }

    // 辅助函数：将数组下标映射回字符
    char get_char(int index)
    {
        if (index >= 0 && index <= 9)
            return index + '0';
        if (index >= 10 && index <= 35)
            return index - 10 + 'A';
        return '?';
    }

    // 统计字符频率
    vector<int> get_freq(const string &s)
    {
        vector<int> freq(36, 0);
        for (char c : s)
        {
            int idx = get_index(c);
            if (idx != -1) // 只统计字母和数字，忽略标点和空格
            {
                freq[idx]++;
            }
        }
        return freq;
    }

    // 绘制频率图
    void draw_freq_graph(const vector<int> &freq)
    {
        int height = 0;
        for (int count : freq)
        {
            height = max(height, count);
        }

        // 输出频率图 (从最高处往下画)
        for (int h = height; h > 0; h--)
        {
            for (int i = 0; i < 36; i++)
            {
                if (freq[i] >= h)
                    cout << "*" << " ";
                else
                    cout << "-" << " ";
            }
            cout << endl;
        }

        // 输出 x 轴标签
        for (int i = 0; i < 36; i++)
        {
            cout << get_char(i) << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (getline(cin, s))
    {
        vector<int> freq = YFan::get_freq(s);
        YFan::draw_freq_graph(freq);
    }

    return 0;
}
