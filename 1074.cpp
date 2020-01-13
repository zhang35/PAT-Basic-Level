#include <iostream>
using namespace std;

int main(){
    string pat, a, b;
    cin >> pat >> a >> b;

    //将a、b与pat对齐
    int len = pat.length();
    for (int i=a.length(); i<len; i++){
        a = '0' + a;
    }
    for (int i=b.length(); i<len; i++){
        b = '0' + b;
    }

    int addition = 0;
    for (int i=len-1; i>=0; i--){
        int sum = a[i] - 48 + b[i] - 48 + addition;
        int digit = pat[i] - 48;
        if (digit == 0){
            digit = 10;
        }
        addition = sum / digit;
        sum = sum % digit;
        a[i] = sum + 48;
    }

    if (addition>0){
        cout << addition << a;
    }
    else{
        //a可能是20位整数，用数值类型容易越界
        bool flag = false;
        for (int i=0; i<len; i++){
            if (a[i]!='0' || flag){
                cout << a[i];
                flag = true;
            }
        }
        if (!flag){
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}
