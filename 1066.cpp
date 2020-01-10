#include <iostream>
using namespace std;

int main(){ 
    int m, n, a, b, sub;
    scanf("%d %d %d %d %d", &m, &n, &a, &b, &sub);
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            int temp;
            scanf("%d", &temp);
            if (j!=0){
                printf(" ");
            }
            if (temp>=a && temp<=b) {
                printf("%03d", sub);
            }
            else{
                printf("%03d", temp);
            }
        }
        printf("\n");
    }

    return 0;
}
