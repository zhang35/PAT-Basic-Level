#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<string> ids;
    for (int i=0; i<m; i++){
        string id;
        cin >> id;
        ids.insert(id);
    }

    int n1 = 0;
    int n2 = 0;
    for (int i=0; i<n; i++){
        string name;
        int k;
        cin >> name >> k;
        string s = "";
        for (int j=0; j<k; j++){
            string id;
            cin >> id;
            if (ids.find(id)!=ids.end()){
                n2++;
                s = s + " " + id;
            }
        }
        if (s!=""){
            n1++;
            cout << name << ":" << s << endl;
        }
    }
    cout << n1 << " " << n2 << endl;
    return 0;
}


