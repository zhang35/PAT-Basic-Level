#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(long n){
    //用pow(n, 0.5)效率低下，sqrt效率高
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int l, k;
    string n;
    cin >> l >> k >> n;
    bool found = false;
    for (int i=0; i+k<=l; i++){
        string s = n.substr(i, k);
        long temp = stol(s);
        if (isPrime(temp)){
            found = true;
            cout << s << endl;
            break;
        }
    }
    if (!found){
        cout << "404" << endl;
    }
    return 0;
}
