#include <iostream>

using namespace std;
int N;
int cnt = 0;
 
int *cols;
bool possible(int level){
    for(int i=0; i < level; i++){
        if(cols[i] == cols[level] || abs(cols[i] - cols[level]) == (i - level)){
            return false;
        }
    }
    return true;
}
void queens(int level){

    if(level == N){
        cnt ++;
        return;
    }
    for(int i=0; i < N; i++){
        cols[level] = i;
        if(possible(level))
            queens(level + 1);
        
    }
}

int main(){
    N = 8;
    cols = new int[16];

    for(int i=0; i<N; i++){
        cols[i] = 0;
        cout << cols[i] << endl;
    }
    
    queens(0);
    cout << cnt << endl;
    return 0;
}