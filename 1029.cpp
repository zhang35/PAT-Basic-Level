#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    string s1, s2;
    cin >> s1 >> s2;
    long i = 0;
    long j = 0;
    long len1 = s1.length();
    long len2 = s2.length();
    string s3 = "";
    while(i<len1 && j<len2){
        while(s1[i]!=s2[j] && i<len1){
            if (s1[i]>='a' && s1[i]<='z'){
                s1[i] -= 32; //小写转大写，a:65, A:97
            }
            if (s3.find(s1[i])==string::npos){
                s3 += s1[i];
            }
            i++;
        }
        i++;
        j++;
    }
    while (i<len1){
        if (s1[i]>='a' && s1[i]<='z'){
            s1[i] -= 32; //小写转大写，a:65, A:97
        }
        if (s3.find(s1[i])==string::npos){
            s3 += s1[i];
        }
        i++;
    }
    cout << s3 << endl;
    return 0;
}

