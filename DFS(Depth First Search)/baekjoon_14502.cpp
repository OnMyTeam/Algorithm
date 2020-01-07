#include <iostream>
#include <vector>

using namespace std;

// ¿¬±¸¼Ò(14502)
void DFS(int rowStart, int columnStart, int matrix[][7], bool visited[][7], int row, int column){
    visited[rowStart][columnStart] = true;


}
int main()
{
    int row, column, index, fromEdge, toEdge;
    row = 4;
    column = 6;
    index = 0;
    bool visited[row][column];
    int nodeNum[row][column];
    vector< vector<int> > graph(row * column);
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            visited[i][j] = false;
        }   
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
    int matrix[row][column] = {
        {0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 2},
        {1, 1, 1, 0, 0, 2},
        {0, 0, 0, 0, 0, 2}
    };
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
        for(int j=0; j<column; j++){
            nodeNum[i][j] = index;
            cout << nodeNum[i][j] <<" ";
            index++;
            
        }
        cout << endl;
    }
    index = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cout << index << endl;
            if(matrix[i][j] == 1){
                index++;
                continue;
            }

            if(index == (row * column) - (column - 1)){
                if(matrix[i][j+1] == 0){
                    fromEdge = nodeNum[i][j];
                    toEdge = nodeNum[i][j+1];
                }
            }
            else if(index % column == 0){
                if(matrix[i][j+1] == 0){
                    fromEdge = nodeNum[i][j];
                    toEdge = nodeNum[i][j+1];

                }
                if(matrix[i+column][j] == 0){
                    fromEdge = nodeNum[i][j];
                    toEdge = nodeNum[i+column][j];

                }
            }
            else if(index % column == column - 1){
                cout << "???" << endl;
                if(matrix[i+column][j] == 0){
                    fromEdge = nodeNum[i][j];
                    toEdge = nodeNum[i+column][j];

                }
            }
            else {
                cout << "111" << endl;
                if(matrix[i][j+1] == 0 || matrix[i][j+1] == 2){
                    fromEdge = nodeNum[i][j];
                    toEdge = nodeNum[i][j+1];
                    graph[fromEdge][toEdge] = 1;
                    graph[toEdge][fromEdge] = 1;                      

                }
                if(matrix[i+column][j] == 0 || matrix[i+column][j] == 2){
                    fromEdge = nodeNum[i][j];
                    toEdge = nodeNum[i+column][j];
                    graph[fromEdge][toEdge] = 1;
                    graph[toEdge][fromEdge] = 1;  
                }             
            }
              
            index++;
        }

    }
    
    for(int i=0; i<row * column; i++){
        for(int j=0; j<row * column; j++){
            cout << graph[i][j] << " " ;
            
        }
        cout << endl;
    }

    // for(int i=0; i<row * column; i++){
    //     for(int j=0; j<row * column; j++){
    //         cout << graph[i][j] << " " ;
            
    //     }
    //     cout << endl;
    // }    

    // for(int i=0; i<row; i++){
    //     for(int j=0; j<column; j++){
    //         if(matrix[i][j] == 2){
    //             DFS(i, j, matrix, visited, row, column);
    //         }
    //     }   
    //     cout << endl;
    // }    
    return 0;
}