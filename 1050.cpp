#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int k;
    cin >> k;
    int n = 1;
    int m = k;
    while (n<=sqrt(k)){
        if (k%n==0){
            m = k / n;
        }
        n++;
    }
    n = k / m;

    vector<int> a(k);
    for(int i=0; i<k; i++){
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    vector<vector<int> > b(m, vector<int>(n));

    int count = k - 1;
    int round = 0;
    int i = 0;
    int j = 0;
    while (1){
        for (j=round; j<n-round; j++){
            b[i][j] = a[count];
            count--;
        }
        if (count<0) break;

        j--;
        for (i=round+1; i<m-round; i++){
            b[i][j] = a[count];
            count--;
        }
        if (count<0) break;

        i--;
        for (j=n-round-2; j>=round; j--){
            b[i][j] = a[count];
            count--;
        }
        if (count<0) break;

        j++;
        for (i=m-round-2; i>round; i--){
            b[i][j] = a[count];
            count--;
        }
        if (count<0) break;

        i++;
        round++;
    }

    for (i=0; i<m; i++){
        cout << b[i][0];
        for (j=1; j<n; j++){
            cout << " " << b[i][j];
        }
        cout << endl;
    }
    return 0;
}


