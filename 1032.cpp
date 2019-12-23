#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);//解除iostream与stdio绑定，提高cin、cout效率
    cin.tie(0); //解除cin与cout的绑定，提高cin效率

    int n;
    cin >> n;

    vector<int> schoolScore(n);

    for (int i=0; i<n; i++){
        int school;
        int score;
        cin >> school >> score;
        schoolScore[school-1] += score;
    }
    
    int bestSchool = 1;
    int bestScore = schoolScore[0];
    for (int i=1; i<n; i++){
        if (schoolScore[i] > bestScore){
            bestSchool = i + 1;
            bestScore = schoolScore[i];
        }
    }
    
    cout << bestSchool << " " << bestScore << endl;
    return 0;
}
