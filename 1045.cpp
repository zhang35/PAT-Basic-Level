#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> b(a);
    sort(a.begin(), a.end());

    int max = 0;
    vector<int> c;
    for (int i=0; i<n; i++){
        if (a[i]==b[i] && b[i]>max){
            c.push_back(a[i]);
        }
        if (b[i]>max){
            max = b[i];
        }
    }

    cout << c.size() << endl;
    if (c.size()>0){
        sort(c.begin(), c.end());
        cout << c[0];
        for (int i=1; i<c.size(); i++){
            cout << " " << c[i];
        }
    }
    cout << endl;
    return 0;
}
