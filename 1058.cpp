#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct question{
    int point;
    int optionNum;
    int rightNum;
    string ans;
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<question> q(m);
    for (int i=0; i<m; i++){
        cin >> q[i].point >> q[i].optionNum >> q[i].rightNum;
        q[i].ans = "";
        for (int j=0; j<q[i].rightNum; j++){
            char ch;
            cin >> ch;
            q[i].ans += ch;
        }
    }

    vector<int> wrong(m);
    int maxWrong = 0;

    for (int i=0; i<n; i++){
        int points = 0;
        for (int j=0; j<m; j++){
            string str;
            cin >> str;
            int rightNum = str[1] - 48;
            bool isRight = true;
            if (rightNum!=q[j].rightNum){
                isRight = false;
                for (int k=0; k<rightNum; k++){
                    cin >> str; //吸收剩余选项
                }
            }
            else {
                for (int k=0; k<rightNum; k++){
                    cin >> str;
                    if (q[j].ans.find(str[0])==string::npos){
                        isRight = false;
                    }
                }
            }

            if (isRight){
                points += q[j].point;
            }
            else{
                wrong[j]++;
                if (wrong[j]>maxWrong){
                    maxWrong = wrong[j];
                }
            }
        }
        cout << points << endl;
    }

    if (maxWrong==0){
        cout << "Too simple";
    }
    else {
        cout << maxWrong; 
        for (int i=0; i<m; i++){
            if (wrong[i]==maxWrong){
                cout << " "  << i+1; 
            }
        }
    }
    cout << endl;
    return 0;
}
