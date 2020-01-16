#include <iostream>
#include <vector>

using namespace std;
int N;
int cnt = 0;
bool possible(int z, int k, vector<int> matrix[]){

    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            // cout << "i,j " << i << "," << j << " -> " << matrix[i][j] << endl;
            if(i == z && j == k){
                // cout << "z,k " << z << "," << k << endl;
                continue;
            }

            if(matrix[i][j] == 1){
                // cout << "z,k " << z << "," << k << endl;
                // cout << "abs(i - z) " << abs(i - z) << " abs(j - k) " << abs(j - k) << endl;
                if(i == z || j == k || abs(i - z) == abs(j - k) )
                    return false;
            }
            
        }
    }
  
    return true;
}
void queens(int level, vector<int> matrix[], vector<int> ans){

    if(level == N){
        int sum = 0;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(matrix[i][j] == 1){
                    sum = sum + (i+j);
                }
            }
            
        }        
        for(int i=0; i < ans.size(); i++){
            if(ans[i] == sum){
                return;
            }
        }
        ans.push_back(sum);
        cnt ++;        
        return;
    }
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            if (matrix[i][j] == 1){
                continue;
            }
                
            if(possible(i, j, matrix)){
                matrix[i][j] = 1;
                ans.push_back(i+j);
                queens(level + 1, matrix, ans);
                matrix[i][j] = 0;
                ans.pop_back();
            }

              
        }

    }
}

int main(){
    N = 4;
    vector<int> matrix[N];
    vector<int> ans;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            matrix[i].push_back(0);
        }
    }
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            matrix[i][j] = 1;
            ans.push_back(i+j);
            queens(1, matrix, ans);
            matrix[i][j] = 0;
            ans.pop_back();
        }

    }    
    cout << cnt << endl;
    return 0;
}