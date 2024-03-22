#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double newton(double x, double m, double p);
double f(double x);
double df(double x);

int main(void)
{
  double x, max = 50 ,eps = pow(2.0, -30.0);

  printf("** 初期値の入力: ");
  scanf("%lf", &x);

  printf("x = %lf\n", newton(x, max, eps));

  return (0);
}
/* newton */
double newton(double x, double m, double p)
{
  double n = 0;
  double d;
  do{
    d= -f(x)/df(x);
    x = x + d;
    n++;
  } while (fabs(d) > p && n < m);
  if (n == m) {
    printf("failed");
    exit(0);
  } else {
    return x;
  }
}

/* 関数の定義 */
double f(double x)
{
  return pow(x,3)+(-3*pow(x,2))+(-1*x)+3;
}
/* 関数の微分 */
double df(double x)
{
  return (3*pow(x,2))+(-6*x)+(-1);
}
