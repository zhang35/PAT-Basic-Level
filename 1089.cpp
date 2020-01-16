#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1); //从1存储
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    int minWolf1 = n+1;
    int minWolf2 = n+1;
    //狼人和好人各有1个说谎，用i表示说谎狼人，j表示说谎好人
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (j==i){ //三个人序号不能重复
                continue;
            }
            for (int k=1; k<=n; k++){ //k表示另一个狼人
                if (i==k || j==k){
                    continue;
                }
                //反转两个说谎者的话
                a[i] *= -1;
                a[j] *= -1;
                //遍历所有元素，验证成立需满足两点：
                //1.除了-i、-k不能再有其它负数；2.无矛盾：不存在相反数，即不能出现+i、+k；
                bool isValid = true;
                for (int l=1; l<=n; l++){
                    if ((a[l]<0 && a[l]!=-i && a[l]!=-k) || (a[l]==i) || (a[l]==k)){
                        isValid = false;
                        break; 
                    }
                }
                //合理，保存找最小序列
                if (isValid){
                    int wolf1 = min(i, k);
                    int wolf2 = max(i, k);
                    if (wolf1<minWolf1){
                        minWolf1 = wolf1;
                        minWolf2 = wolf2;
                    }
                    else if(wolf1==minWolf1){
                        if (wolf2 < minWolf2){
                            minWolf2 = wolf2;
                        }
                    }
                }
                //验证完复原说谎者的话
                a[i] *= -1;
                a[j] *= -1; 
            }
        }
    }
    if (minWolf1 < n+1){
        cout << minWolf1 << " " << minWolf2 << endl;
    }
    else {
        cout << "No Solution" << endl;
    }
    return 0;
}
