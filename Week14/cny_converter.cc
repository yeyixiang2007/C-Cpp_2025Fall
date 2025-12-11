// 人民币金额打印（拓展至亿级别）
//
// 思路：以 19006005 为例
// 1.字符串倒序并剔除负号：50060091
// 2.逐个转换为大写数字：[伍][零][零][陆][零][零][玖][壹]
// 3.插入小单位：[伍(圆)][零][零][陆(仟)][零][零][玖(佰)][壹(仟)]
// 4.插入大单位：[伍(圆)][零][零][陆(仟)](万)[零][零][玖(佰)][壹(仟)]
// 5.合并重复零：[伍(圆)][零][陆(仟)](万)[零][玖(佰)][壹(仟)]
// 6.删除大单位后的零：[伍(圆)][零][陆(仟)](万)[玖(佰)][壹(仟)]
// 7.合并倒序输出（并添加负号）：壹仟玖佰万陆仟零伍圆
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

namespace YFan
{
    // 数字
    static string digits[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    // 小单位（仟佰拾）
    static string s_units[] = {"", "拾", "佰", "仟"};
    // 大单位（圆万亿）
    static string l_units[] = {"圆", "万", "亿"};

    string cny_to_str(string cny)
    {
        // Step 1: 字符串倒序并剔除负号
        bool is_negative = false;
        if (cny[0] == '-')
        {
            is_negative = true;
            cny = cny.substr(1);
        }
        reverse(cny.begin(), cny.end());

        // Step 2: 逐个转换为大写数字
        vector<string> res;
        for (int i = 0; i < cny.length(); i++)
        {
            int d = cny[i] - '0';
            res.push_back(digits[d]);
        }

        // Step 3: 插入小单位
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] != "零")
                res[i] += s_units[i % 4];
        }

        // Step 4: 插入大单位
        for (int i = 0; i < res.size(); i++)
        {
            if (i % 4 == 0 && i / 4 < 3)
                res[i] += l_units[i / 4];
        }

        // Step 5: 合并重复零
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] == "零")
            {
                if (i + 1 < res.size() && res[i + 1] == "零")
                {
                    res[i] = "";
                }
            }
        }

        // Step 6: 删除大单位后的零
        bool check_zero = false;
        for (int i = 0; i < res.size(); i++)
        {
            if (i % 4 == 0 && i / 4 < 3)
            {
                string unit = l_units[i / 4];
                if (res[i] == "零" + unit)
                {
                    bool has_value = false;
                    for (int k = i + 1; k < res.size(); k++)
                    {
                        if (res[k] != "" && res[k] != "零")
                            has_value = true;
                    }
                    if (has_value)
                    {
                        res[i] = unit;
                        check_zero = true;
                    }
                    else
                        check_zero = false;
                }
                else
                    check_zero = false;
            }
            else
            {
                if (check_zero)
                {
                    if (res[i] == "零")
                        res[i] = "";
                    else if (res[i] != "")
                        check_zero = false;
                }
            }
        }

        // Step 7: 合并倒序输出
        string ans = is_negative ? "负" : "";
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
            ans += res[i];
        return ans;
    }
}

int main()
{
    system("chcp 65001");
    int n;
    if (cin >> n)
    {
        while (n--)
        {
            string cny;
            cin >> cny;
            cout << YFan::cny_to_str(cny) << endl;
        }
    }
    return 0;
}
