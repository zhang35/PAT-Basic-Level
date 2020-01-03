#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    //求和公式S(n) = n*a1 + 2(n-1)*a2 + 3(n-2)*a3 + ... + n*an;
    double s = 0;
    double a;
    for(int i=0; i<n; i++){
        scanf("%lf", &a);
        s += a*(i+1)*(n-i);
    }
    
    printf("%.2f", s);
    return 0;
}


