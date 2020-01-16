#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(100000);
    for (int i=0; i<n; i++){
        int g1, g2;
        cin >> g1 >> g2;
        v[g1].push_back(g2);
        v[g2].push_back(g1);
    }
    for (int i=0; i<m; i++){
        int k;
        cin >> k;
        vector<int> g(k);
        for (int j=0; j<k; j++){
            cin >> g[j];
        }
        bool isSafe = true;
        for (int j=0; j<k-1 && isSafe; j++){ //遍历到倒数第2个即可
            for (int l=0; l<v[g[j]].size() && isSafe; l++){
                for (int m=j+1; m<k; m++){
                    if (v[g[j]][l]==g[m]){
                        isSafe = false;
                        break;
                    }
                }
            }
        }
        if (isSafe){
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout << endl;
    }
    return 0;
}
