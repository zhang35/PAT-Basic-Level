#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a, b, c;
    for (int i=0; i<n; i++){
        bool ret = false;
        cin >> a >> b >> c;
        //a,b异号或者有一个0直接算。
        if ((int)(a^b)<0 || (int)(a&b)==0){
            if (a+b>c){
                ret = true;
            }
        }
        //a b c同号的情况下
        else if((int)(a^c)>0){
            if (b>(c-a)){
                ret = true;
            }
        }
        //a b同号，a c异号
        else if (a>0){
            ret = true;
        }
        string s;
        if(ret){
            s = "true";
        }
        else{
            s = "false";
        }
        cout << "Case #" << i+1 << ": " << s << endl;
    }
    return 0;
}
