// 广义表（简单版）
//
// 思路：以 (a,(b,c)) 为例，借鉴了 c4 的处理思路
// 1. 定义一个字符指针 p，指向当前要处理的字符
// 2. 定义一个变量 tk，用来存储当前字符（保存的是 ASCII 码）
// 3. 定义一个变量 depth，用来存储当前深度
// 4. 定义一个变量 length，用来存储当前长度
// 5. 定义一个变量 max_depth，用来存储最大深度，当 depth 大于 max_depth 时，更新 max_depth
// * 有效字符：小写字母、左括号、右括号
//
// TODO: 异常处理，如不合法的数据
// TODO: 拓展功能，支持解析为基于指针的数据结构
#include <iostream>
#define ll long long
using namespace std;

char *p;           // 当前指向的字符
ll tk;             // 当前 token（保存的是 ASCII 码）
int depth = 0;     // 当前深度
int length = 0;    // 当前长度
int max_depth = 0; // 最大深度

namespace YFan
{
    // 解析广义表
    void parse()
    {
        while (tk = *p)
        {
            ++p;
            if (tk == ' ' || tk == ',') // 跳过空格和逗号
                continue;
            if (tk == '(') // 开始一层嵌套
            {
                if (depth == 1)
                    length++; // 最外层的嵌套广义表
                depth++;
                continue;
            }
            if (tk == ')') // 结束一层嵌套
            {
                if (depth > max_depth)
                    max_depth = depth;
                depth--;
                continue;
            }
            if (tk >= 'a' && tk <= 'z') // 小写字母
            {
                if (depth == 1) // 最外层的单独字母
                    length++;
                continue;
            }
        }
    }
}

int main()
{
    string glist;
    while (getline(cin, glist) && glist != "END")
    {
        p = &glist[0];
        YFan::parse();
        cout << length << " " << max_depth << endl;

        depth = 0;
        length = 0;
        max_depth = 0;
    }
    return 0;
}
