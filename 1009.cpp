#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 0;
    vector<string> st(40); //总长度不超过80的字符串，单词间用空格隔开，最多40个单词

    while (cin>>st[n++]){
        if (getchar() == '\n')
            break;
    }

    cout << st[n-1];
    for (int i=n-2; i>=0; i--){
        cout << " "<< st[i];
    }
    return 0;
}
