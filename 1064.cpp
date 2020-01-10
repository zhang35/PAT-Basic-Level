#include <iostream>
#include <set>
using namespace std;

int main(){ 
    int n;
    cin >> n;
    set<int> ss;
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        int sum = 0; 
        for (int j=0; j<s.length(); j++){
            sum += s[j] - 48;
        }
        if (ss.find(sum)==ss.end()){
            ss.insert(sum);
        }
    }

    //set会自动排序（从小到大）
    cout << ss.size() << endl;
    set<int>::iterator it=ss.begin();
    cout << *it++;
    while (it!=ss.end()){
        cout << " " << *it++;
    }
    cout << endl;
    return 0;
}
