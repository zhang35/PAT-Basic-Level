#include <iostream>
#include <vector>
using namespace std;

int main(){
    //提高cin、cout效率
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> s(101);
    int n;
    int temp;

    cin >> n;
    for (int i=0; i<n; i++){
       cin >> temp; 
       s[temp]++;
    }

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> temp;
        if (i!=0){
            cout << " ";
        }
        cout << s[temp];
    }

    cout << endl;
    return 0;
}
