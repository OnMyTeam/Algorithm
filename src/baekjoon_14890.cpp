#include<iostream>
#include <vector>

using namespace std;

int N,L;
vector<int> *visited;
vector< vector<int> > matrix({
    vector<int>({3, 3, 3, 3, 3, 3}),
    vector<int>({2, 3, 3, 3, 3, 3}),
    vector<int>({2, 2, 2, 3, 2, 3}),
    vector<int>({1, 1, 1, 2, 2, 2}),
    vector<int>({1, 1, 1, 3, 3, 1}),
    vector<int>({1, 1, 2, 3, 3, 2}),

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

int main(){
    int cnt = 0;
    
	N = 6, L = 2;
    visited = new vector<int>[N];
    // for(int i=0; i<N; i++){
    //     visited[i].assign(N,0);
    // }  
    // // 세로 탐색
    // for(int i=0; i<N; i++){
    //     bool suc = true;
    //     for(int j=0; j<N; j++){
    //         cout << matrix[j][i] << " ";
    //         if(j == N-1){
    //             continue;
    //         }
    //         //현재 칸과 다음칸의 높이가 다른지 먼저 확인
    //         if(matrix[j][i] != matrix[j+1][i]){
    //             // 높이가 2이상 나면 갈수 없음
    //             if(abs(matrix[j][i] - matrix[j+1][i]) >= 2){
    //                 cout << "11" << endl;
    //                 suc = false;
    //             }
    //             else{
                    
    //                 // 전칸 번호가 다음칸 번호보다 클때
    //                 if(matrix[j][i] > matrix[j+1][i]){
    //                     // 경사 길이가 최소 L이상인지 확인
    //                     int Llength = 1;
    //                     for(int k=j+1; k<N; k++){
    //                         // cout << k << " , " << k+1 << endl;
    //                         if(k == N-1 || visited[k + (L - 1)][i] == 1){
    //                             continue;
    //                         }
    //                         else if(matrix[k][i] != matrix[k+1][i]){
    //                             suc = false;
    //                         }
    //                         else{
                          
    //                             Llength++;
    //                         }

    //                         if(Llength == L){
    //                             visited[k][i] = 1;
    //                             visited[k+1][i] = 1;                                
    //                             break;
    //                         }
    //                     }
    //                     Llength = 1;                        
    //                 }
    //                 // 전칸 번호가 다음칸 번호보다 클때
    //                 if(matrix[j][i] < matrix[j+1][i]){
    //                     int Llength = 1;
    //                     for(int k=j; k>=0; k--){
    //                         // cout << k << " , " << k+1 << endl;
    //                         if(k == 0 || visited[k - (L - 1)][i] == 1){
    //                             continue;
    //                         }
    //                         else if(matrix[k][i] != matrix[k-1][i]){
    //                             suc = false;
    //                         }
    //                         else{

    //                             Llength++;
    //                         }

    //                         if(Llength == L){
    //                             visited[k][i] = 1;
    //                             visited[k-1][i] = 1;                                      
    //                             break;
    //                         }
    //                     }
    //                     Llength = 1;                          
    //                 }

    //             }
                
    //         }
    //     }
    //     cout << endl;
    //     if(suc == true){
    //         cout << i << endl;
    //         cnt ++;
    //     }
        
    //     suc == true;
        
    // }
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
                if(abs(matrix[i][j+1] - matrix[i][j+1]) >= 2){

                    suc = false;
                }
                else{
                    
                    // 전칸 번호가 다음칸 번호보다 클때
                    if(matrix[i][j] > matrix[i][j+1]){
                        // 경사 길이가 최소 L이상인지 확인
                        int Llength = 1;
                        for(int k=j+1; k<N; k++){
                            // cout << k << " , " << k+1 << endl;
                            if(k == N-1 || visited[i][k + (L - 1)] == 1){
                                continue;
                            }
                            else if(matrix[i][k] != matrix[i][k+1]){
                                suc = false;
                            }
                            else{
                          
                                Llength++;
                            }

                            if(Llength == L){
                                visited[i][k] = 1;
                                visited[i][k+1] = 1;                                
                                break;
                            }
                        }
                        Llength = 1;                        
                    }
                    // 전칸 번호가 다음칸 번호보다 클때
                    if(matrix[i][j] < matrix[i][j+1]){
                        int Llength = 1;
                        for(int k=j; k>=0; k--){
                            // cout << k << " , " << k+1 << endl;
                            if(k == 0 || visited[i][k - (L - 1)] == 1){
                                continue;
                            }
                            else if(matrix[i][k] != matrix[i][k-1]){
                                suc = false;
                            }
                            else{

                                Llength++;
                            }

                            if(Llength == L){
                                visited[i][k] = 1;
                                visited[i][k-1] = 1;                                      
                                break;
                            }
                        }
                        Llength = 1;                          
                    }

                }
                
            }
        }
        cout << endl;
        if(suc == true){
            cout << i << endl;
            cnt ++;
        }
        
        suc == true;
        
    }

    cout << cnt << " ";
	return 0;
}