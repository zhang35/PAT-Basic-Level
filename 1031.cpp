#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);

    int w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    string m = "10X98765432";

    int n;
    cin >> n;

    string s;
    bool allPassed = true;
    for (int i=0; i<n; i++){
        cin >> s; 
        int z = 0;
        bool valid = true;
        for (int j=0; j<17; j++){
            if (s[j]<'0' || s[j]>'9'){
               valid = false; 
               break;
            }
            z += (s[j] - 48) * w[j];        
        }
        if (valid){
            z %= 11;
            if (m[z] != s[17]){
                cout << s << endl;
                allPassed = false;
            }
        }
        else {
            cout << s << endl;
            allPassed = false;
        }
    }

    if (allPassed){
        cout << "All passed" << endl;
    }
    
    return 0;
}
