#include <stdio.h>
#include <math.h>

#define N 10000
int approximate(char filename){
    int n = 0;
    double x[N],y[N];
    FILE*fp = stdin;

    fp = fopen(filename,"r");
    while(fscanf(fp,"%lf,%lf",&x[n],&y[n]) != EOF) {
        n++;
    }

    fclose(fp);
    double a,b,s1,s2,avex,avey,temp1=0,temp2=0,sumx=0,sumy=0;
    for (int i = 0; i < n; i++) {
       temp1 += x[i]* y[i];
       temp2 += pow(x[i],2);
       sumx += x[i];
       sumy += y[i];
    }
 
    s1 = (1/(double)(n))*temp1;
    s2 = (1/(double)(n))*temp2;
    avex =(1/(double)(n))* sumx;
    avey =(1/(double)(n))* sumy;
    a = (s1-(avex*avey))/(s2-pow(avex,2));
    b = ((avey*s2)-(avex*s1))/(s2-pow(avex,2));
    printf("傾きa = %g,切片b= %g\n",a,b);
}
