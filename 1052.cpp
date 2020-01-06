#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<string> > face(3);
    for (int i=0; i<3; i++){
        string s;
        getline(cin, s);
        int pos1 = -1;
        while(1) {
            pos1 = s.find("[", pos1+1);
            int pos2 = s.find("]", pos1);
            if (pos1==string::npos || pos2==string::npos){
                break;
            }
            face[i].push_back(s.substr(pos1+1, pos2-pos1-1));
        }
    }

    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        vector<int> nums(5);
        for (int j=0; j<5; j++){
            cin >> nums[j];
        }
        if (nums[0]>face[0].size() || nums[1]>face[1].size() || nums[2]>face[2].size() || nums[3]>face[1].size() || nums[4]>face[0].size()
                || nums[0]<1 || nums[1]<1 || nums[2]<1 || nums[3]<1 || nums[4]<1 ){
                cout << "Are you kidding me? @\\/@" << endl;
        }
        else{
            cout << face[0][nums[0]-1] << '(' << face[1][nums[1]-1] << face[2][nums[2]-1] << face[1][nums[3]-1] << ')' << face[0][nums[4]-1] << endl;
        }
    }
    return 0;
}

