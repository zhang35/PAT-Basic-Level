#include <iostream>
#include <vector>
using namespace std;

void PrintArray(vector<int> a);//打印数组

void PrintArray(vector<int> a) {
    vector<int>::iterator it=a.begin();
    cout << *it;
    it++;
    while (it!=a.end()){
        cout << " " << *it;
        it++;
    }
    cout<<endl;
}

int main(){
    int n;
    int offset;

    cin >> n >> offset;
    offset %= n;
    
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    //若n不能整除offset，则一次循环就能遍历到所有元素
    int loops = 1;

    if (offset==0){
        loops = 0;
    }
    else if (n%offset==0){
        loops = offset;
    }
    for (int i=0; i<loops; i++){
        int start = i;

        //只申请2个额外空间，谁腾地方，下一个就移动谁。
        int cur = a[i];
        int next;

        int pos = i;
        do {
            pos = (pos + offset) % n;

            next = a[pos];
            a[pos] = cur;
            cur = next;
        }while (pos!=start);
    }
    PrintArray(a);
    return 0;
}
