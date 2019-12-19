#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> n(10);
    for (int i=0; i<10; i++){
        cin >> n[i];
    }

    int i = 1;
    //若存在0
    if (n[0]>0){
       //输出1个第一个非0位
       while (n[i]==0) {
           i++;
       }
       cout << i;
       n[i]--;

       //输出所有0
       while (n[0]>0){
           cout << 0;
           n[0]--;
       }
    }

    while (i<10) {
        while (n[i]>0){
            cout << i;
            n[i]--;
        }
        i++;
    }

    cout << endl;
    return 0;
}
