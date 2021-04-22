#include <iostream>
#include <vector>

using namespace std;

const int N = 6;
const int M = 6;

int minNUm = 999999999;
void run(int x, int y, int cameranum, int cValue[N][M]) {
    
    if(cameranum == 0){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(0 < cValue[j][k] && cValue[j][k] < 6){
                    int cameranum = cValue[j][k];
                    
                    run(j, k, cameranum, cValue);
                }
            }
        }
    }
    if(cameranum == 1){
        for(int i = 1; i <= 4; i++){
            // 동
            if(i == 1){
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }
                    cValue[x][j] = 9;
                }
                for(int j= x; j<N; j++){
                    for(int k = 0; k<M; k++){
                        if(cValue[j][k] == cValue[x][y]){
                            continue;
                        }
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }

            }else if(i == 2){ // 북
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[j][y] == 6){
                        break;
                    }                    
                    cValue[j][y] = 9;
                }
                for(int j= x; j<N; j++){
                    for(int k = 0; k<M; k++){
                        if(cValue[j][k] == cValue[x][y]){
                            continue;
                        }
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }               
            }else if(i == 3){ // 서
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }                        
                    cValue[x][j] = 9;
                }
                for(int j= x; j<N; j++){
                    for(int k = 0; k<M; k++){
                        if(cValue[j][k] == cValue[x][y]){
                            continue;
                        }
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }               
            }else if(i == 4){
                for(int j= x + 1; j < N; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }                       
                    cValue[x][j] = 9;
                }
                for(int j= x; j<N; j++){
                    for(int k = 0; k<M; k++){
                        if(cValue[j][k] == cValue[x][y]){
                            continue;
                        }
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }             
            }
        }
    }else if(cameranum == 2){
        for(int i = 1; i <= 2 ; i++){

            if(i == 1){
                int aValue[N][M] = cValue[N][M];
                // 동
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }                    
                    cValue[x][j] = 9;
                }
                // 서
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }                       
                    cValue[x][j] = 9;
                }
                for(int i=0; i < N; i++){
                    for(int j=0; j < M; j++){

                        cout << cValue[i][j] << " ";
                    }
                    cout << endl;

                }                
                cout << endl;
                                                   
            }else {
                //북
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[j][y] == 6){
                        break;
                    }                       
                    cValue[j][y] = 9;
                }
                // 남
                for(int j= x + 1; j < N; j++){
                    if(cValue[j][y] == 9 || cValue[j][y] == 6){
                        break;
                    }                      
                    cValue[j][y] = 9;
                }

            }
            for(int j= x; j<N; j++){
                for(int k = 0; k<M; k++){
                    if(j == x && k == y){
                        // cout<< "찾음" << cValue[j][k] << endl;
                        // cout<< "위치" << j << "," << k << endl;
                        continue;
                    }
                    if(0 < cValue[j][k] && cValue[j][k] < 6){
                        int cameranum = cValue[j][k];
                        run(j, k, cameranum, cValue);
                    }
                }
            }            
        }
    }else if(cameranum == 3){
        for(int i = 1; i <= 4; i++){
            
            if(i == 1){
                //동
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }
                    cValue[x][j] = 9;
                }
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[j][y] == 6){
                        break;
                    }                    
                    cValue[j][y] = 9;
                }
              

            }else if(i == 2){ // 북
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[j][y] == 6){
                        break;
                    }                    
                    cValue[j][y] = 9;
                }
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }                        
                    cValue[x][j] = 9;
                }
                            
            }else if(i == 3){ // 서
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }                        
                    cValue[x][j] = 9;
                }
                // 남
                for(int j= x + 1; j < N; j++){
                    if(cValue[j][y] == 9 || cValue[j][y] == 6){
                        break;
                    }                      
                    cValue[j][y] = 9;
                }
                              
            }else if(i == 4){
                // 남
                for(int j= x + 1; j < N; j++){
                    if(cValue[j][y] == 9 || cValue[j][y] == 6){
                        break;
                    }                      
                    cValue[j][y] = 9;
                }
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }
                    cValue[x][j] = 9;
                }
                            
            }
            for(int j= x; j<N; j++){
                for(int k = 0; k<M; k++){
                    if(j == x && k == y){
                        // cout<< "찾음" << cValue[j][k] << endl;
                        // cout<< "위치" << j << "," << k << endl;
                        continue;
                    }
                    if(0 < cValue[j][k] && cValue[j][k] < 6){
                        int cameranum = cValue[j][k];
                        run(j, k, cameranum, cValue);
                    }
                }
            }                  
        }  

    }else if(cameranum == 4){
        for(int i = 1; i <= 4; i++){
            // 동
            if(i == 1){
                //동
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }
                    cValue[x][j] = 9;
                }
                //북
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[j][y] == 6){
                        break;
                    }                    
                    cValue[j][y] = 9;
                }
                //서
                
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }                       
                    cValue[x][j] = 9;
                }
                                    

            }else if(i == 2){ 
                // 북
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[j][y] == 6){
                        break;
                    }                    
                    cValue[j][y] = 9;
                }
                // 서
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }                        
                    cValue[x][j] = 9;
                }

                // 남
                for(int j= x + 1; j < N; j++){
                    if(cValue[j][y] == 9 || cValue[j][y] == 6){
                        break;
                    }                      
                    cValue[j][y] = 9;
                }
                                            
            }else if(i == 3){ 

                // 서
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }                        
                    cValue[x][j] = 9;
                }
                // 남
                for(int j= x + 1; j < N; j++){
                    if(cValue[j][y] == 9 || cValue[j][y] == 6){
                        break;
                    }                      
                    cValue[j][y] = 9;
                }
                //동
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }
                    cValue[x][j] = 9;
                }
           

            }else if(i == 4){
                // 남
                for(int j= x + 1; j < N; j++){
                    if(cValue[j][y] == 9 || cValue[j][y] == 6){
                        break;
                    }                      
                    cValue[j][y] = 9;
                }
                // 동
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        break;
                    }
                    cValue[x][j] = 9;
                }
                // 북
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[x][j] == 6){
                        break;
                    }                    
                    cValue[j][y] = 9;
                }                            
             
            }
            for(int j= x; j<N; j++){
                for(int k = 0; k<M; k++){
                    if(j == x && k == y){
                        // cout<< "찾음" << cValue[j][k] << endl;
                        // cout<< "위치" << j << "," << k << endl;
                        continue;
                    }
                    if(0 < cValue[j][k] && cValue[j][k] < 6){
                        int cameranum = cValue[j][k];
                        run(j, k, cameranum, cValue);
                    }
                }
            }                
        }  
    }else {
        // 남
        for(int j= x + 1; j < N; j++){
            if(cValue[j][y] == 9 || cValue[j][y] == 6){
                break;
            }                      
            cValue[j][y] = 9;
        }
        // 동
        for(int j= y + 1; j < M; j++){
            if(cValue[x][j] == 9 || cValue[x][j] == 6){
                break;
            }
            cValue[x][j] = 9;
        }
        // 북
        for(int j= x - 1; j >= 0; j--){
            if(cValue[j][y] == 9 || cValue[x][j] == 6){
                break;
            }                    
            cValue[j][y] = 9;
        }
        // 서
        for(int j= y - 1; j >= 0; j--){
            if(cValue[x][j] == 9 || cValue[x][j] == 6){
                break;
            }                        
            cValue[x][j] = 9;
        }
        int zerocnt = 0;
        for(int i=0; i < N; i++){
            for(int j=0; j < M; j++){
                if(cValue[i][j] == 0){
                    zerocnt++;
                }
                cout << cValue[i][j] << " ";
            }
            cout << endl;
            
        }
        cout << zerocnt << endl;
        cout << endl;
    }






}
 

int main()
{
    int value[N][M] = {
        {0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 6, 0},
        {0, 6, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 5},
    };


    run(0, 0, 0, value);
    
    return 0;
}