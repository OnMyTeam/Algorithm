#include <iostream>
#include <vector>

using namespace std;

// ??????(14502)
vector< vector<int> > DFS(int row, int col, int detectNum, vector< vector<int> > matrix, vector< vector<int> > nodeNum){

    // ??, ??????
    int rx, ry;
    rx = detectNum / matrix[0].size();
    ry = detectNum % matrix[0].size();
    matrix[rx][ry] = 2;
  
    for(int i=0; i<4; i++){
        int x, y;
        int tx, ty;
        // 12??
        if(i == 0){
            tx = -1;
            ty = 0;
        }
        //3??
        else if(i == 1){
            tx = 0;
            ty = 1;
        }
        //6??
        else if(i == 2){
            tx = 1;
            ty = 0;            
        }
        //9??
        else{
            tx = 0;
            ty = -1;             
        }
        x = rx + tx;
        y = ry + ty;
        if(x < 0 || x >= row || y < 0 || y >= col)
            continue;
        if(matrix[x][y] == 0){
            int detectNum1 = nodeNum[x][y];
             matrix = DFS(row, col, detectNum1, matrix, nodeNum);
        }
    }    
    return matrix;

}


int Wall(vector< vector<int> > matrix, int count, int row, int col, vector< vector<int> > nodeNum, int max){
    if(count == 3){

        vector< vector<int> > nMatrix(row * col);
        int nMax = 0;
        nMatrix = matrix;
        bool visited[row * col];
        for(int i=0; i<row * col; i++){
            visited[i] = false;
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 2){
                    int detectNum = nodeNum[i][j];
                    nMatrix = DFS(row, col, detectNum, nMatrix, nodeNum);
                }
            }   
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(nMatrix[i][j] == 0){
                    nMax++;
                }
            }

        }
        if (nMax > max){
            max = nMax;
        }
        return max;
    }

    
    for(int i=0; i < row; i++){
        for(int j=0; j< col; j++){
            if(matrix[i][j] == 1 || matrix[i][j] == 2){
                continue;
            }            
            matrix[i][j] = 1;
            max = Wall(matrix, count+1, row, col, nodeNum, max);
            matrix[i][j] = 0;
            
        }
        
    }
    return max;

}

int main()
{
    int row, col, index, fromEdge, toEdge;
    row = 4;
    col = 6;
    index = 0;
    bool visited[row * col];
    int max = -1;
    // int nodeNum[row][col]; 
    vector< vector<int> > nodeNum(row * col);
    vector< vector<int> > graph(row * col);
    vector< vector<int> > matrix({
        vector<int>({0, 0, 0, 0, 0, 0}),
        vector<int>({1, 0, 0, 0, 0, 2}),
        vector<int>({1, 1, 1, 0, 0, 2}),
        vector<int>({0, 0, 0, 0, 0, 2}),

        // vector<int>({2, 0, 0, 0, 1, 1, 0}),
        // vector<int>({0, 0, 1, 0, 1, 2, 0}),
        // vector<int>({0, 1, 1, 0, 1, 0, 0}),
        // vector<int>({0, 1, 0, 0, 0, 0, 0}),
        // vector<int>({0, 0, 0, 0, 0, 1, 1}),
        // vector<int>({0, 1, 0, 0, 0, 0, 0}),
        // vector<int>({0, 1, 0, 0, 0, 0, 0}),

        // vector<int>({2, 0, 0, 0, 0, 0, 0, 2}),
        // vector<int>({2, 0, 0, 0, 0, 0, 0, 2}),
        // vector<int>({2, 0, 0, 0, 0, 0, 0, 2}),
        // vector<int>({2, 0, 0, 0, 0, 0, 0, 2}),
        // vector<int>({2, 0, 0, 0, 0, 0, 0, 2}),
        // vector<int>({0, 0, 0, 0, 0, 0, 0, 0}),
        // vector<int>({0, 0, 0, 0, 0, 0, 0, 0}),
        // vector<int>({0, 0, 0, 0, 0, 0, 0, 0}),     
        
    });

    for(int i=0; i<row; i++){
        vector<int> linkedV(col);
        nodeNum.push_back(linkedV);
        for(int j=0; j<col; j++){
            nodeNum[i].push_back(index);
            index++;
            
        }
    }

    for(int i=0; i < row; i++){
        for(int j=0; j< col; j++){
            if(matrix[i][j] == 1 || matrix[i][j] == 2){
                continue;
            }

            matrix[i][j] = 1;
            max = Wall(matrix, 1, row, col, nodeNum, max);
            

            matrix[i][j] = 0;

        }
        cout << " ??? ???????? ???? : " <<  max << endl;
    }
 
    return 0;
}