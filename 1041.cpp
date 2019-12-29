#include <iostream>
#include <vector>
using namespace std;

struct Student{
    string id;
    int examNum;
};
int main(){
    int n;
    cin >> n;
    vector<Student> students(n);
    string id;
    int testNum, examNum;
    for (int i=0; i<n; i++){
        cin >> id >> testNum >> examNum;
        students[testNum-1].id = id;
        students[testNum-1].examNum = examNum;
    }
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> testNum; 
        cout << students[testNum-1].id << " " << students[testNum-1].examNum << endl;
    }
    return 0;
}

