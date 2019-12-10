#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
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

    int count = 0;
    int pre = 3;
    for (int i=5; i<=n; i++){
        if (isPrime(i)){
            if (i-pre == 2){
                count++;
            }
            pre = i;
        }
    }

    cout << count << endl;
    return 0;
}
