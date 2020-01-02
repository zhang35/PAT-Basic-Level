#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sum1 = 0;
    int sum2 = 0;
    for (int i=0; i<n; i++){
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2; 

        int sum = a1 + b1;
        if (a2==sum && b2==sum){
            continue;
        }

        if (a2==sum){
            sum1++;
        }
        else if (b2==sum){
            sum2++;
        }
    }
    cout << sum2 << " " << sum1 << endl;
    return 0;
}
