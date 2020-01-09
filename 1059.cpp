#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

bool isPrime(int n){
    //用pow(n, 0.5)效率低下，sqrt效率高
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    map<string, int> ids;
    vector<bool> checked(n);
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        ids[s] = i + 1;
    }

    int k;
    cin >> k;
    for (int i=0; i<k; i++){
        string s;
        cin >> s;
        cout << s << ": ";
        if (ids.find(s)==ids.end()){
            cout << "Are you kidding?" << endl;
        }
        else{
            int rank = ids[s];
            if (checked[rank-1]){
                cout << "Checked" << endl;
            }
            else {
                if (rank==1){
                    cout << "Mystery Award" << endl;
                }
                else if(isPrime(rank)){
                    cout << "Minion" << endl;
                }
                else{
                    cout << "Chocolate" << endl;
                }
                checked[rank-1] = true;
            }
        }
    }
    
    return 0;
}
