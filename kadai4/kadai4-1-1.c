#include <stdio.h>
#include <math.h>
#include <unistd.h>

double sekibun(double a, double b, double n);
/* 関数の定義 */
double f(double x);

int main(void)
{
  printf("S=%lf",sekibun(1,2,10000000));
  return (0);
}

double sekibun(double a, double b, double n)
{
  double h;
    h = (b - a) / n;

    double x, sum;
    int i;

    sum = 0;
    sum = 1/2 * f(a);
    for (i = 1; i < n; i++)
    {
        x = a + h * i;
        sum += f(x);
    }

    sum = sum + 1/2 * f(b);
    return h * sum;
}

/* 関数の定義 */
double f(double x)
{
  return 2/pow(x,2);
}
