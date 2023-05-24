#include<bits/stdc++.h>
using namespace std;

void BFS(int node , vector<int> adj[] , int v , vector<int> &vis , vector<int> &bfs){
    queue<int> q;
    bfs.push_back(node);
    q.push(node);
    vis[node] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                q.push(it);
                bfs.push_back(it);
                vis[it] = 1;
            }
        }
    }
}


void DFS(int node , vector<int> adj[] , int v , vector<int> &vis , vector<int> &dfs){
    vis[node] = 1;
    dfs.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            DFS(it,adj,v,vis,dfs);
        }
    }
}

int main(){

    int v , e;
    cin >> v >> e;
    vector<int> adj[v];

    int a,b;
    for(int i = 0 ; i < e ; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    } 
    vector<int> vis(v);
    vector<int> dfs;
    vector<int> bfs;
    BFS(2,adj,v,vis,bfs);
    DFS(2,adj,v,vis,dfs);
    for(auto it : bfs) cout << it << ' ';
    cout << endl;
    for(auto it : dfs) cout << it << ' ';
    cout << endl;

    return 0;
}