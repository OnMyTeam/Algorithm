#include <iostream>

using namespace std;
int N;
int cnt = 0;

int *cols;
int main(){
    N = 4;
    cols = new int[N+1];

    for(int i=1; i<=N; i++){
        cols[i] = 0;
        cout << cols[i] << endl;
    }
    return 0;
}