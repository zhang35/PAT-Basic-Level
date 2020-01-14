#include <iostream>
#include <algorithm>
using namespace std;

bool isPalin(string s){
    int len = s.length();
    for (int i=0; i<len/2; i++){
        if (s[i]!=s[len-i-1]){
            return false;
        }
    }
    return true;
}
string addString(string a, string b){
    if (a.length()<b.length()){
        swap(a, b);
    }
    for (int i=b.length(); i<a.length(); i++){
        b = '0' + b;
    }
    string str = "";
    int carry = 0;
    for (int i=a.length()-1; i>=0; i--){
        char ch = a[i] + b[i] - 48 + carry;
        if (ch > '9'){
            carry = 1;
            ch -= 10;
        }
        else{
            carry = 0;
        }
        str = ch + str;
    }
    if (carry > 0){
        str = '1' + str;
    }
    return str;
}

int main()
{
    string a, b;    
    cin >> a;
    bool isFound = false;
    for (int i=0; i<10; i++){
        if (isPalin(a)){        
            cout << a << " is a palindromic number." << endl;
            isFound = true;
            break;
        }
        b = a; 
        reverse(b.begin(), b.end());
        string c = addString(a, b);
        cout << a << " + " << b << " = " << c << endl;
        a = c;
    }
    if (!isFound){
        cout << "Not found in 10 iterations." << endl;
    }
    return 0;
}

