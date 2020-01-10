#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

int main(){ 
    int n;
    cin >> n;
    vector<int> couple(100000);
    for (int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        couple[a] = b+1;
        couple[b] = a+1;
    }

    int m;
    cin >> m;
    set<int> ss;
    set<int>::iterator it;
    for (int i=0; i<m; i++){
        int a;
        cin >> a;
        if (couple[a]!=0 && ss.find(couple[a]-1)!=ss.end()){
            ss.erase(ss.find(couple[a]-1));
        }
        else {
            ss.insert(a);
        }
    }

    //set会自动排序（从小到大）
    cout << ss.size() << endl;
    if (ss.size()>0){
        it = ss.begin();
        cout << setw(5) << setfill('0') << *it++;
        while (it!=ss.end()){
            cout << " " << setw(5) << setfill('0') << *it++;
        }
        cout << endl;
    }
    return 0;
}
