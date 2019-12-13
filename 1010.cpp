#include <iostream>
#include <vector>
using namespace std;

int main(){
    int i = 0;
    vector<int> array;
    int temp;
    while (cin>>temp){
        array.push_back(temp);
        i++;
        if (getchar() == '\n')
            break;
    }

    if (array[1]==0){
        cout << "0 0" << endl;
        return 0;
    }

    cout << array[0] * array[1] << " " << array[1] - 1;
    for (int j=2; j<i; j+=2){
        if (array[j+1]==0){
            break;
        }
        cout << " " << array[j] * array[j+1] << " " << array[j+1] - 1;
    }
    cout << endl;
    return 0;
}
