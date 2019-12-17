#include <iostream>
#include <cmath>
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

int main()
{
    int m;
    int n;
    cin >> m >> n;
    int count = 1;
    int primeNum = 0;
    int i = 2;
    while (count<m){
        if (isPrime(i)){
            count++;
        }
        i++;
    }
    while (count<n){
        if (isPrime(i)){
            count++;
            primeNum++;
            cout << i;
            if (primeNum%10==0){
                cout << endl;
            }
            else {
                cout << " ";
            }
        }
        i++;
    }
    while (!isPrime(i)){
        i++;
    }
    cout << i;
    cout << endl;
    return 0;
}
