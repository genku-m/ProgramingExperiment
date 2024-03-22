#include <stdio.h>
#include <math.h>
int main(void){
	double height[11] ={168,162,171,159,174,165,175,176,168,182,179};
	double weight[11] ={60,55,65,60,72,59,61,66,56,73,62};
	int hlength = (int)sizeof(height) / sizeof(height[0]);
    int wlength = (int)sizeof(height) / sizeof(height[0]);
    double a,b,s1,s2,avex,avey,temp1=0,temp2=0,sumx=0,sumy=0;
    for (int i = 0; i < hlength; i++) {
       temp1 += height[i]* weight[i];
       temp2 += pow(height[i],2);
       sumx += height[i];
       sumy += weight[i];
    }
    s1 = (1/(double)hlength)*temp1;
    s2 = (1/(double)hlength)*temp2;
    avex =(1/(double)hlength)* sumx;
    avey =(1/(double)wlength)* sumy;
    a = (s1-(avex*avey))/(s2-pow(avex,2));
    b = ((avey*s2)-(avex*s1))/(s2-pow(avex,2));
    printf("傾きa = %lf,切片b= %lf\n",a,b);
}
