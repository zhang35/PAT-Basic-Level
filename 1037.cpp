#include <stdio.h>

int main(){
    int p[3];
    int a[3];
    scanf("%d.%d.%d %d.%d.%d", &p[0], &p[1], &p[2], &a[0], &a[1], &a[2]);

    for (int i=0; i<3; i++){
        a[i] -= p[i];
    }
    int knut = a[0] * 17 * 29 + a[1] * 29 + a[2];
    if (knut<0){
        printf("-");
        knut *= -1;
    }
    a[2] = knut % 29;
    knut /= 29;
    a[1] = knut % 17;
    a[0] = knut / 17;
    printf("%d.%d.%d\n", a[0], a[1], a[2]);

    return 0;
}

