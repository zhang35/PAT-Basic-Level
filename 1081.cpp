#include <iostream>
#include <cctype>
using namespace std;

int main(){
    int n;
    cin >> n;
    getchar(); //吸收换行符
    for (int i=0; i<n; i++){
        string s;
        getline(cin, s);
        if (s.length()<6){
            cout << "Your password is tai duan le." << endl;
        }
        else{
            bool hasDigit = false;
            bool hasAlpha = false;
            bool isOK = true;
            for (int j=0; j<s.length(); j++){
                if (isdigit(s[j])){
                    hasDigit = true;
                }
                else if (isalpha(s[j])){
                    hasAlpha = true;
                }
                else if (s[j]=='.'){
                    continue;
                }
                else {
                    isOK = false;
                    cout << "Your password is tai luan le." << endl;
                    break;
                }
            }
            if (isOK){
                if (!hasAlpha){
                    cout << "Your password needs zi mu." << endl;
                }
                else if(!hasDigit){
                    cout << "Your password needs shu zi." << endl;
                }
                else {
                    cout << "Your password is wan mei." << endl;
                }
            }
        }
    }
    return 0;
}

