#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a, b, c;
    do{
        while (s.size() < 4){
            s += '0';
        }
        sort(s.begin(), s.end());
        b = stoi(s);
        reverse(s.begin(), s.end());
        a = stoi(s);
        c = a - b;
        printf("%04d - %04d = %04d\n", a, b, c);
        s = to_string(c);
    }while (c!=0 && c!=6174);
    return 0;
}
