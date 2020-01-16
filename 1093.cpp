#include <iostream>
#include <vector>
using namespace std;

int main(){
    string a[2];
    getline(cin, a[0]);
    getline(cin, a[1]);
    vector<bool> exist(127);
    for (int i=0; i<2; i++){
        for (int j=0; j<a[i].size(); j++){
            if (!exist[a[i][j]]){
                cout << a[i][j];
                exist[a[i][j]] = true;
            }
        }
    }
    cout << endl;
    return 0;
}

