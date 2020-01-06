#include <stdio.h>

int main(){
    int n;
    int d;
    float e;
    scanf("%d %f %d", &n, &e, &d);

    float prob = 0;
    float empty = 0;
    for (int i=0; i<n; i++){
        int k;
        scanf("%d", &k);
        int count = 0;
        for (int j=0; j<k; j++){
            float temp;
            scanf("%f", &temp);
            if (temp < e){
                count++;
            }
        }
        if (count > k / 2){
            if (k > d){
                empty++;
            }
            else{
                prob++;
            }
        }
    }
    
    printf("%.1f%% %.1f%%\n", prob/n*100, empty/n*100);
    return 0;
}

