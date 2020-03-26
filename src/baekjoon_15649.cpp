#include <iostream>
#include <vector>

using namespace std;
#define MAX_SIZE 8
const int N = 4;
int M = 4;
int numArray[MAX_SIZE];
int Visited[MAX_SIZE];
void run(int cnt){

    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << numArray[i] << " ";
        }        
        cout << endl;
        return;
    }


    for(int i = 1; i <= N; i++){
        if(Visited[i] == 0){
            numArray [cnt] = i;
            Visited[i] = 1;
            run(cnt + 1);
            Visited[i] = 0;
        }

    }
    
}
int main()
{
    for(int i = 0; i <= MAX_SIZE; i++){
        Visited[i] = 0;
    }
    run(0);

    return 0;
}