#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    int maxScore = 0;
    int maxGroup = 0;
    vector<int> score(1000);
    for (int i=0; i<n; i++){
        string s;
        int temp;
        cin >> s >> temp;

        int group = stoi(s.substr(0, s.find('-')));
        score[group-1] += temp;
        if (score[group-1] > maxScore){
            maxScore = score[group-1];
            maxGroup = group;
        }
    }

    cout << maxGroup << " " << maxScore << endl;
    return 0;
}
