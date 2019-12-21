#include <iostream>
using namespace std;

int main()
{
    int c1, c2;
    cin >> c1 >> c2;
    //四舍五入
    int sec = (c2 - c1 + 50) / 100;

    int h = sec / 3600;
    sec %= 3600;

    int m = sec / 60;
    sec %= 60;
    printf("%02d:%02d:%02d\n", h, m, sec);
    return 0;
}
