#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int p = 0;
    int pa = 0;
    int pat = 0;
    for (int i=0; i<s.length(); i++){
        if (s[i]=='P'){
            p++;
        }
        else if(s[i]=='A'){
           pa += p; 
           pa %= 1000000007;
        }
        else if(s[i]=='T'){
            pat += pa;
            pat %= 1000000007;
        }
    }
    cout << pat << endl;
    return 0;
}

