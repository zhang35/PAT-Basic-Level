#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    char ch;
    scanf("%d %c", &n, &ch);

    int k = sqrt((n+1)/2);  //能得到的一半层数
    int left = n - 2 * k * k + 1;
    //上半部分
    for (int i=0; i<k; i++){
        //空格数
        for (int j=0; j<i; j++){
            printf(" ");
        }
        //字符数
        for (int j=0; j<2*(k-i)-1; j++){
            printf("%c", ch);
        }
        printf("\n");
    }
    //下半部分
    for (int i=1; i<k; i++){
        //空格数
        for (int j=0; j<k-i-1; j++){
            printf(" ");
        }
        //字符数
        for (int j=0; j<2*i+1; j++){
            printf("%c", ch);
        }
        printf("\n");
    }
    printf("%d\n", left);
    return 0;
}

