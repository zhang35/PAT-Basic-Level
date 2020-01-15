#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m, x, y;
    cin >> m >> x >> y;
    vector<float> a(3); //甲乙丙
    bool isEnd = false; //控制跳出2重循环
    for (int i=9; i>=1; i--){
        for (int j=9; j>=0; j--){
            int t1, t2;
            if (i==j){
                continue;
            }
            else if (i>j){
                t1 = (9 * y - x) * i;
                t2 = (9 * y + 10 * x) * j;
            }
            else if (i<j){
                t1 = (9 * y + x) * i;
                t2 = (9 * y - 10 * x) * j;
            }

            if (t1==t2){
                a[0] = 10 * i + j;
                a[1] = 10 * j + i;
                a[2] = a[1] / y;
                isEnd = true;
                break;
            }
        }
        if (isEnd){
            break;
        }
    }

    if (a[0]==0){
        cout << "No Solution";
    }
    else{
        cout << a[0];
        for (int i=0; i<3; i++){
            if (m==a[i]) {
                cout << " Ping";
            }
            else if (m>a[i]) {
                cout << " Gai";
            }
            else {
                cout << " Cong";
            }
        }
    }
    cout << endl;
    return 0;
}
