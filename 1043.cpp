#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> nums(6);
    for (int i=0; i<s.length(); i++){
        switch(s[i]){
        case 'P': nums[0]++;break;
        case 'A': nums[1]++;break;
        case 'T': nums[2]++;break;
        case 'e': nums[3]++;break;
        case 's': nums[4]++;break;
        case 't': nums[5]++;break;
        }
    }
    s = "PATest";
    int count = accumulate(nums.begin(), nums.end(), 0); 
    int i = 0;
    while(count!=0){
        if (nums[i]!=0){
            cout << s[i];
            nums[i]--;
            count--;
        }
        i = (i + 1) % 6;
    }
    return 0;
}
