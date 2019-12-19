#include <iostream>
//#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n;

     do {
        while (s.length()<4){
            s = '0' + s;
        }
        sort(s.begin(), s.end());
        int sum1 = 0;
        int sum2 = 0;
        int multi = 1;
        for (int i=0; i<4; i++){
            int value = s[i] - 48;
            sum2 = sum2 * 10 + value;
            sum1 += multi * value;  
            multi *= 10;
        }
        n = sum1 - sum2;
        printf("%04d - %04d = %04d\n", sum1, sum2, n);
        //cout << setw(4) << setfill('0') << sum1  << " - " << setw(4) << setfill('0') << sum2  << " = " << setw(4) << setfill('0') << n << endl;
        s = to_string(n);
    } while (n!=6174 && n!=0) ;

    return 0;
}
