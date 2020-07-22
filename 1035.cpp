#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(vector<int> a){
    cout << a[0];
    for(int i=1; i<a.size(); i++) {
        cout << " " << a[i];
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n; i++){
        cin >> b[i];
    }
    //找到第一个未排序元素位置
    int i = 1;
    while (i<n && b[i-1]<=b[i]){
        i++;
    }
    if (equal(a.begin()+i, a.end(), b.begin()+i)){
        cout << "Insertion Sort" << endl;
        sort(b.begin(), b.begin()+i+1);
    }
    else {
        cout << "Merge Sort" << endl;
        int span = 2;
        while (!equal(a.begin(), a.end(), b.begin())){
            for (i=0; i<n/span; i++){
                sort(a.begin()+i*span, a.begin()+(i+1)*span);
            }
            sort(a.begin()+i*span, a.end());
            span *= 2;
        }
        for (i=0; i<n/span; i++){
            sort(b.begin()+i*span, b.begin()+(i+1)*span);
        }
        sort(b.begin()+i*span, b.end());
    }
    printArray(b);

    return 0;
}
