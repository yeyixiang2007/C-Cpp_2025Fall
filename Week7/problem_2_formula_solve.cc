// 求解一元二次方程
#include <stdio.h>
#include <math.h>

void slove(float a, float b, float c)
{
    if (a == 0 && b == 0)
    {
        printf("x\n");
        return;
    }

    if (a == 0)
    {
        double x = -c * 1.0 / b;
        printf("%.2f\n", x);
        return;
    }

    double delta = b * b - 4.0 * a * c;
    if (delta < 0)
    {
        printf("x\n");
        return;
    }

    double sqrt_delta = sqrt(delta);
    double x1 = (-b + sqrt_delta) / (2.0 * a);
    double x2 = (-b - sqrt_delta) / (2.0 * a);

    if (delta == 0)
        printf("%.2f\n", x1);

    else
    {
        if (x1 < x2)
        {
            double temp = x1;
            x1 = x2;
            x2 = temp;
        }
        printf("%.2f %.2f\n", x1, x2);
    }
}

int main()
{
    int a, b, c;
    while (scanf("%d,%d,%d", &a, &b, &c) == 3)
    {
        slove(a, b, c);
    }
}
