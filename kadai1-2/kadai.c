#include <stdio.h>
#include <math.h>
int main(void){
	// Your code here!
	int x;
	printf("%s","BMIを計算する場合は1、標準体重を計算する場合は2を入力してください。\n");
	scanf("%d",&x);
	if (x == 1) {
    	double h,w;
        printf("%s","身長をm単位で入力してください。\n");
    	scanf("%lf",&h);
        printf("%s","体重をkg単位で入力してください。\n");
    	scanf("%lf",&w);
        printf("身長%gm,体重%gkgのBMI値は%gです。\n",h,w,w/pow(h,2));
    	return 0;
	} else if (x ==2 ) {
    	double h;
         printf("%s","身長をm単位で入力してください。\n");
    	scanf("%lf",&h);
    	printf("身長%gmの平均体重は%gkgです。\n",h,22*pow(h,2));
    	return 0;
	}else {
    	return 0;
	}
}
