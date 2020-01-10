#include <iostream>
#include <vector>

using namespace std;

// 바이러스(2606)

// 바이러스 감염 탐색
int DFS(int start, vector<vector<int>> graph, bool visited[], int count){
    // n번 컴퓨터 방문(감염) 여부
    visited[start] = true;
    
    for(int i=0; i<graph[start].size(); i++){

        if(graph[start][i] == 1 && visited[i] == false){
            cout << start << " -> " << i << endl;
            count ++;
            cout <<" 감염: " << count << endl;
            count = DFS(i, graph, visited, count);
        }
    }
    return count;
} 
// 초기화
vector< vector<int> > init(bool visited[], vector< vector<int> >graph, int comSize){
        // visited 배열 false로 초기화
        fill(visited, visited+comSize, false);
        // graph 구조 0으로 초기화(0은 연결이 안되있음을 의미)
        for(int i=0; i<comSize; i++){
            vector<int> linkedV(comSize);
            graph.push_back(linkedV);
            for(int j=0; j<comSize; j++){
                graph[i].push_back(0);
            }        

        }
        return graph;
}
int main()
{
    int comSize, edgeSize;
    int fromEdge, toEdge;
    int start, count;
    
    cin >> comSize;
    cin >> edgeSize;
    // 방문여부
    bool visited[comSize];
    vector< vector<int> > graph(comSize);
    graph = init(visited, graph, comSize);

    // 컴퓨터와 컴퓨터 끼리 연결
    // 무방향 그래프 이므로, 서로 연결 시켜야 됌
    for(int i=0; i<edgeSize; i++){
        cin >> fromEdge >> toEdge;
        graph[fromEdge][toEdge] = 1;
        graph[toEdge][fromEdge] = 1;

    }

    for(int i=0; i<comSize; i++){
         cout << i << "| ";
        for(int j=0; j<comSize; j++){
             cout << graph[i][j] << " " ;
        }
        cout << endl;
    }

    cin >> start;
    
    DFS(start, graph, visited, 0);
    
    return 0;
}