#include <iostream>
#include <vector>

using namespace std;

// 바이러스(2606)

int DFS(int start, vector<vector<int>> graph, bool visited[], int count){
    visited[start] = true;
    count ++;
    for(int i=0; i<graph[start].size(); i++){

        if(graph[start][i] == 1 && visited[i] == false){
            cout << start << " -> " << i << endl;
            cout <<" 감염: " << count << endl;
            count = DFS(i, graph, visited, count);
        }
    }
    return count;
}

vector< vector<int> > init(bool visited[], vector< vector<int> >graph, int comSize){
        fill(visited, visited+comSize, false);

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



    for(int i=0; i<edgeSize; i++){
        cin >> fromEdge >> toEdge;
        graph[fromEdge][toEdge] = 1;
        graph[toEdge][fromEdge] = 1;

    }
    

    for(int i=0; i<comSize; i++){
        for(int j=0; j<comSize; j++){
             cout << graph[i][j] << " " ;
        }
        cout << endl;
    }

    cin >> start;
    
    DFS(start, graph, visited, 0);
    
    return 0;
}