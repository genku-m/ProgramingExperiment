#include <stdio.h>
#include <math.h>

int main(void) {
    double y = 1.0;
    double t = 0.0;

    double dt = 0.025;
    while (t < 10.0) {
        t += dt;
        y += dt * y;
        printf("%f,%f \n",t,y);
    }
    return 0;
}
