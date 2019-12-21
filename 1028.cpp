#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    int n;
    cin >> n;

    string name;
    string date;
    string oldName;
    string youngName;
    string oldLimit = "1814/09/06";
    string youngLimit = "2014/09/06";
    string young = "0000/00/00";
    string old = "2100/00/00";
    int count = 0;
    for (int i=0; i<n; i++){
        cin >> name >> date;
        if (date >= oldLimit && date <= youngLimit){
            if (date > young){
                young = date;
                youngName = name;
            }
            if (date < old){
                old = date;
                oldName = name;
            }
            count++;
        }
    }

    if (count==0){
        cout << 0 << endl;
    }
    else {
        cout << count << " " << oldName << " " << youngName << endl;
    }
    return 0;
}

