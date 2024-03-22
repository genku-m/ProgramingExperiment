#include <stdio.h>
#include <math.h>
int main(void){
	double height[11] ={168,162,171,159,174,165,175,179,168,182,179};
	double weight[11] ={60,55,65,60,72,59,61,69,56,73,62};
	int hlength = (int)sizeof(height) / sizeof(height[0]);
    int wlength = (int)sizeof(height) / sizeof(height[0]);
    // ソート前に偏差積和を出す
    double sumh = 0, sumw = 0;
	for (int i = 0; i < hlength; i++) {
    	sumh += height[i];
	}
    for (int i = 0; i < wlength; i++) {
    	sumw += weight[i];
	}
    
    double aveh = sumh/11,avew =sumw/11;
    double sdheight, sdweight,temph=0,tempw=0;
    for (int i=0; i <  hlength; ++i) {
       temph += pow(height[i] - aveh,2);
    }
    sdheight = sqrt((1/(double)hlength)*temph);
    for (int i=0; i <  wlength; ++i) {
       tempw += pow(weight[i] - avew,2);
    }
    sdweight = sqrt((1/(double)wlength)*tempw);

    double sdhw, temphw = 0;
    for (int i=0; i <  hlength; ++i) {
       temphw += (height[i] - aveh)*(weight[i] - avew);
    }
    sdhw = (1/(double)wlength)*temphw;

    // ソート
	for (int i=0; i <  hlength; ++i) {
        for (int j=i+1; j <  hlength; ++j) {
            if (height[i] > height[j]) {
                double tmp;
                tmp =  height[i];
                height[i] =  height[j];
                height[j] = tmp;
            }
        }
    }
    for (int i=0; i <  wlength; ++i) {
        for (int j=i+1; j <  wlength; ++j) {
            if (weight[i] > weight[j]) {
                double tmp;
                tmp =  weight[i];
                weight[i] =  weight[j];
                weight[j] = tmp;
            }
        }
    }
	printf("身長の最大値:%gcm\n",height[hlength-1]);
	printf("体重の最大値:%gkg\n",weight[wlength-1]);
	printf("身長の最小値:%gcm\n",height[0]);
	printf("体重の最小値:%gkg\n",weight[0]);
	printf("身長の平均値:%gcm\n",aveh);
	printf("体重の平均値:%gkg\n",avew);	
    printf("身長の中央値:%gcm\n",height[(11+1)/2-1]);
    printf("体重の中央値:%gkg\n",weight[(11+1)/2-1]);
    printf("身長の標準偏差:%gcm\n",sdheight);
    printf("体重の標準偏差:%gkg\n",sdweight);
    printf("身長、体重の相関関数:%g\n",sdhw/(sdheight*sdweight));
  return 0;
}
