#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

/**********************************************
 generate-data.c
 
 y = ax + b + e (eはN(0,1)) から x,y を生成するプログラム

 **********************************************/

#define randDouble ((double)rand()+1.0)/((double)RAND_MAX+2.0) // 0以上1未満の実数値の乱数を生成

double rand_normal(double mu, double sigma)
{
  double e = sqrt(-2.0*log(randDouble)) * sin(2.0*M_PI*randDouble);
  return mu + sigma*e;
}

int generate_data(int argc, char *argv[])
{
  FILE *file;
  // ファイルを書き込みモードでオープン
  file = fopen(argv[1], "w");
  
  if (file == NULL){
        printf("ファイルをオープンできませんでした。\n");
        return 1;
  }

  int i, n = 100;
  double a = 0.7, b = 1.2, e;
  double x, y;

  if(argc >= 2)
    n = atoi(argv[2]);

  srand((unsigned int)time(NULL));
  rand();
  for(i=0; i<n; i++){
    x = randDouble * 10.0;
    e = rand_normal(0,1);
    y = a * x + b + e;
    fprintf(file, "%.3lf,%.3lf\n",x,y);
  }
  printf("ファイル %s を生成しました。\n", argv[1]);
  sleep(1);
}
