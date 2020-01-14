#include <iostream>

using namespace std;
int N;
int cnt = 0;

int *cols;

void queens(int level){

    if(level == N){
        cnt ++;
        return;
    }
    for(int i=1; i <= N; i++){
        cols[level] = i;
        
    }
}
bool possible(int level){
    for(int i=1; i < level; i++){
        if(cols[i] == cols[level] || abs(cols[i] - cols[level]) == (i - level)){
            return false;
        }
    }
    return true;
}
int main(){
    N = 4;
    cols = new int[N];

    for(int i=0; i<N; i++){
        cols[i] = 0;
        cout << cols[i] << endl;
    }
    queens(0);
    return 0;
}