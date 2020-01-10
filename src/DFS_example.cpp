#include<iostream>
#include<stack>
#include <vector>


using namespace std;

const int vertex = 7;
const int edge = 9;
bool visit[vertex];
vector<int> graph[vertex];

void DFS(int start){

    stack<int> stk;
    stk.push(start);
    int y = -1;
    while(!stk.empty()){
        
        int x = stk.top();
        stk.pop();
        if(!visit[x]){
            visit[x] = true;
            
            if(y != -1){
                cout << y << "-> " << x << endl;
            }
            
            for(int i=graph[x].size() - 1; i>=0; i--){
                int next = graph[x][i];
                if(!visit[next]){
                    stk.push(next);
                }
            }
        }
        y = x;

    }

}

int main(){

    for(int i=0; i<edge; i++){
        int fromEdge, toEdge;
        cin >> fromEdge >> toEdge;
        // 정점과 정점사이의 연결
        // 무방향이기 때문에 서로 연결한다.
        graph[fromEdge].push_back(toEdge);
        graph[toEdge].push_back(fromEdge);
        
    }

    // BFS 탐색 시작
    DFS(0);

    return 0;
}