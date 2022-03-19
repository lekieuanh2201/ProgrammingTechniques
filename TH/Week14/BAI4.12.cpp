/*Bài tập 12. Lược đồ*/

#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

long long arr[1000000];
long long n;
void TRY(){
    set<long long> height;
    for (long long i = 0; i < n; i++){
        height.insert(arr[i]);
    }
    long long res = 0;
    for(auto i = height.rbegin(); i != height.rend(); i++){
        long long tmp = *i;
        long long count = 0;
        for(long long j = 0; j < n; j++){
            if(arr[j] >= tmp) count += tmp;
            else {
                res = max(res, count);
                count = 0;
            }
        }
        res = max(res, count);
    }
    cout << res ;
}
int main(){
    cin >> n;
    for (long long i = 0; i < n; i++){
        cin >> arr[i];
    }
    TRY();
    return 0;
}
