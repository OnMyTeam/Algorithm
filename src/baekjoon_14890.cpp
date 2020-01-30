#include<iostream>
#include <vector>

using namespace std;

int N,L;
vector<int> *visited;
vector< vector<int> > matrix({
    // vector<int>({3, 3, 3, 3, 3, 3}),
    // vector<int>({2, 3, 3, 3, 3, 3}),
    // vector<int>({2, 2, 2, 3, 2, 3}),
    // vector<int>({1, 1, 1, 2, 2, 2}),
    // vector<int>({1, 1, 1, 3, 3, 1}),
    // vector<int>({1, 1, 2, 3, 3, 2}),

    // vector<int>({3, 2, 1, 1, 2, 3}),
    // vector<int>({3, 2, 2, 1, 2, 3}),
    // vector<int>({3, 2, 2, 2, 3, 3}),
    // vector<int>({3, 3, 3, 3, 3, 3}),
    // vector<int>({3, 3, 3, 3, 2, 2}),
    // vector<int>({3, 3, 3, 3, 2, 2}),

    vector<int>({3, 2, 1, 1, 2, 3}),
    vector<int>({3, 2, 2, 1, 2, 3}),
    vector<int>({3, 2, 2, 2, 3, 3}),
    vector<int>({3, 3, 3, 3, 3, 3}),
    vector<int>({3, 3, 3, 3, 2, 2}),
    vector<int>({3, 3, 3, 3, 2, 2}),   
    
});

int main(){
    int cnt = 0;
    
	N = 6, L = 3;
    visited = new vector<int>[N];
    for(int i=0; i<N; i++){
        visited[i].assign(N,0);
    }  
    // 세로 탐색
    for(int i=0; i<N; i++){
        bool suc = true;
        for(int j=0; j<N; j++){
            cout << matrix[j][i] << " ";
            if(j == N-1){
                continue;
            }
            //현재 칸과 다음칸의 높이가 다른지 먼저 확인
            if(matrix[j][i] != matrix[j+1][i]){
                // 높이가 2이상 나면 갈수 없음
                if(abs(matrix[j][i] - matrix[j+1][i]) >= 2){
                    suc = false;
                }
                else{
                    
                    // 전칸 번호가 다음칸 번호보다 클때
                    if(matrix[j][i] > matrix[j+1][i]){
                        if(L == 1){
                            visited[j+1][i] = 1;
                        }
                        else{
                            // 경사 길이가 최소 L이상인지 확인
                            int Llength = 1;
                            for(int k=j+1; k<N; k++){
                                // cout << k << " , " << k+1 << endl;
                                if(k == N-1 || visited[k + 1][i] == 1){
                                    // cout << " 11 " << endl;
                                    continue;
                                }
                                else if(matrix[k][i] != matrix[k+1][i]){
                                    // cout << " 22 " << endl;
                                    suc = false;
                                }
                                else{
                            
                                    Llength++;
                                }

                                if(Llength == L){
                                    // cout << " 33 " << endl;
                                    for(int z=j+1; z<k+L; z++){
                                        visited[z][i] = 1;
                                    }                             
                                    break;
                                }
                            }
                            if(Llength < L){
                                // cout <<" 55 " << endl;
                                suc = false;
                            }                            
                            Llength = 1; 
                        }
                       
                    }
                    // 전칸 번호가 다음칸 번호보다 작을때
                    if(matrix[j][i] < matrix[j+1][i]){
                        if(L == 1){
                             visited[j][i] = 1;
                        }else{
                            int Llength = 1;
                            for(int k=j; k>=0; k--){
                                // cout << k << " , " << k-1 << endl;
                                if(k == 0 || visited[k - 1][i] == 1){
                                    // cout << " 1111 " << endl;
                                    continue;
                                }
                                else if(matrix[k][i] != matrix[k-1][i]){
                                    // cout << " 11 " << endl;
                                    suc = false;
                                }
                                else{
                                    // cout << " 22 " << endl;
                                    Llength++;
                                }

                                if(Llength == L){
                                    
                                    for(int z=j; z>=0; z--){
                                        visited[z][i] = 1;
                                    }
                                    break;
                                }
                            }
                            if(Llength < L){
                                // cout <<" 55 " << endl;
                                suc = false;
                            }                            
                            Llength = 1; 
                        }
                         
                    }

                }
                
            }
        }
        cout << endl;
        if(suc == true){
            cnt ++;
            cout << i << endl;
        }else{
            for(int a=0; a<N; a++){
                visited[a][i] = 0;
            }            
        }
        
        suc == true;
        
    }

    cout << endl;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////
    for(int i=0; i<N; i++){
        visited[i].assign(N,0);
    }  
    // 가로 탐색
    for(int i=0; i<N; i++){
        bool suc = true;
        for(int j=0; j<N; j++){
            cout << matrix[i][j] << " ";
            if(j == N-1){
                continue;
            }
            //현재 칸과 다음칸의 높이가 다른지 먼저 확인
            if(matrix[i][j] != matrix[i][j+1]){
                // 높이가 2이상 나면 갈수 없음
                if(abs(matrix[i][j] - matrix[i][j+1]) >= 2){

                    suc = false;
                }
                else{
                    
                    // 전칸 번호가 다음칸 번호보다 클때
                    if(matrix[i][j] > matrix[i][j+1]){
                        if(L == 1){
                            visited[i][j+1] = 1;
                        }else{
                            // 경사 길이가 최소 L이상인지 확인
                            int Llength = 1;
                            for(int k=j+1; k<N; k++){
                                // cout << k << " , " << k+1 << endl;
                                if(k == N-1 || visited[i][k + 1] == 1){
                                    // cout << " 11 " << endl;
                                    continue;
                                }
                                else if(matrix[i][k] != matrix[i][k+1]){
                                    // cout << " 22 " << endl;
                                    suc = false;
                                }
                                else{
                            
                                    Llength++;
                                }

                                if(Llength == L){
                                    // cout << " 33 " << endl;
                                    for(int z=j+1; z<N; z++){
                                        visited[i][z] = 1;
                                    }                             
                                    break;
                                }
                            }
                            if(Llength < L){
                                // cout <<" 55 " << endl;
                                suc = false;
                            }                            
                            Llength = 1;  
                        }
                      
                    }
                    // 전칸 번호가 다음칸 번호보다 작을때
                    if(matrix[i][j] < matrix[i][j+1]){
                         
                        if(L == 1){
                            visited[i][j] = 1;
                        }
                        else{
                            int Llength = 1;
                            for(int k=j; k>=0; k--){
                                // cout << k << " , " << k-1 << endl;
                                if(k == 0 || visited[i][k - (L - 1)] == 1){
                                    // cout << " 11 " << endl;
                                    continue;
                                }
                                else if(matrix[i][k] != matrix[i][k-1]){
                                    // cout << " 22 " << endl;
                                    suc = false;
                                }
                                else{
                                    // cout << " 33 "  << endl;
                                    Llength++;
                                }

                                if(Llength == L){
                                    // cout << " 44 " << endl;
                                    for(int z=j; z>=0; z--){
                                        visited[i][z] = 1;
                                    }                                          
                                    break;
                                }
                            }
                            if(Llength < L){
                                // cout <<" 55 " << endl;
                                suc = false;
                            }
                            Llength = 1; 
                        }
                         
                    }

                }
                
            }
        }
        cout << endl;
        if(suc == true){
            cnt ++;
            cout << i << endl;
        }
        
        suc == true;
        
    }

    cout << " result : " << cnt << endl;
	return 0;
}