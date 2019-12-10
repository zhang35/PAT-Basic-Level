#include <iostream>
#include <list>
using namespace std;

bool cmp(int a1, int a2){
    return a1 > a2;
}
int main(){
    int n;
    cin >> n;
    list<int> l(n);

    for (list<int>::iterator it=l.begin(); it!=l.end(); ++it){
        cin >> *it;
    }

    for (list<int>::iterator it=l.begin(); it!=l.end(); ++it){
        int temp = *it;
        while(temp!=1){
            if (temp%2==0){
                temp /= 2;
            }
            else{
                temp = (temp + (temp + 1) / 2);
            }
            for (list<int>::iterator it2=l.begin(); it2!=l.end(); ++it2){
                if (*it2 == temp){
                    it2 = l.erase(it2); //注意erase的用法，需要按返回值更新迭代器，防止越界
                }
            }
        }
    }

    l.sort(cmp);
    for (list<int>::iterator it=l.begin(); it!=l.end(); ++it){
        if (it!=l.begin()){
            cout << " ";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
