#include <iostream>
#include <string>
using namespace std;

int main(){
    int m;
    cin >> m;
    for (int i=0; i<m; i++){
        int k;
        cin >> k;
        bool notFound = true;
        for (int n=1; n<10; n++){
            string s1 = to_string(n * k * k);
            string s2 = to_string(k);
            if (s1.substr(s1.size()-s2.size(), s2.size()) == s2){
                notFound = false;
                cout << n << " " << s1 << endl;
                break;
            }
        }
        if (notFound){
            cout << "No" << endl;
        }
    }
    return 0;
}
