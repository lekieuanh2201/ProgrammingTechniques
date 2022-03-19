/*Bài tập 12: Đếm đường đi*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
int m;
vector<int> road[50];
int mark[50];
int res = 0;

void input(){
    cin >> n >> k;
    cin >> m;
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
}
void TRY(int t, int start){
    for (int i = 0; i < road[start].size(); i++){
        int point = road[start][i];
        if (mark[point] == 0){
            mark[point] = 1;
            if( t == k) res++;
            else TRY(t+1, point);
            mark[point] = 0;
        }
    }
}
int main(int argc, char const *argv[]){
    input();
    for (int i = 1; i <= n; i++){
        memset(mark, 0, sizeof(mark));
        mark[i] = 1;
        TRY(1, i);
    }
    cout << res / 2;
    return 0;
}
