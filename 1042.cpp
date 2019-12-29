#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    vector<int> nums(26);
    int maxNum = 0;
    int maxIndex = 26;
    for (int i=0; i<s.length(); i++){
        if (isalpha(s[i])){
            if (isupper(s[i])){
                s[i] += 32;
            }
            int index = s[i] - 97;
            nums[index]++;
            if (nums[index]>maxNum || (nums[index]==maxNum && index<maxIndex)){
                maxNum = nums[index];
                maxIndex = index;
            }
        }
    }
    cout << (char)(maxIndex+97) << " " << maxNum << endl;
    return 0;
}

