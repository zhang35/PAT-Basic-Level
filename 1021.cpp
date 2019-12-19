#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> n(10);

    for (int i=0; i<s.length(); i++){
        n[s[i]-48]++;
    }

    for (int i=0; i<10; i++){
        if (n[i]!=0){
            cout << i << ":" << n[i] << endl;
        }
    }
    return 0;
}
