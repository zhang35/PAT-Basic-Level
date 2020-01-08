#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int sum = 0;
    for (int i=0; i<s.length(); i++){
        if (isalpha(s[i])) {
            sum += tolower(s[i]) - 96;
        }
    }

    vector<int> count(2);
    while (sum!=0){
        count[sum%2]++;
        sum /= 2;
    }
    
    cout << count[0] << " " << count[1] << endl;
    return 0;
}
