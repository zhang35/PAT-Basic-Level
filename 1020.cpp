#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Mooncake{
    float value;
    float stock;
    float price;
};

bool cmp(Mooncake a, Mooncake b){
    return a.price > b.price;
}

int main()
{
    int n;
    int d;
    scanf("%d %d", &n, &d);
    
    vector<Mooncake> mooncakes(n);
    for (int i=0; i<n; i++){
        scanf("%f", &mooncakes[i].stock);
    }
    for (int i=0; i<n; i++){
        scanf("%f", &mooncakes[i].value);
        mooncakes[i].price = mooncakes[i].value / mooncakes[i].stock;
    }

    sort(mooncakes.begin(), mooncakes.end(), cmp);

    int i = 0;
    float sum = 0;
    while (d>0 && i<n){
        if (mooncakes[i].stock > d){
            sum += mooncakes[i].price * d;
            break;
        }
        else {
            sum += mooncakes[i].value;
            d -= mooncakes[i].stock;
            i++;
        }
    }

    printf("%0.2f\n", sum);
    return 0;
}
