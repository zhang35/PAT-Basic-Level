#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        float point = 0;
        cin >> point;
        
        int high = -1;
        int low = m + 1;
        int count = -2; //要去掉最高分、最低分两个
        int total = 0;
        for (int j=1; j<n; j++){
            int temp;
            cin >> temp;
            if (temp>=0 && temp<=m){
                count++;        
                if (temp>high){
                    high = temp;
                }
                if (temp<low){
                    low = temp;
                }
                total += temp;
            }
        }
        point = (point + (total - high - low) * 1.0 / count) / 2;
        //四舍五入
        cout << (int)(point+0.5) << endl;
    }
    return 0;
}

