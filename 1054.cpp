#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

bool isNumber(string s){
    istringstream sin(s);
    double test;
    return sin >> test && sin.eof();
}

int main(){
    int n;
    cin >> n;
    string str;
    double sum = 0;
    int count = 0;
    for (int i=0; i<n; i++){
        bool islegal = true;
        cin >> str;
        double d = 0;
        if (isNumber(str)){
            d = stod(str);
            if (d<-1000 || d>1000){
                islegal = false;
            }
            else{
                int pos = str.find('.');
                if (pos!=string::npos && str.length()-3>pos){
                    islegal = false; 
                }
            }
        }
        else{
            islegal = false;
        }

        if (islegal){
            count++;
            sum += d;
        }
        else {
            cout << "ERROR: " << str << " is not a legal number" << endl;
        }
    }

    if (count==0){
        cout << "The average of 0 numbers is Undefined" << endl;
    }
    else if (count==1){
        cout << "The average of 1 number is " << fixed << setprecision(2) << sum << endl;
    }
    else{
        cout << "The average of " << count << " numbers is " << fixed << setprecision(2) << sum / count << endl;
    }
    return 0;
}

