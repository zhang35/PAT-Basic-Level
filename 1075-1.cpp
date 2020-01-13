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
    int head, n, k;
    cin >> head >> n >> k;

    vector<Node> nodeMap(100000);
    for (int i=0; i<n; i++){
        int addr;
        cin >> addr;
        cin >> nodeMap[addr].data >> nodeMap[addr].next;
    }

    vector<Node> sortMap(100003);
    int h1 = 100000;
    int h2 = 100001;
    int h3 = 100002;
    int r1 = h1;
    int r2 = h2;
    int r3 = h3;

    for (int h=head; h!=-1; h=nodeMap[h].next){
        int data = nodeMap[h].data;
        if (data<0){
            sortMap[r1].next = h;
            r1 = h;
            sortMap[r1].data = data;
        }
        else if (data>=0 && data<=k){
            sortMap[r2].next = h;
            r2 = h;
            sortMap[r2].data = data;
        }
        else {
            sortMap[r3].next = h;
            r3 = h;
            sortMap[r3].data = data;
        }
    }
    sortMap[r3].next = -1;
    sortMap[r2].next = sortMap[h3].next;
    sortMap[r1].next = sortMap[h2].next;
    for (int h=sortMap[h1].next; h!=-1; h=sortMap[h].next){
        cout << setw(5) << setfill('0') << h << " " << sortMap[h].data << " ";
        if (sortMap[h].next!=-1){
            cout << setw(5) << setfill('0') << sortMap[h].next << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}
