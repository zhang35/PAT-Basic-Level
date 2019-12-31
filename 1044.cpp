#include <iostream>
#include <cctype>
#include <string>
using namespace std;

const string low[] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const string high[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int MarsToEarth(string s){
    int h = 0;
    int l = 0;
    string hs;
    string ls;
    if (s.length()>4){
        hs = s.substr(0, 3);
        ls = s.substr(4, 3);
    }
    else {
        hs = s;
        ls = s;
    }

    for (int i=0; i<13; i++){
        if (high[i] == hs){
            h = i * 13;
            break;
        }
    }
    for (int i=0; i<13; i++){
        if (low[i] == ls){
            l = i;
            break;
        }
    }

    return h + l;
}
string EarthToMars(int i){
    string h = high[i/13];
    string l = low[i%13];
    if (h!=""){
        if (l=="tret"){
            l = "";
        }
        else{
            h += " ";
        }
    }
    return h + l;
}

int main(){
    int n;
    cin >> n;
    getchar();
    
    string s;
    for (int i=0; i<n; i++){
        getline(cin , s);
        if (isdigit(s[0])){
            cout << EarthToMars(stoi(s)) << endl;
        }
        else {
            cout << MarsToEarth(s) << endl;
        }
    }
    return 0;
}
