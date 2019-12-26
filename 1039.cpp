#include <iostream>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    int less = 0;
    for (int i=0; i<s2.length(); i++){
        int pos = s1.find(s2[i]);
        if (pos==string::npos){
            less++;
        }
        else{
            s1[pos] = ' ';
        }
    }
    if (less>0){
        cout << "No " << less;
    }
    else {
        cout << "Yes " << s1.length() - s2.length();
    }

    cout << endl;
    return 0;
}

