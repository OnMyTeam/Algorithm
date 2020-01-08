#include <iostream>
#include <vector>

using namespace std;

// 연구소(14502)
vector< vector<int> > DFS(int detectNum, vector< vector<int> > graph, vector< vector<int> > matrix, bool visited[]){
    // 각 빈방 번호별 방문여부(감염여부)
    visited[detectNum] = true;
    // 몫, 나머지
    int quotient, remainder;
    quotient = detectNum / matrix[0].size();
    remainder = detectNum % matrix[0].size();
    matrix[quotient][remainder] = 2;

        
    for(int i=0; i<graph[detectNum].size(); i++){
        if(graph[detectNum][i] == 1 && visited[i] == false){
         
            matrix = DFS(i, graph, matrix, visited);
        }
    }

    // cout << endl;
    return matrix;

}

vector< vector<int> > makeGraph(int row, int column, vector< vector<int> > graph, vector< vector<int> > matrix, vector< vector<int> > nodeNum){
    int index=0, fromEdge, toEdge;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            
            if(matrix[i][j] == 1 || index == (row * column) - 1){
                index++;
                continue;
            }

            if(index == (row * column) - (column - 1)){
                if(matrix[i][j+1] == 0 || matrix[i][j+1] == 2){
                    fromEdge = nodeNum[i][j];
                    toEdge = nodeNum[i][j+1];
                    graph[fromEdge][toEdge] = 1;
                    graph[toEdge][fromEdge] = 1;                    
                }
            }
            else if(index % column == 0){
               
                if(matrix[i][j+1] == 0 || matrix[i][j+1] == 2){
                    // cout << index << endl;
                    fromEdge = nodeNum[i][j];
                    toEdge = nodeNum[i][j+1];             
                    graph[fromEdge][toEdge] = 1;
                    graph[toEdge][fromEdge] = 1;       

                }

                if(i != (row - 1)){
                    if(matrix[i+1][j] == 0 || matrix[i+1][j] == 2){
                        
                        fromEdge = nodeNum[i][j];
                        toEdge = nodeNum[i+1][j];
                        graph[fromEdge][toEdge] = 1;
                        graph[toEdge][fromEdge] = 1;       
                    }
                }

            }
            else if(index % column == column - 1){

                if(matrix[i+1][j] == 0 || matrix[i+1][j] == 2){
                    fromEdge = nodeNum[i][j];
                    toEdge = nodeNum[i+1][j];
                    graph[fromEdge][toEdge] = 1;
                    graph[toEdge][fromEdge] = 1;
                    // cout << "44 "  << fromEdge << " -> " << toEdge << endl; ;
                    // cout << "44 "  << toEdge << " -> " << fromEdge << endl; ;                 
                }
            }
            else {
 
                if(matrix[i][j+1] == 0 || matrix[i][j+1] == 2){
                    fromEdge = nodeNum[i][j];
                    toEdge = nodeNum[i][j+1];
                    graph[fromEdge][toEdge] = 1;
                    graph[toEdge][fromEdge] = 1;
                    // cout << "55 "  << fromEdge << " -> " << toEdge << endl; ;
                    // cout << "55 "  << toEdge << " -> " << fromEdge << endl; ;                    

                }
                if(i != (row-1)){
                    if(matrix[i+1][j] == 0 || matrix[i+1][j] == 2){
                        fromEdge = nodeNum[i][j];
                        toEdge = nodeNum[i+1][j];
                        // cout << "66 "  << fromEdge << " -> " << toEdge << endl; ;
                        // cout << "66 "  << toEdge << " -> " << fromEdge << endl; ;                   
                        graph[fromEdge][toEdge] = 1;
                        graph[toEdge][fromEdge] = 1;  
                    }   
                }
          
            }
           
            index++;
        }

    }
    return graph;
}

int Wall(vector< vector<int> > matrix, int count, int row, int column, vector< vector<int> > graph, vector< vector<int> > nodeNum, int max){
    // 몫, 나머지
          

    if(count == 3){
        // for(int i=0; i<row; i++){
        //     for(int j=0; j<column; j++){

        //         cout << matrix[i][j] << " ";

                
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        vector< vector<int> > nMatrix(row * column);
        int nMax = 0;
        nMatrix = matrix;
        bool visited[row * column];
        for(int i=0; i<row * column; i++){
            visited[i] = false;
        }
        graph = makeGraph(row, column, graph, matrix, nodeNum);
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(matrix[i][j] == 2){
                    int detectNum = nodeNum[i][j];
                    // cout << "시작번호 : " << detectNum << endl;
                    nMatrix = DFS(detectNum, graph, nMatrix, visited);
                    // for(int i=0; i<row; i++){
                    //     for(int j=0; j<column; j++){

                    //         cout << nMatrix[i][j] <<" ";

                            
                    //     }
                    //     cout << endl;
                    // }
                    
                }
            }   
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(nMatrix[i][j] == 0){
                    nMax++;
                }
            }

        }
        if (nMax > max){
            max = nMax;
            cout << " 안전구역 개수 : " <<  max << endl;
        }
        return max;
    }
    for(int i=0; i < row; i++){
        for(int j=0; j< column; j++){
            if(matrix[i][j] == 1 || matrix[i][j] == 2){
                continue;
            }            
            matrix[i][j] = 1;
            max = Wall(matrix, count+1, row, column, graph , nodeNum, max);
            matrix[i][j] = 0;
            
        }
        
    }    

}






