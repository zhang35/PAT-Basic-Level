#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int len = a[0];
    for (int i = 1; i < n; i++){
        len = (len + a[i]) / 2;
    }

    cout << len << endl;
    return 0;
}


