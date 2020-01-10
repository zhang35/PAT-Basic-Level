#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){ 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    } 

    sort(a.begin(), a.end());

    int i = n - 1;
    int count = 0;
    int e = 0;
    do{
        e = a[i] - 1;
        count++;
        i--;
    }while(count<e && i>=0);

    if (e < 0){
        e = 0;
    }
    cout << e << endl;
    return 0;
}
