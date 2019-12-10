#include <iostream>
using namespace std;

int main(){
        string str;
        cin >> str;
        if (str.size()==3){
            int n = str[0] - 48;
            for (int i=0; i<n; i++){
                cout << 'B';
            }
        }
        if (str.size()>=2){
            int n = str[str.size() - 2] - 48;
            for (int i=0; i<n; i++){
                cout << 'S';
            }
        }

        int n = str[str.size() - 1] - 48;
        for (int i=1; i<=n; i++){
            cout << i;
        }
        cout << endl;
        return 0;
}
