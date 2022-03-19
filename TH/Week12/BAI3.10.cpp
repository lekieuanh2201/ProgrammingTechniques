/*Bài tập 10: Khoảng cách Hamming*/

#include<iostream>
using namespace std;

int N, H;
int x[20];

void print_sol(){
    for (int i = 1; i <= N; i++){
        cout << x[i];
    }
    cout << endl;
}
void TRY(int i, int j, int old_L){
    x[i] = j;
    int L = j ? ++old_L : old_L;
    if (i == N ){
        if (L == H){
            print_sol();
            return;
        }
        return ;
    }
    TRY(i+1, 0, L);
    TRY(i+1, 1, L);
}
int main(){
    int k1[20], k2[20];
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> k1[i] >> k2[i];
    }
    for (int i = 0; i < t; i++){
        N = k1[i];
        H = k2[i];
        TRY(1, 0, 0);
        TRY(1, 1, 0);
        cout << endl;
    }
    return 0;
}
