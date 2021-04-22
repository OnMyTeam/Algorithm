#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int vertex = 7;
const int edge = 9;
bool visit[vertex];
vector<int> graph[vertex];

void BFS(int start){
    queue<int> qu;
    visit[start] = true;
    qu.push(start);
    while(!qu.empty()){
        int x = qu.front();
        qu.pop();
        for(int i=0; i<graph[x].size(); i++){
            int next = graph[x][i];
            if(!visit[next]){
                // 연결된 번호를 queue에 쌓음
                qu.push(next);
                // 연결된 번호를 방문여부 체크
                visit[x] = true;                
            }
        }

    }
}

int main(){
   

    for(int i=0; i<edge; i++){
        int fromEdge, toEdge;
        cin >> fromEdge >> toEdge;
        // 정점과 정점사이의 연결
        // 무방향이기 때문에 서로 연결한다.
        cout << fromEdge << " -> " << toEdge << endl;
        graph[fromEdge].push_back(toEdge);
        graph[toEdge].push_back(fromEdge);
        
    }

    // BFS 탐색 시작
    BFS(0);

    return 0;
}