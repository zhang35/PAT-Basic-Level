#include <iostream>
#include <map>
using namespace std;

int main(){ 
    int m, n, s;
    cin >> m >> n >> s;
    
    if (s>m){
        cout << "Keep going..." << endl;
    }
    else {
        map<string, int> countMap;
        for (int i=1; i<=m; i++){
            string name;
            cin >> name;
            if (i>=s && (i-s)%n==0){
                if (countMap[name]>0){
                    s++;
                    continue;
                }
                else{
                    countMap[name]++;
                    cout << name << endl;
                }
            }
        }
    }
    return 0;
}
