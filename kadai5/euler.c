#include <stdio.h>
#include <math.h>

double f(double y) {
   return y; 
}

// Euler
void euler(double t0, double y0, double dt, double t_end) {
    double t = t0;
    double y = y0;

    while (t < t_end) {
        double k1 = dt*f(y);
        double exacty = exp(t);
        printf("Euler Method\n");
        printf("t = %f, y = %f\n", t, y);
        printf("Exact Solution\n");
        printf("t = %f, y = %f\n", t, exacty);
        printf("relative error\n");
        printf("t = %f, deltay = %e\n", t, fabs((y-exacty)/exacty));
        y += k1;
        t += dt;
    }
}

int main() {
    double t0 = 0.0;
    double y0 = 1.0;
    double dt = 0.2;
    double t_end = 10.0;

    euler(t0, y0, dt, t_end);

    return 0;
}
