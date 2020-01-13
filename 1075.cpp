#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Node{
    int data;
    int next;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int head, n, k;
    cin >> head >> n >> k;

    vector<Node> nodeMap(100000);
    for (int i=0; i<n; i++){
        int addr;
        cin >> addr;
        cin >> nodeMap[addr].data >> nodeMap[addr].next;
    }

    vector<vector<int> > v(3);

    for (int h=head; h!=-1; h=nodeMap[h].next){
        if (nodeMap[h].data<0){
            v[0].push_back(h);
        }
        else if (nodeMap[h].data>=0 && nodeMap[h].data<=k){
            v[1].push_back(h);
        }
        else {
            v[2].push_back(h);
        }
    }
    bool isFirst = true;
    for (int i=0; i<3; i++){
        //next已经变动了，只有值和data是有用的
        for (int j=0; j<v[i].size(); j++){
            int addr = v[i][j];
            if (isFirst){
                cout << setw(5) << setfill('0') << addr << " " << nodeMap[addr].data << " ";
                isFirst = false;
            }
            else{
                cout << setw(5) << setfill('0') << addr << endl;
                cout << setw(5) << setfill('0') << addr << " " << nodeMap[addr].data << " ";
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}

