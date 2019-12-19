#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int a, b, d;
    cin >> a >> b >> d;

    int sum = a + b;
    if (sum==0){
        cout << 0;
    }
    else{
        stack<int> s;
        while (sum!=0){
            s.push(sum % d);
            sum /= d;
        }

        while (!s.empty()){
            cout << s.top();
            s.pop();
        }
    }
    cout << endl;
    return 0;
}
