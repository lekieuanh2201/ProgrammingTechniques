/*Bai tap 6: BFS*/
#include<bits/stdc++.h>
using namespace std;

void bfs(vector< list<int> > adj){
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1);
    /*#YOUR CODE HERE#*/
    while (!Q.empty()){
        int f = Q.front();
        if (!visited[f]){
            visited[f] = true;
            cout<<f<<endl;
        }
        if (!adj[f].empty()){
            int fl = adj[f].front();
            adj[f].pop_front();
            if (!visited[fl]){
                Q.push(fl);
            }
        }
        else{
            Q.pop();
        }
    }
    /******************/
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
    bfs(adj);
    return 0;
}
