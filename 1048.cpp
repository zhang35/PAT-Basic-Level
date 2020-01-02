#include <iostream>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    int i = a.length()-1;
    int j = b.length()-1;
    if (j<i){
        for (int k=0; k<i-j; k++){
            b = '0' + b;
        }
        j = i;
    }
    bool flag = true;
    while (i>=0 && j>=0){
        //奇数位
        if (flag){
            b[j] = (a[i] + b[j] - 5) % 13 + 48; 
            if (b[j]==58){
                b[j] = 'J';
            }
            else if (b[j]==59){
                b[j] = 'Q';
            }
            else if (b[j]==60){
                b[j] = 'K';
            }
        }
        else {
            b[j] -= a[i];
            if (b[j]<0){
                b[j] += 10;
            }
            b[j] += 48;
        }
        flag = !flag;
        i--;
        j--;
    }
    
    cout << b << endl;
    return 0;
}

