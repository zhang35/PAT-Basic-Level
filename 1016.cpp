#include <iostream>
using namespace std;

int main()
{
    string a;
    char d;

    int sum = 0;

    for (int i=0; i<2; i++){
        cin >> a >> d;
        int p = 0;
        int num = d - 48;
        for (int j=0; j<a.length(); j++){
            if (a[j]==d){
                p = p * 10 + num;
            }
        }
        sum += p;
    }

    cout << sum << endl;
    return 0;
}
