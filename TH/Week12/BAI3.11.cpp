/*Bài tập 11: Lịch trình chụp ảnh*/

#include <bits/stdc++.h>
using namespace std;

int n, r, target[1000] , c[1000][1000], route[1000];
int cost, result;
int mark[1000];
int x[1000];

void init(){
    cost = 0;
    result = 1e8;
    memset(mark, 0, sizeof(mark));
    memset(x, 0, sizeof(x));
}
void TRY(int t, int m){
    for (int i = 2; i < m; i++){
        int point = route[i];
        if (mark[point] == 0 ){
            mark[point] = 1;
            x[t] = point;
            cost += c[ x[t-1]][point];
            if (t == m - 1){
                if (cost + c[point][x[m]] < result){
                    result = cost + c[point][x[m]];
                }
            }
            else {
                TRY(t+1, m);
            }
            mark[point] = 0;
            cost -= c[ x[t-1]][point];
        }
    }
}
int main(int argc, char const *argv[]){
    cin >> n >> r ;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (i != j && c[i][j] == 0) c[i][j] = 1e8;
        }
    }
    cin.ignore();
    for (int i = 0; i < r; i++){
        string str;
        getline(cin, str);
        stringstream stm(str);
        int m = 0;
        while ( stm >> route[++m] ) {
            continue;
        }
        m--;
        init();
        x[1] = route[1];
        x[m] = route[m];
        mark[route[1]] = 1;
        mark[route[m]] = 1;
        if (m == 2) result = c[route[1]][route[2]];
        else TRY(2, m);
        if(result >= 1e8) result = 0;
        target[i] = result;
    }
    for (int i = 0; i < r; i++) cout << target[i] << endl;
    return 0;
}