int main()
{
    int row, column, index, fromEdge, toEdge;
    row = 7;
    column = 7;
    index = 0;
    bool visited[row * column];
    int max = -1;
    // int nodeNum[row][column];
    vector< vector<int> > nodeNum(row * column);
    vector< vector<int> > graph(row * column);
    vector< vector<int> > matrix({
        // vector<int>({0, 0, 0, 0, 0, 0}),
        // vector<int>({1, 0, 0, 0, 0, 2}),
        // vector<int>({1, 1, 1, 0, 0, 2}),
        // vector<int>({0, 0, 0, 0, 0, 2}),

        vector<int>({2, 0, 0, 0, 1, 1, 0}),
        vector<int>({0, 0, 1, 0, 1, 2, 0}),
        vector<int>({0, 1, 1, 0, 1, 0, 0}),
        vector<int>({0, 1, 0, 0, 0, 0, 0}),
        vector<int>({0, 0, 0, 0, 0, 1, 1}),
        vector<int>({0, 1, 0, 0, 0, 0, 0}),
        vector<int>({0, 1, 0, 0, 0, 0, 0}),

        // vector<int>({2, 0, 0, 0, 1, 1, 0}),
        // vector<int>({0, 0, 1, 0, 1, 2, 0}),
        // vector<int>({0, 1, 1, 0, 1, 0, 0}),
        // vector<int>({0, 1, 0, 0, 0, 0, 0}),
        // vector<int>({0, 0, 0, 0, 0, 1, 1}),
        // vector<int>({0, 1, 0, 0, 0, 0, 0}),
        // vector<int>({0, 1, 0, 0, 0, 0, 0}),        
        
    });
    vector< vector<int> > nMatrix(row * column);
    vector< vector<int> > tmpMatrix(row * column);
    nMatrix = matrix;
    for(int i=0; i<row * column; i++){
        visited[i] = false;
    }
   
    // int matrix[row][column] = {
    //     {2, 0, 0, 0, 1, 1, 0},
    //     {0, 0, 1, 0, 1, 2, 0},
    //     {0, 1, 1, 0, 1, 0, 0},
    //     {0, 1, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 1, 1},
    //     {0, 1, 0, 0, 0, 0, 0},
    //     {0, 1, 0, 0, 0, 0, 0}
    // };

    for(int i=0; i<row * column; i++){
        vector<int> linkedV(row * column);
        graph.push_back(linkedV);

    }
    // cout << "!!!! :" <<  endl;
    for(int i=0; i<row * column; i++){
        for(int j=0; j<row * column; j++){
            graph[i].push_back(0);
        }
        
    }

    for(int i=0; i<row; i++){
        vector<int> linkedV(column);
        nodeNum.push_back(linkedV);
        for(int j=0; j<column; j++){
            // nodeNum[i][j] = index;
            nodeNum[i].push_back(index);
            // cout << nodeNum[i][j] <<" ";
            index++;
            
        }
        // cout << endl;
    }
    // graph 생성

    // graph = makeGraph(row, column, graph, matrix, nodeNum);
    for(int i=0; i < row; i++){
        for(int j=0; j< column; j++){
            if(matrix[i][j] == 1 || matrix[i][j] == 2){
                continue;
            }

            matrix[i][j] = 1;
            max = Wall(matrix, 1, row, column, graph, nodeNum, max);
            matrix[i][j] = 0;



        }
        
    }
    
    
     
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<column; j++){
    //         if(matrix[i][j] == 2){
    //             int detectNum = nodeNum[i][j];
    //             cout << "시작번호 : " << detectNum << endl;
    //             nMatrix = DFS(detectNum, graph, nMatrix, visited);
    //             for(int i=0; i<4; i++){
    //                 for(int j=0; j<6; j++){

    //                     cout << nMatrix[i][j] <<" ";

                        
    //                 }
    //                 cout << endl;
    //             }
                
    //         }
    //     }   
    // }
 
    return 0;
}