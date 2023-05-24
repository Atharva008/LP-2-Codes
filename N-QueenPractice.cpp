// N - QUEENS //

// #include<bits/stdc++.h>
// using namespace std;


// bool isSafe(int row , int col , vector<string> &board , int n){
//     int drow = row , dcol = col;

//     while(row >= 0 and col >= 0){
//         if(board[row][col] == 'Q') return false;
//         row--;
//         col--;
//     }
//     row = drow , col = dcol;
//     while(col >= 0){
//         if(board[row][col] == 'Q') return false;
//         col--;
//     }
//     row = drow , col = dcol;
//     while(row < n and col >= 0){
//         if(board[row][col] == 'Q') return false;
//         row++;
//         col--;
//     }
//     return true;
// }


// void solve(int col , vector<string> &board , vector<vector<string>> &ans , int n){

//     if(col == n){
//         ans.push_back(board);
//         return;
//     }

//     for(int row = 0 ; row < n ; row++){
//         if(isSafe(row,col,board,n)){
//             board[row][col] = 'Q';
//             solve(col + 1 , board , ans , n);
//             board[row][col] = '.';
//         }
//     }
// }


// int main(){

//     int n;
//     cin >> n;

//     vector<vector<string>> ans;
//     vector<string> board(n);
//     string s(n,'.');
//     for(int i = 0 ; i < n ; i++) board[i] = s;

//     solve(0,board,ans,n);

//     for(auto board : ans){
//         for(int x = 0 ; x < n ; x++){
//             for(int y = 0 ; y < n ; y++){
//                 cout << board[x][y] << ' ';
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
//     cout << endl;




//     return 0;
// }



// A - STAR //


// #include<bits/stdc++.h> 
// using namespace std;

// int g = 0;

// void Print(int start[]){
//     for(int i = 0 ; i < 9 ; i++){
//        if(i % 3 == 0) cout << endl;
//        if(start[i] == -1) cout << "_ ";
//        else cout << start[i] << ' '; 
//     }
//     cout << endl;
// }

// void moveLeft(int start[] , int idx){
//     swap(start[idx] , start[idx - 1]);
// }

// void moveRight(int start[] , int idx){
//     swap(start[idx] , start[idx + 1]);
// }

// void moveUp(int start[] , int idx){
//     swap(start[idx] , start[idx - 3]);
// }

// void moveDown(int start[] , int idx){
//     swap(start[idx] , start[idx + 3]);
// }


// int heuristic(int start[] , int goal[]){
//     int h = 0;
//     for(int i = 0 ; i < 9 ; i++){
//         for(int j = 0 ; j < 9 ; j++){
//             if(start[i] == goal[j] and start[i] != -1){
//                 h += (abs(j-i) / 3) + (abs(j-i) % 3);
//             } 
//         }
//     }
//     return h + g;
// }

// void moveTile(int start[] , int goal[]){
//     int emptyAt = 0;
//     for(int i = 0 ; i < 9 ; i++){
//         if(start[i] == -1){
//             emptyAt = i;
//             break;
//         }
//     }

//     int row = emptyAt / 3;
//     int col = emptyAt % 3;

//     int t1[9] , t2[9] , t3[9] , t4[9] , f1 = INT_MAX , f2 = INT_MAX , f3 = INT_MAX , f4 = INT_MAX;
//     for(int i = 0 ; i < 9 ; i++){
//         t1[i] = start[i]; t2[i] = start[i]; t3[i] = start[i]; t4[i] = start[i];
//     }  

//     if(col - 1 >= 0){
//         moveLeft(t1 , emptyAt);
//         f1 = heuristic(t1 , goal);
//     }

//     if(col + 1 < 3){
//         moveRight(t2 , emptyAt);
//         f2 = heuristic(t2 , goal);
//     }

//     if(row - 1 >= 0){
//         moveUp(t3 , emptyAt);
//         f3 = heuristic(t3 , goal);
//     }

//     if(row + 1 < 3){
//         moveDown(t4 , emptyAt);
//         f4 = heuristic(t4 , goal);
//     }


//     if(min({f1,f2,f3,f4}) == f1){
//         moveLeft(start,emptyAt);
//     }

//     if(min({f1,f2,f3,f4}) == f2){
//         moveRight(start,emptyAt);
//     }

//     if(min({f1,f2,f3,f4}) == f3){
//         moveUp(start,emptyAt);
//     }

//     if(min({f1,f2,f3,f4}) == f4){
//         moveDown(start,emptyAt);
//     }
// }

// void solveEight(int start[] , int goal[]){
//     g++;
//     moveTile(start,goal);
//     Print(start);

//     int f = heuristic(start,goal);
//     if(f == g){
//         cout << "Solved in : " << f << " moves" << endl;
//         return;
//     }
//     solveEight(start,goal);
// }

// bool solvable(int start[] , int goal[]){
//     int inv = 0;
//     for(int i = 0 ; i < 9 ; i++){
//         if(start[i] <= 1) continue;
//         for(int j = i + 1 ; j < 9 ; j++){
//             if(start[j] == -1) continue;
//             if(start[i] > start[j]) inv++;
//         }
//     }
//     if(inv % 2 == 1) return false;
//     return true;
// }


// int main(){

//     int start[9] , goal[9];
//     for(int i = 0 ; i < 9 ; i++) cin >> start[i];
//     for(int i = 0 ; i < 9 ; i++) cin >> goal[i];

//     Print(start);
//     if(solvable(start,goal)) solveEight(start,goal);
//     else cout << "Impossible to Solve" << endl;
//     return 0;
// }



// SELECTION SORT //

// #include<bits/stdc++.h>
// using namespace std;


// void selectionSort(vector<int> &v){
//     int min_idx = 0 , n = v.size();
//     for(int i = 0 ; i < n - 1 ; i++){
//         min_idx = i;
//         for(int j = i + 1 ; j < n ; j++){
//             if(v[i] > v[j]){
//                 min_idx = j;
//             }
//         }
//         swap(v[i] , v[min_idx]);
//     }
// }

// int main(){
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for(int i = 0 ; i < n ; i++) cin >> v[i];
//     selectionSort(v);
//     for(int i = 0 ; i < n ; i++){
//         cout << v[i] << ' ';
//     }
//     cout << endl;
//     return 0;
// }



// Djikstra's Algorithm // 

// #include<bits/stdc++.h>
// using namespace std;


// void Djikstras(int source , vector<int> &dist , vector<vector<pair<int,int>>> &adj){
//     dist[source] = 0;
//     set<pair<int,int>> s;

//     s.insert({0,source});

//     while(!s.empty()){
//         auto it = *(s.begin());
//         s.erase(it);
//         int node = it.second;
//         int dis = it.first;

//         for(auto it : adj[node]){
//             int adjNode = it.first;
//             int edgeWt = it.second;

//             if(dist[adjNode] > dis + edgeWt){
//                 dist[adjNode] = dis + edgeWt;
//                 s.insert({adjNode , dist[adjNode]});
//             }
//         }
//     }
// }

// int main(){

//     int v , e;
//     cin >> v >> e;

//     vector<vector<pair<int,int>>> adj(v);
//     for(int i = 0 ; i < e ; i++){
//         int u , v , w;
//         cin >> u >> v >> w;

//         adj[u].push_back({v , w});
//         adj[v].push_back({u , w});
//     }

//     vector<int> dist(v , INT_MAX);
//     int source;
//     cin >> source;

//     Djikstras(source,dist,adj);

//     for(int i = 0 ; i < v ; i++){
//         cout << dist[i] << ' ';
//     }
//     return 0;
// }