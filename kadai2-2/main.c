#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define N 10000
double approximate(const char* filename) {
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
    remove(filename);
    return a;
}

#define randDouble ((double)rand()+1.0)/((double)RAND_MAX+2.0) // 0以上1未満の実数値の乱数を生成

double rand_normal(double mu, double sigma)
{
  double e = sqrt(-2.0*log(randDouble)) * sin(2.0*M_PI*randDouble);
  return mu + sigma*e;
}

int generate_data(const char* filename, int n)
{
    FILE *file;
    // ファイルを書き込みモードでオープン
    file = fopen(filename, "w");
    
    if (file == NULL){
            printf("ファイルをオープンできませんでした。\n");
            return 1;
    }

    int i= 100;
    double a = 0.7, b = 1.2, e;
    double x, y;

    srand((unsigned int)time(NULL));
    rand();
    for(i=0; i<n; i++){
        x = randDouble * 10.0;
        e = rand_normal(0,1);
        y = a * x + b + e;
        fprintf(file, "%.3lf,%.3lf\n",x,y);
    }
    fclose(file);
    sleep(1);
    return 0;
}

int main(int argc, char *argv[])
{
    FILE *file;
    // ファイルを書き込みモードでオープン
    int datasize = 100;
    char slopefilename[100];
    if(argc >= 2)
    datasize = atoi(argv[1]);
    sprintf(slopefilename,"slope%d.csv",datasize);
    file = fopen(slopefilename, "w");
    
    if (file == NULL){
            printf("ファイルをオープンできませんでした。\n");
            return 1;
    }
    for(int i=0; i<100; i++)
    {
        char filename[100] = "data.csv";
       
        generate_data(filename,datasize);
        double slope = approximate(filename);
        fprintf(file, "%lf\n",slope);
    }
    fclose(file);
    return 0;
}
