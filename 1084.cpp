#include <iostream>
using namespace std;

int main(){
    int d, n;
    cin >> d >> n;
    string s(1, d+48); //使用单个字符初始化string，重复字符1次
    for (int i=1; i<n; i++){
        string tempStr = "";
        int j = 0;
        while (j<s.length()) {
            char ch = s[j];
            int count = 1;
            j++;
            while (s[j]==ch && j<s.length()){
                count++;
                j++;
            }
            tempStr += ch;
            tempStr += (char)(count+48);
        }
        s = tempStr;
    }
    cout << s << endl;
    return 0;
}



