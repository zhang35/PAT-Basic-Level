#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i]; 
    }

    sort(a.begin(), a.end());
    
    int maxNum = 0;
    for (int i=0; n-i>maxNum; i++) {
        int j = i + maxNum;
        while (a[j]*1.0/a[i]<=p && j<n){
            j++;
        }
        int curNum = j - i;
        if (curNum > maxNum){
            maxNum = curNum;
        }
    }

    cout << maxNum << endl;
    return 0;
}
