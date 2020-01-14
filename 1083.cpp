#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int> countMap;
    for (int i=0; i<n; i++){
        int temp;
        cin >> temp;
        countMap[abs(temp - i - 1)]++;
    }
    //map自动按key从小到大排序，故反向遍历map
    for (map<int, int>::reverse_iterator rit = countMap.rbegin(); rit!=countMap.rend(); ++rit){
        //题目要求有重复
        if (rit->second > 1){
            cout << rit->first << " " << rit->second << endl;
        }
    }
    return 0;
}



