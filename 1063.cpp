#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){ 
    int n;
    cin >> n;
    float maxRadius = 0;
    for (int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        float radius = a * a + b * b;
        if (radius > maxRadius){
            maxRadius = radius;
        }
    }
    maxRadius = sqrt(maxRadius);

    cout << fixed << setprecision(2) << maxRadius << endl; 
    return 0;
}

