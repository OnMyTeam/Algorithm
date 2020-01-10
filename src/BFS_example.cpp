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
                // ����� ��ȣ�� queue�� ����
                qu.push(next);
                // ����� ��ȣ�� �湮���� üũ
                visit[x] = true;                
            }
        }

    }
}

int main(){
   

    for(int i=0; i<edge; i++){
        int fromEdge, toEdge;
        cin >> fromEdge >> toEdge;
        // ������ ���������� ����
        // �������̱� ������ ���� �����Ѵ�.
        cout << fromEdge << " -> " << toEdge << endl;
        graph[fromEdge].push_back(toEdge);
        graph[toEdge].push_back(fromEdge);
        
    }

    // BFS Ž�� ����
    BFS(0);

    return 0;
}