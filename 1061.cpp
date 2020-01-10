#include <iostream>
#include <vector>
using namespace std;

int main(){ 
    int n, m;
    cin >> n >> m;
    vector<int> point(n);
    vector<int> answer(n);
    for (int i=0; i<m; i++){
        cin >> point[i];
    } 
    for (int i=0; i<m; i++){
        cin >> answer[i];
    } 

    for (int i=0; i<n; i++){
        int totalPoint = 0;
        for (int j=0; j<m; j++){
            int ans;
            cin >> ans;
            if (ans == answer[j]){
                totalPoint += point[j];
            }
        } 
        cout << totalPoint << endl;
    } 

    return 0;
}

