#include <iostream>
#include <algorithm>
using namespace std;

string addString(string a, string b){
    string str = "";
    int carry = 0;
    for (int i=0; i<a.size(); i++){
        char ch = a[i] + b[i] + carry - '0';
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
    string a;    
    cin >> a;
    int n = 10;
    int i = 0;
    while (i<n){
        string b = a; 
        reverse(b.begin(), b.end());
        if (a==b){        
            cout << a << " is a palindromic number." << endl;
            break;
        }
        string c = addString(a, b);
        cout << a << " + " << b << " = " << c << endl;
        a = c;
        i++;
    }
    if (i==n){
        cout << "Not found in 10 iterations." << endl;
    }
    return 0;
}
