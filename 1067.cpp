#include <iostream>
using namespace std;

int main(){ 
    string password;
    int n;
    cin >> password >> n;
    getchar(); //吸收换行符

    string s;
    int count = 0;
    while(1){
        getline(cin, s);
        if (s=="#"){
            break;
        }
        if (s!=password){
            cout << "Wrong password: " << s << endl;
            count++;
            if (count==n){
                cout << "Account locked" << endl;
                break;
            }
        }
        else{
            cout << "Welcome in" << endl;
            break;
        }
    }
    return 0;
}
