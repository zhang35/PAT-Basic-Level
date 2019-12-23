#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string key, s;
    getline(cin, key);
    getline(cin, s);
    //cin >> key >> s;

    if (key==""){
        cout << s;
    }
    else {
        bool shiftBroken = false;
        if (key.find('+')!=string::npos){
            shiftBroken = true;
        }
        for (int i=0; i<s.length(); i++){
            if ((key.find(toupper(s[i]))!=string::npos) || 
                (shiftBroken && isupper(s[i])) ){
                continue; 
            }
            cout << s[i];
        }

        cout << endl;
    }

    return 0;
}

