#include<bits/stdc++.h>
using namespace std;

void djikstras(int source , int n , vector<vector<pair<int,int>>> &adj , vector<int> &dist){
    set<pair<int,int>> s;
    s.insert({0,source});
    dist[source] = 0;

    while(!s.empty()){
        auto it = *(s.begin());
        int node = it.second;
        int dis = it.first;
        s.erase(it);

        for(auto it : adj[node]){
            int edgeWt = it.second;
            int adjNode = it.first;
            if(edgeWt + dis < dist[adjNode]){
                dist[adjNode] = edgeWt + dis;
                s.insert({dist[adjNode] , adjNode});
            }
        }
    }
}

int main(){

    int n , e;
    cin >> n >> e;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0 ; i < e ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src;
    cin >> src;
    vector<int> dist(n,1e9);
    djikstras(src , n , adj , dist);
    for(auto it : dist) cout << it << ' ';
    cout << endl;
    return 0;
}