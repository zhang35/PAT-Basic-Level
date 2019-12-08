#include <iostream>
#include <string>
using namespace std;

int main(){
    string maxName;
    string maxId;
    int maxScore = 0;

    string minName;
    string minId;
    int minScore = 100;

    string name;
    string id;
    int score;

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> name >> id >> score;
        if (score > maxScore){
            maxName = name;
            maxId = id;
            maxScore = score;
        }
        if (score < minScore){
            minName = name;
            minId = id;
            minScore = score;
        }
    }
    cout << maxName << " " << maxId << endl;
    cout << minName << " " << minId << endl;
}
