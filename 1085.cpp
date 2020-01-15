#include <iostream>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct School{
    string name;
    float points;
    int stuNum;
};

bool cmp(School s1, School s2){
    int p1 = (int)s1.points;
    int p2 = (int)s2.points;
    if (p1 == p2){
        return s1.stuNum==s2.stuNum ? s1.name<s2.name : s1.stuNum<s2.stuNum;
    }
    else{
        return p1 > p2;
    }
}

int main(){
    int n;
    cin >> n;
    unordered_map<string, School> schMap;
    for (int i=0; i<n; i++){
        string id, name;
        float score;
        cin >> id >> score >> name;
        for (int j=0; j<name.length(); j++){
            name[j] = tolower(name[j]);
        }
        if (id[0]=='B'){
            score /= 1.5;
        }
        else if(id[0]=='T'){
            score *= 1.5;
        }
        schMap[name].name = name;
        schMap[name].points += score;
        schMap[name].stuNum++;
    }

    vector<School> schVec;
    for (unordered_map<string, School>::iterator it=schMap.begin(); it!=schMap.end(); ++it){
        schVec.push_back(it->second);
    }

    sort(schVec.begin(), schVec.end(), cmp);
    cout << schVec.size() << endl;
    int rank = 1;
    for (int i=0; i<schVec.size(); i++){
        if (i>0 && (int)schVec[i].points!=(int)schVec[i-1].points){
            rank = i + 1;
        }
        cout << rank << " " << schVec[i].name << " " << (int)schVec[i].points << " " << schVec[i].stuNum << endl;
    }
    return 0;
}



