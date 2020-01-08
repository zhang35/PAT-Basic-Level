#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct people{
    string name;
    int height;
};

bool cmp(people p1, people p2){
    if (p1.height==p2.height){
        return p1.name < p2.name;
    }
    else {
        return p1.height > p2.height;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<people> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i].name >> p[i].height;
    }
    sort(p.begin(), p.end(), cmp);

    int count = 0;
    for (int i=0; i<k; i++){
        int len = n / k;
        if (i==0){
            len += n % k;
        }
        if (len==0){
            break;
        }
        vector<string> names(len);
        int mid = len / 2;
        names[mid] = p[count++].name;
        int d = -1;
        for (int j=1; j<len; j++){
            names[mid+d] = p[count++].name;
            d = -d;
            if (d<0){
                d--;
            }
        }
        cout << names[0];
        for (int j=1; j<len; j++){
            cout << " " << names[j];
        }
        cout << endl;
    }
    return 0;
}
