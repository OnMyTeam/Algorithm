#include <iostream>
#include <vector>

using namespace std;
int N;
int cnt = 0;
int *cols;

bool possible(int level){
    for(int i=0; i < level; i++){
        if(cols[i] == cols[level] || abs(cols[level] - cols[i]) == (level - i)){
            return false;
        }
    }
    return true;
}
void queens(int level){
    //  cout << level << " " ;
    if(level == N){
        cnt ++;
        // cout << cnt << endl ;
        return;
    }
    for(int i=0; i < N; i++){
        cols[level] = i;
        if(possible(level))          
            queens(level + 1);   
    }
}

int main(){
    N = 4;
    cols = new int[N];
    vector<int> matrix[4];

    for(int i=0; i<N; i++){
        cols[i] = 0;
    }
    
    queens(0);
    cout << cnt << endl;
    return 0;
}