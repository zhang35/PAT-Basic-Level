#include <iostream>
#include <cctype>
using namespace std;

void encode(string s){
     int i = 0;
     while (i<s.length()){
         char ch = s[i];
         int count = 1;
         i++;
         while (s[i]==ch){
             count++;
             i++;
         }
         if (count>1){
             cout << count;
         }
         cout << ch;
     }
     cout << endl;
}
void decode(string s){
     int i = 0;
     while (i<s.length()){
         string temp = "";
         while (isdigit(s[i])){
             temp += s[i];
             i++;
         }
         int count = 1;
         if (temp!=""){
            count = stoi(temp);
         }
         for (int j=0; j<count; j++){
            cout << s[i];
         }
         i++;
     }
     cout << endl;
}
int main()
{
    char ch;
    cin >> ch;
    getchar();
    string s;
    getline(cin, s);

    if (ch=='C'){
        encode(s);
    }
    else if (ch=='D'){
        decode(s);
    }
    return 0;
}

