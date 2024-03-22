#include <stdio.h>
#include <math.h>
#include <unistd.h>

double simpson(double a, double b, double n);
/* 関数の定義 */
double f(double x);

int main(void)
{
  printf("S=%lf",simpson(0,1,50));
  return (0);
}

double simpson(double a, double b, double n)
{
  double S,h;
	int i;
	
	h=(b-a)/(2.0*n);
	
	S=(f(a)+f(b));
	for (i=1;i<n;i++){
		S += 4.0*f(a+(2.0*i-1.0)*h)+2.0*f(a+2.0*i*h);
	}
	S += 4.0*f(a+(2.0*n-1.0)*h);
	S *= h/3.0;
	
	return S;
}

/* 関数の定義 */
double f(double x)
{
  return 4/(1+pow(x,2));   /* 穴埋め箇所5 */
}
