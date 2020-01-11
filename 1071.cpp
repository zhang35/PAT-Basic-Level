#include <iostream>
using namespace std;

int main() {
    int t, k;
    cin >> t >> k;

    for (int i=0; i<k; i++){
        int n1, b, temp, n2;
        cin >> n1 >> b >> temp >> n2;
        if (temp>t){
            cout << "Not enough tokens.  Total = " << t << "." << endl;
        }
        else{
            //猜对
            if ( (b==0&&n2<n1) || (b==1&&n2>n1)){
                t += temp;
                cout << "Win " << temp << "!  Total = " << t << "." << endl;
            }
            else{
                t -= temp; 
                cout << "Lose " << temp << ".  Total = " << t << "." << endl;
                if (t==0){
                    cout << "Game Over." << endl;
                    break;
                }
            }
        }
    }
    return 0;
}


