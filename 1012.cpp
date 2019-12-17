#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    vector<int> A(5);
    int n;
    cin >> n;

    int sign = 1;
    bool exist = false; //A2的计算结果可能为0，额外判断是否存在这类数

    A[4] = 0;
    int count = 0;

    int temp;
    for (int i=0; i<n; i++){
        cin >> temp;
        switch (temp%5){
        case 0: if (temp%2==0){
                    A[0] += temp;
                };
                break;
        case 1: A[1] += (temp * sign);
                sign *= -1;
                exist = true;
                break;
        case 2: A[2]++;
                break;
        case 3: A[3] += temp;
                count++;
                break;
        case 4: if (temp>A[4]) {
                    A[4] = temp;
                }
                break;
        }
    }

    if (A[0]==0){
        cout << 'N';
    }
    else{
        cout << A[0];
    }

    for (int i=1; i<5; i++){
        cout << " ";
        if (i==1){
            if (!exist){
                cout << 'N';
            }
            else{
                cout << A[1];
            }
        }
        else if (A[i]==0){
            cout << 'N';
        }
        else if(i==3){
            float average = A[3] * 1.0 / count;
            cout << setiosflags(ios::fixed) <<  setprecision(1) << average;
        }
        else {
            cout << A[i];
        }
    }
    cout << endl;
    return 0;
}
