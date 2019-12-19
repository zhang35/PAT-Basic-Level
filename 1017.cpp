#include <iostream>
using namespace std;

int main()
{
    string a;
    int b;
    int r = 0;
    string q = "";

    cin >> a >> b;

    //按照手算除法规则，从高位往低位计算
    for (int i=0; i<a.length(); i++){
        r = r * 10 + a[i] - 48; //被除数加上下一位
        q += (char)(r / b + 48); //当前商计入最终商里
        r = r % b; //被除数变成余数*10
    }
    
    //若q第一位是0，且并非仅有一位时，去掉最前面的0
    if (q[0]=='0' && q.length()>1){
        q = q.substr(1, q.length());
    }
    cout << q << " " << r << endl;
    return 0;
}
