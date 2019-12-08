#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        bool isRight = true;
        size_t p = str.find("P");
        size_t t = str.find("T");
        //必须有P、T，且T在P后面两位以上
        if (p==string::npos || t==string::npos || (t-p)<2){
            isRight = false;
        }
        else{
            //剩下的字符必须都是A
            for (size_t j=0; j<str.size(); j++) {
                if (j!=p && j!=t){
                    if (str[j]!='A'){
                        isRight = false;
                    }
                }
            }

            //T右侧A的数量 = PT中间A的数量 * P左侧A的数量
            size_t leftA = p;
            size_t midA = t - p - 1;
            size_t rightA = str.size() - 1 - t;

            if (rightA != (midA * leftA)){
                isRight = false;
            }
        }

        if (isRight){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

}
