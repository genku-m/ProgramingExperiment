#include <stdio.h>
#include <math.h>
#include <unistd.h>

/* 2分法 */
double bisection(double a, double b, double eps);
/* 関数の定義 */
double f(double x);

int main(void)
{
  double a, b, x, h, y1, y2, eps = pow(2.0, -30.0);
  int n;

  printf("** 初期区間 [a, b] の入力: ");
  scanf("%lf %lf", &a, &b);

  printf("** 区間の分割数nの入力: ");
  scanf("%d", &n);

  /* 対象区間を探索しながら2分法を適用 */
  h = (b-a)/n;   /* 穴埋め箇所1 */
  y1 = f(a);
  printf("h = %lf\n",h);
  for(x=a+h; x!=b; x+=h){
    if (x == b) {
      printf("x == b %lf\n",x);
    }
    if (x > b) {
      printf("x > b %lf\n",x);
    }
    printf("x = %lf\n",x);
    y2 = f(x);
    if(y1*y2 < 0.0) printf("x = %lf\n", bisection(x-h, x, eps));   /* 穴埋め箇所2 */
    y1 = y2;
    sleep(1);
  }
  return (0);
}
/* 2分法 */
double bisection(double a, double b, double eps)
{
  double c;
  do{
    c = (a+b)/2.0;
    if(f(a)*f(c) < 0.0) b = c;   /* 穴埋め箇所3 */
    else a = c;
  } while (fabs(b-a) >= eps);
  c = (a+b)/2.0;   /* 穴埋め箇所4 */

  return (c);
}

/* 関数の定義 */
double f(double x)
{
  return pow(x,5)-(5*pow(x,3))+(4*x);   /* 穴埋め箇所5 */
}
