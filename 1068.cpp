#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main(){ 
    //提高cin效率
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n, tol;
    cin >> m >> n >> tol;

    map<int, bool> duplicate;
    cout << duplicate[0];
    //矩阵四周填充-2^24，以便判断边缘点
    vector<vector<int> > a(n+2, vector<int>(m+2, -16777216));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            if (duplicate.find(a[i][j])!=duplicate.end()){
                duplicate[a[i][j]] = false;
            }
            else{
                duplicate[a[i][j]] = true; //标记此点存在了
            }
        }
    }

    int x = 0;
    int y = 0;
    int color = 0;
    int count = 0;
    bool notUnique = false;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            int temp = a[i][j];
            if (duplicate[temp]){ //该点不唯一
                continue; 
            }
            if (abs(temp-a[i-1][j-1])>tol &&
                 abs(temp-a[i-1][j])>tol &&   
                 abs(temp-a[i-1][j+1])>tol && 
                 abs(temp-a[i][j-1])>tol && 
                 abs(temp-a[i][j+1])>tol && 
                 abs(temp-a[i+1][j-1])>tol && 
                 abs(temp-a[i+1][j])>tol && 
                 abs(temp-a[i+1][j+1])>tol){
                if (count==1){
                    notUnique = true;
                    break;
                }
                x = i;
                y = j;
                color = temp;
                count++;
            }
        }
        if (notUnique){
            break;
        }
    }
    if (notUnique){
        cout << "Not Unique" << endl;
    }
    else if(count==0){
        cout << "Not Exist" << endl;
    }
    else{
        cout << "(" << y << ", " << x << "): " << color << endl;
    }
    return 0;
}
