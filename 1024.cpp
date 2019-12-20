#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    if (s[0]=='-'){
        cout << '-';
    }

    int pos = s.find('E');
    string numString = s.substr(1, pos - 1);
    int exp = stoi(s.substr(pos+2, s.length() - pos - 1));

    if (exp==0){
        cout << numString << endl;
    }
    else {
        if (s[pos+1]=='-'){
            cout << "0.";
            while (exp>1){
                cout << 0;
                exp--;
            }
            cout << numString[0] << numString.substr(2, numString.length()-2);
        }
        else {
           cout << numString[0];
           int i = 2;
           while (exp>0 && i<numString.length()) {
               cout << numString[i];
               i++;
                exp--;
           }
           if (i<numString.length()){
               cout << "." << numString.substr(i, numString.length() - i);
           }
           else {
               while (exp>0){
                   cout << 0;
                   exp--;
               }
           }
        }
    }
    
    return 0;
}
