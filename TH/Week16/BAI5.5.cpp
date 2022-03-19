/*Bài tập 5: Năm nhuận*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a;
    cin >> n;
    bool found = false;
    while(n--){
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0)){
            found = true;
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
