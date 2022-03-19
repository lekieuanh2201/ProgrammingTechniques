/* Bài tập 5: DFS*/
#include<bits/stdc++.h>
using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1

    /*# YOUR CODE HERE #*/
    while (!S.empty()){
        int t = S.top();
        if (!visited[t]){
            visited[t] = true;
            cout << t << endl;
        }
        if (!adj[t].empty()){
            int f = adj[t].front();
            adj[t].pop_front();
            if(!visited[f]){
                S.push(f);
            }
        }
        else{
            S.pop();
        }
    }
    /*****************/
}
int main(){
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);
    return 0;
}
