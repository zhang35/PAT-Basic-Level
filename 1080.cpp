#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Student{
    string id;
    int online;
    int midScore;
    int endScore;
    int total;
};

bool cmp(Student s1, Student s2){
    return s1.total==s2.total ? s1.id<s2.id : s1.total>s2.total;
}

int main(){
    int p, m, n;
    cin >> p >> m >> n;
    map<string, int> online;
    for (int i=0; i<p; i++){
        string id;
        int score;
        cin >> id >> score;
        if (score>=200){
            online[id] = score;
        }
    }
    map<string, int> mid;
    for (int i=0; i<m; i++){
        string id;
        int score;
        cin >> id >> score;
        mid[id] = score;
    }
    map<string, int> end;
    for (int i=0; i<n; i++){
        string id;
        int score;
        cin >> id >> score;
        end[id] = score;
    }

    vector<Student> stuList;
    for (map<string, int>::iterator it=online.begin(); it!=online.end(); ++it){
        string id = it->first;
        int midScore = -1;
        if (mid.find(id)!=mid.end()){
           midScore = mid[id];
        }
        int endScore = -1;
        if (end.find(id)!=end.end()){
            endScore = end[id];
        }

        int total = 0;
        if (endScore!=-1){
            if (midScore>endScore){
                total = (int)(midScore * 0.4 + endScore * 0.6 + 0.5);  //+0.5四舍五入
            }
            else {
                total = endScore;
            }
        }

        if (total >= 60){
            Student s;
            s.id = id;
            s.online = it->second;
            s.midScore = midScore;
            s.endScore = endScore;
            s.total = total;
            stuList.push_back(s);
        }
    }
    sort(stuList.begin(), stuList.end(), cmp);
    for (int i=0; i<stuList.size(); i++){
        cout << stuList[i].id << " " << stuList[i].online << " " << stuList[i].midScore << " " << stuList[i].endScore << " " << stuList[i].total << endl;
    }
    return 0;
}

