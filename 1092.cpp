#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int maxNum = -1;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            int temp;
            cin >> temp;
            a[j] += temp;
            if (a[j]>maxNum){
                maxNum = a[j];
            }
        }
    }
    cout << maxNum << endl;
    vector<int> b;  //记录最大值id
    for (int i=0; i<n; i++){
        if (a[i]==maxNum){
            b.push_back(i+1);
        }
    }
    for (int i=0; i<b.size(); i++){
        if (i==0){
            cout << b[i];
        }
        else {
            cout << " " << b[i];
        }
    }
    cout << endl;
    return 0;
}
