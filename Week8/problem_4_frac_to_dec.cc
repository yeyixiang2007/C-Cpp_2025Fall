#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1005 // 确保不溢出

int digits[MAX_DIGITS];

void solve()
{
    long long a, b;
    int c;

    scanf("%lld %lld %d", &a, &b, &c);

    // 计算整数部分
    printf("%lld.", a / b);

    a %= b;

    // 计算小数部分
    for (int i = 0; i <= c; i++)
    {
        a *= 10;
        digits[i] = a / b;
        a %= b;

        // 如果小数部分为0，且位数未到要求，填充0
        if (a == 0 && i < c)
        {
            for (int k = i + 1; k <= c; k++)
            {
                digits[k] = 0;
            }
            break;
        }
    }

    // 四舍五入
    if (digits[c] >= 5) // 如果最后一位大于等于5，需要进位
    {
        int k = c - 1;
        while (k >= 0)
        {
            digits[k]++;
            if (digits[k] < 10) // 如果当前位小于10，不需要进位
                break;
            digits[k] = 0; // 如果当前位等于10（不可能大于10），需要进位，当前位设为0
            k--;
        }
    }

    // 输出结果
    for (int i = 0; i < c; i++)
    {
        printf("%d", digits[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        solve();
    }
    return 0;
}
