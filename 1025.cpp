#include <iostream>
#include <stack>
#include <map>
using namespace std;

struct Node{
    int addr;
    int data;
    int next;
};

int main()
{
    int head, n, k;
    scanf("%d %d %d", &head, &n, &k);

    map<int, Node> nodeMap;
    for (int i=0; i<n; i++){
        Node *node = new Node();
        scanf("%d %d %d", &node->addr, &node->data, &node->next);
        nodeMap[node->addr] = *node;
    }
    //注意坑!并非所有节点都有效，需重新数有效节点数
    n = 0;
    for (int h=head; h!=-1; h=nodeMap[h].next){
        n++;
    }

    int len = n;
    int curHead = head;
    int preHead = -1;

    while (len >= k){
        int p = curHead;
        stack<int> s;
        //p从头遍历到尾
        for (int i=0; i<k-1; i++){
            s.push(p);
            p = nodeMap[p].next;
        }
        //若是第一组，将其尾作为新的总的头
        if (len==n){
            head = p;
        }
        //关联上一组的头和当前组的尾
        if (preHead!=-1){
            nodeMap[preHead].next = p;
        }
        //curHead指向下一组
        preHead = curHead;
        curHead = nodeMap[p].next;
        //反转链表
        for (int i=0; i<k-1; i++){
            nodeMap[p].next = s.top();
            p = s.top();
            s.pop();
        }
        len -= k;
    }
    nodeMap[preHead].next = curHead;
    int p = head;
    for (int i=0; i< n-1; i++){
        printf("%05d %d %05d\n", nodeMap[p].addr, nodeMap[p].data, nodeMap[p].next);
        p = nodeMap[p].next;
    }
    printf("%05d %d -1\n", nodeMap[p].addr, nodeMap[p].data);
    return 0;
}
