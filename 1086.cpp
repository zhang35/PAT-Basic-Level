#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    a *= b;
    bool flag = false;
    while (a!=0){
        int temp = a % 10;
        if (temp==0){
            if (flag){
                cout << temp;
            }
        }
        else{
            cout << temp;
            flag = true;
        }
        a /= 10;
    }
    cout << endl;
    return 0;
}



