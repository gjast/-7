#include <stdio.h>
#include <math.h>
#include <time.h>

double f(double x)
{
    return  0.25 * pow(x, 3) + x - 1.2502;
}

double f1(double x)
{
    return  0.25 * 3 * pow(x, 2) + 1;
}

double f2(double x)
{
    return 0;
}

int main()
{
    int n = 0;
    double a = 0, b = 2;
    double c, eps = 0.00001;

    clock_t start_time = clock();

    if (f(a) * f2(a) > 0)
        c = a;
    else
        c = b;

    do
    {
        c = c - f(c) / f1(c);
        n++;
    }
    while (abs(f(c)) >= eps);

    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("корень равен = %lf\n", c);
    printf("итераций = %d\n", n);
    printf("время выполнения = %lf секунд\n", time_taken);

    return 0;
}
