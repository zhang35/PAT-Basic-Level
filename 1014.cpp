#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
    map<char, string> day;
    day['A'] = "MON";
    day['B'] = "TUE";
    day['C'] = "WED";
    day['D'] = "THU";
    day['E'] = "FRI";
    day['F'] = "SAT";
    day['G'] = "SUN";

    string s[4];
    for (int i=0; i<4; i++){
        cin >> s[i];
    }

    int i;
    //第一个数据
    for (i=0; i<s[0].length() && i<s[1].length(); i++){
        if ((s[0][i]>='A'&&s[0][i]<='G') && (s[0][i]==s[1][i])){
            cout << day[s[0][i]] << " ";
            break;
        }
    }

    //第二个数据
    i++;
    while (i<s[0].length() && i<s[1].length()){
        if (s[0][i]==s[1][i]){
            if (s[0][i]>='0'&&s[0][i]<='9'){
                cout << '0' << (int)(s[0][i]-'0') << ":";
                break;
            }
            else if (s[0][i]>='A'&&s[0][i]<='N'){
                cout << (int)(s[0][i]-'A'+10) << ":";
                break;
            }
        }
        i++;
    }
    //第三个数据
    for (i=0; i<s[2].length() && i<s[3].length(); i++){
        if ( ((s[2][i]>='a'&&s[2][i]<='z')||(s[2][i]>='A'&&s[2][i]<='Z'))
                && (s[2][i]==s[3][i]) ){
            cout << setw(2) << setfill('0') << i;
            break;
        }
    }
    cout << endl;
    return 0;
}
