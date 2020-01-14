#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string bestID;
    string worstID;
    int best = 10001;
    int worst = -1;
    for (int i=0; i<n; i++){
        string id;
        int x, y;
        cin >> id >> x >> y;
        int point = x * x + y * y;
        if (point < best){
            best = point;
            bestID = id;
        }
        if (point > worst){
            worst = point;
            worstID = id;
        }
    }
    cout << bestID << " " << worstID << endl;
    return 0;
}



