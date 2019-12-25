#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long GCD(long long a, long long b){
    long long r;
    while (b!=0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

string RNString(long long a, long long b){
    string str = "";
    if (b<0){
        b = -b;
        a = -a;
    }
    long long g = GCD(abs(a), b);
    a /= g;
    b /= g;
    if (abs(a)>=b){
        str += to_string(a/b);
        if (a%b!=0){
            str += " ";
            str += to_string(abs(a)%b);
            str += "/";
            str += to_string(b);
        }
    }
    else {
        str += to_string(a);
        if (a!=0){
            str += "/";
            str += to_string(b);
        }
    }
    if (a<0){
        str = "(" + str;
        str += ")";
    }
    return str;
}

int main()
{
    string s[2];
    long long a[2], b[2];
    for (int i=0; i<2; i++){
        scanf("%lld/%lld", &a[i], &b[i]);
        s[i] = RNString(a[i], b[i]);
    }

   //加法
    long long ra = a[0] * b[1] + a[1] * b[0];
    long long rb = b[0] * b[1];
    cout << s[0] << " + " << s[1] << " = " << RNString(ra, rb) << endl;
   //减法
    ra = a[0] * b[1] - a[1] * b[0];
    rb = b[0] * b[1];
    cout << s[0] << " - " << s[1] << " = " << RNString(ra, rb) << endl;
   //乘法
    ra = a[0] * a[1];
    rb = b[0] * b[1];
    cout << s[0] << " * " << s[1] << " = " << RNString(ra, rb) << endl;
   //除法
    ra = a[0] * b[1];
    rb = b[0] * a[1];
    cout << s[0] << " / " << s[1] << " = ";
    if (rb==0){
        cout << "Inf" << endl;
    }
    else {
        cout << RNString(ra, rb) << endl;
    }
    return 0;
}
