#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    char a, b;

    vector<vector<int> > rec(2, vector<int>(3, 0)); //初始化二维数组rec(2)(3)
    vector<map<char, int> > win(2);
    for (int i=0; i<2; i++){
        win[i]['C'] = 0;
        win[i]['B'] = 0;
        win[i]['J'] = 0;
    }

    scanf("%d", &n);
    getchar();
    for (int i=0; i<n; i++){
        scanf("%c %c", &a, &b);
        getchar();
        if (a==b){
            rec[0][1]++;
            rec[1][1]++;
        }
        else if ((a=='C'&&b=='B') || (a=='J'&&b=='C') || (a=='B'&&b=='J')){ //b胜a
            rec[0][2]++;
            rec[1][0]++;
            win[1][b]++;
        }
        else if ((b=='C'&&a=='B') || (b=='J'&&a=='C') || (b=='B'&&a=='J')){ //a胜b
            rec[0][0]++;
            rec[1][2]++;
            win[0][a]++;
        }
    }

    for (int i=0; i<2; i++){
        printf("%d", rec[i][0]);
        for (int j=1; j<3; j++){
            printf(" %d", rec[i][j]);
        }
        printf("\n");
    }

    char maxWin;
    for (int i=0; i<2; i++){
        int temp = win[i]['B'];
        maxWin = 'B';
        if (win[i]['C'] > temp){
            temp = win[i]['C'];
            maxWin = 'C';
        }
        if (win[i]['J'] > temp){
            maxWin = 'J';
        }
        printf("%c", maxWin);
        if (i==0) {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}
