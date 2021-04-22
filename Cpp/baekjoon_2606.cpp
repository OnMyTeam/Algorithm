#include <iostream>
#include <vector>

using namespace std;

// ���̷���(2606)

// ���̷��� ���� Ž��
int DFS(int start, vector<vector<int>> graph, bool visited[], int count){
    // n�� ��ǻ�� �湮(����) ����
    visited[start] = true;
    
    for(int i=0; i<graph[start].size(); i++){

        if(graph[start][i] == 1 && visited[i] == false){
            cout << start << " -> " << i << endl;
            count ++;
            cout <<" ����: " << count << endl;
            count = DFS(i, graph, visited, count);
        }
    }
    return count;
} 
// �ʱ�ȭ
vector< vector<int> > init(bool visited[], vector< vector<int> >graph, int comSize){
        // visited �迭 false�� �ʱ�ȭ
        fill(visited, visited+comSize, false);
        // graph ���� 0���� �ʱ�ȭ(0�� ������ �ȵ������� �ǹ�)
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
    // �湮����
    bool visited[comSize];
    vector< vector<int> > graph(comSize);
    graph = init(visited, graph, comSize);

    // ��ǻ�Ϳ� ��ǻ�� ���� ����
    // ������ �׷��� �̹Ƿ�, ���� ���� ���Ѿ� ��
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