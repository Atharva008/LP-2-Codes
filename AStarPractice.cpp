#include<bits/stdc++.h>
using namespace std;

int g = 0;


void Copy(int temp[], int real[]){
    for(int i = 0; i < 9; i++) temp[i] = real[i];
}


void Print(int v[]){
    for(int i = 0; i < 9; i++){
        if(i % 3 == 0) cout << '\n';
        if(v[i] == -1) cout << "_ ";
        else cout << v[i] << " ";
    }
    cout << "\n\n";
}

void moveLeft(int v[] , int idx){
    swap(v[idx] , v[idx-1]);
}

void moveRight(int v[] , int idx){
    swap(v[idx] , v[idx+1]);
}

void moveUp(int v[] , int idx){
    swap(v[idx] , v[idx-3]);
}

void moveDown(int v[] , int idx){
    swap(v[idx] , v[idx+3]);
}

int heuristic(int start[] , int goal[]){
    int h = 0;
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            if(start[i] == goal[j] and start[i] != -1){
                h += abs((j - i) / 3) + abs((j - i) % 3);
            }
        }
    }
    return h + g;
}

void moveTile(int start[] , int goal[]){
    int emptyAt = 0;
    for(int i = 0 ; i < 9 ; i++){
        if(start[i] == -1){
            emptyAt = i;
            break;
        }
    }

    int row = emptyAt / 3;
    int col = emptyAt % 3;

    int t1[9] , t2[9] , t3[9] ,t4[9];
    Copy(t1,start);
    Copy(t2,start);
    Copy(t3,start);
    Copy(t4,start);

    int f1 = INT_MAX , f2 = INT_MAX , f3 = INT_MAX , f4 = INT_MAX;

    if(col - 1 >= 0){
        moveLeft(t1, emptyAt);
        f1 = heuristic(t1, goal);
    }
    
    if(col + 1 < 3){
        moveRight(t2, emptyAt);
        f2 = heuristic(t2, goal);
    }

    if(row + 1 < 3){
        moveDown(t3, emptyAt);
        f3 = heuristic(t3, goal);
    }
    
    if(row - 1 >= 0){
        moveUp(t4, emptyAt);
        f4 = heuristic(t4, goal);
    }

    if(f1 <= f2 && f1 <= f3 && f1 <= f4 ){
        moveLeft(start, emptyAt);
    }
    else if(f2 <= f1 && f2 <= f3 && f2 <= f4 ){
        moveRight(start, emptyAt);
    }
    else if(f3 <= f1 && f3 <= f2 && f3 <= f4 ){
        moveDown(start, emptyAt);
    }
    else{
        moveUp(start, emptyAt);
    }
}

void solveEight(int start[] , int goal[]){
    g++;
    moveTile(start,goal);
    Print(start);
    int f = heuristic(start,goal);
    if(f == g){
        cout << "Solved in " << f << " Moves" << endl;
        return;
    }
    solveEight(start,goal);
}

bool solvable(int start[]){
    int inv = 0;
    for(int i = 0 ; i < 9 ; i++){
        if(start[i] <= 1) continue;
        for(int j = i + 1 ; j < 9 ; j++){
            if(start[j] == -1) continue;
            if(start[i] > start[j]) inv++;
        }
    }
    if(inv % 2 == 1) return false;
    return true;
}


int main(){

    int start[9] , goal[9];

    for(int i = 0 ; i < 9 ; i++) cin >> start[i];
    for(int j = 0 ; j < 9 ; j++) cin >> goal[j];

    Print(start);
    if(solvable(start)) solveEight(start,goal);
    else cout << "Impossible to solve" << endl;

    // for(int i = 0 ; i < 9 ; i++) cout << start[i] << ' ';
    return 0;
}