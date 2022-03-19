/*Bài tập 11. Bảo vệ lâu đài */

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int n, s;
struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b) {
        int ra, rb;
        if (a.first <= a.second) ra = a.first;
        else ra = a.second;
        if (b.first <= b.second) rb = b.first;
        else rb = b.second;
        return ra < rb;
    }
};

void TRY(vector<pair<int, int>> list, int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> Q ;
    int result = 0;
    int total_enemy = 0;
    int kill_enemy = 0;
    for(auto &enemy : list){
        total_enemy += enemy.first;
        Q.push(enemy);
    }
    while(!Q.empty() && s > 0){
        pair<int, int> tmp = Q.top();
        Q.pop();
        if(tmp.first <= tmp.second) kill_enemy += tmp.first;
        else {
            int enemy = tmp.first - tmp.second;
            Q.push({enemy, tmp.second});
            kill_enemy += tmp.second;
        }
        s -= 1;
    }
    cout << total_enemy - kill_enemy;
}
int main(){
    int n, s;
    cin >> n >> s;
    vector<pair<int, int> > list;
    int a, b;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        list.push_back({a, b});
    }
    TRY(list, s);

    return 0;
}
