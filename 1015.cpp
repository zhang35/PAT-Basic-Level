//#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Student{
    int id;
    int moral;
    int talent;
};

bool cmp(Student s1, Student s2){
    int sum1 = s1.moral + s1.talent;
    int sum2 = s2.moral + s2.talent;
    if (sum1==sum2) {
        if (s1.moral == s2.moral){
            return s1.id < s2.id;
        }
        else {
            return s1.moral > s2.moral;
        }
    }
    else {
        return sum1 > sum2;
    }
}

int main()
{
    int n;
    int l;
    int h;

    //cin >> n >> l >> h;
    scanf("%d%d%d", &n, &l, &h);

    vector <vector<Student> > t(4);  //分为4档

    int m = 0;
    for (int i=0; i<n; i++){
        Student stu;
        //cin >> stu.id >> stu.moral >> stu.talent;
        scanf("%d%d%d", &stu.id, &stu.moral, &stu.talent);
        if (stu.moral>=l && stu.talent>=l){
            if (stu.moral>=h && stu.talent>=h){
                t[0].push_back(stu);
            }
            else if (stu.moral>=h){
                t[1].push_back(stu);
            }
            else if (stu.moral>=stu.talent){
                t[2].push_back(stu);
            }
            else {
                t[3].push_back(stu);
            }
            m++;
        }
    }
    
    //cout << m << endl;
    printf("%d\n", m);

    for (int i=0; i<4; i++){
        sort(t[i].begin(), t[i].end(), cmp);
        for (int j=0; j<t[i].size(); j++){
            //cout << t[i][j].id << " "<< t[i][j].moral << " "<< t[i][j].talent << endl;
            printf("%d %d %d\n", t[i][j].id, t[i][j].moral, t[i][j].talent);
        }
    }

    return 0;
}
