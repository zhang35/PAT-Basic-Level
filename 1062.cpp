#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    int r;
    do{
        r = a % b; 
        a = b;
        b = r;
    }while (r!=0);
    return a;
}

int main(){ 
    int n1, m1, n2, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    
    float d1 = n1 * 1.0 / m1 * k;
    float d2 = n2 * 1.0 / m2 * k;
    if (d1 > d2){
        swap(d1, d2);
    }

    vector<int> ans;
    for (int i=d1+1; i<d2; i++){
        if (gcd(k, i)==1){
            ans.push_back(i);
        }
    }
    
    //题目保证至少有1个输出
    printf("%d/%d", ans[0], k);
    for (int i=1; i<ans.size(); i++){
        printf(" %d/%d", ans[i], k);
    }
    printf("\n");
    return 0;
}

