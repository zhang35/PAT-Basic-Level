#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int sum = 0;
    for (int i=0; i<s.length(); i++){
        sum += s[i] - 48;
    }
    
    string pinyin[] = {"ling", "yi", "er", "san","si","wu","liu","qi","ba","jiu"};
    s = to_string(sum);
    int j = 0;
    while (j < s.length()-1){
        cout << pinyin[s[j] - 48] << " ";
        j++;
    }
    cout << pinyin[s[j] - 48] << endl;
    return 0;
}
