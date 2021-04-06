#include <iostream>
#include <vector>

using namespace std;
#define MAX_SIZE 8
const int N = 4;
int M = 4;
int numArray[MAX_SIZE];
int Visited[MAX_SIZE];
void run(int cnt, int index){

    if(index == M){
        for(int i = 0; i < M; i++){
            cout << numArray[i] << " ";
        }        
        cout << endl;
        return;
    }


    for(int i = cnt; i <= N; i++){
     
        numArray [index] = i;
        run(i + 1, index + 1);
        numArray [index] = 0;
        

    }
    
}
int main()
{
    for(int i = 0; i <= MAX_SIZE; i++){
        Visited[i] = 0;
    }
    run(1,0);

    return 0;
}