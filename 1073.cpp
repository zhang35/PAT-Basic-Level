#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct question{
    float point;
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

    vector<vector<int> > wrong(m, vector<int>(5));
    string mask = "abcde";
    int maxWrong = 0;

    for (int i=0; i<n; i++){
        float points = 0;
        for (int j=0; j<m; j++){
            string str;
            cin >> str;
            int rightNum = str[1] - 48;
            bool isRight = true;
            string ans = "";
            for (int k=0; k<rightNum; k++){
                cin >> str;
                ans += str[0];
            }
            for (int k=0; k<5; k++){
                int p = q[j].ans.find(mask[k]); 
                int r = ans.find(mask[k]); 
                if ((p!=string::npos && r==string::npos) ||
                        (p==string::npos && r!=string::npos)){
                    wrong[j][k]++;
                    if (wrong[j][k]>maxWrong){
                        maxWrong = wrong[j][k];
                    }
                    isRight = false;
                }
            }
            if (isRight){
                points += q[j].point;
            }
            else{
                bool isPartRight = true;
                for (int k=0; k<rightNum; k++){
                    if (q[j].ans.find(ans[k])==string::npos){
                        isPartRight = false;
                    }
                }
                if (isPartRight){
                    points += q[j].point / 2.0;
                }
            }
        }
        cout << fixed << setprecision(1) << points << endl;
    }

    if (maxWrong==0){
        cout << "Too simple";
    }
    else {
        for (int i=0; i<m; i++){
            for (int j=0; j<5; j++){
                if (wrong[i][j]==maxWrong){
                    cout << maxWrong << " "  << i+1 << "-" << mask[j] << endl; 
                }
            }
        }
    }
    return 0;
}


