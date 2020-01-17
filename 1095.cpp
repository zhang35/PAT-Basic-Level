#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Info{
    string s;
    char level; 
    string room;
    string date;
    string id;
    int score;
};
struct Room{
    string name;
    int num;
};
bool cmp1(const Info &i1, const Info &i2){
    return i1.score==i2.score ? i1.s<i2.s : i1.score>i2.score;
}
bool cmp2(const Room &r1, const Room &r2){
    return r1.num==r2.num ? r1.name<r2.name : r1.num>r2.num;
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, m;
    //cin >> n >> m;
    scanf("%d %d", &n, &m);
    vector<Info> v(n);
    for (int i=0; i<n; i++){
        char temp[14];
        scanf("%s %d", temp, &v[i].score);
        v[i].s = temp;
        //cin >> v[i].s >> v[i].score;
        v[i].level = v[i].s[0];
        v[i].room = v[i].s.substr(1, 3);
        v[i].date = v[i].s.substr(4, 6);
        v[i].id = v[i].s.substr(10, 3);
    }
    sort(v.begin(), v.end(), cmp1);
    for (int i=0; i<m; i++){
        int cmd;
        char temp[7];
        scanf("%d %s",  &cmd, temp);
        //cin >> cmd >> para;
        printf("Case %d: %d %s\n", i+1, cmd, temp);
        //cout << "Case " << i+1 << ": " << cmd << " " << para << endl;
        string para = temp;
        if (cmd==1){
            bool found = false;
            for (int j=0; j<n; j++){
                if (v[j].level==para[0]){
                    found = true;
                    //cout << v[j].s << " " << v[j].score << endl;
                    printf("%s %d\n", v[j].s.c_str(), v[j].score);
                }
            }
            if (!found){
                printf("NA\n");
                //cout << "NA" << endl;
            }
        }
        else if(cmd==2){
            int num = 0;
            int totalScore = 0;
            for (int j=0; j<n; j++){
                if (v[j].room==para){
                    num++;
                    totalScore += v[j].score;
                }
            }
            if (num==0){
                //cout << "NA" << endl;
                printf("NA\n");
            }
            else{
                printf("%d %d\n", num, totalScore);
                //cout << num << " " << totalScore << endl;
            }
        }
        else if(cmd==3){
            vector<Room> r(1000); //记录考场人数，以考场号为索引
            for (int j=0; j<n; j++){
                if (v[j].date==para){
                    r[stoi(v[j].room)].name = v[j].room;
                    r[stoi(v[j].room)].num++;
                }
            }
            sort(r.begin(), r.end(), cmp2);
            if (r[0].num==0){
                printf("NA\n");
                //cout << "NA" << endl;
            }
            else{ 
                int j = 0;
                do {
                    //cout << r[j].name << " " << r[j].num << endl;
                    printf("%s %d\n", r[j].name.c_str(), r[j].num);
                    j++;
                }while(j<1000 && r[j].num!=0);
            }
        }
    }
    return 0;
}
