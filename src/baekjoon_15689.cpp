#include <iostream>
#include <vector>

using namespace std;

const int N = 6;
const int M = 6;

int minNUm = 999999999;
void run(int x, int y, int cameranum, int cValue[N][M]) {

    if(cameranum == 1){
        for(int i = 1; i <= 4; i++){
            // µ¿
            if(i == 1){
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }
                    cValue[x][j] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }

            }else if(i == 2){ // ºÏ
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[x][j] == 6){
                        continue;
                    }                    
                    cValue[j][y] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }                
            }else if(i == 3){ // ¼­
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                        
                    cValue[x][j] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }                
            }else if(i == 4){
                for(int j= x + 1; j < N; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                       
                    cValue[x][j] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
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
                // µ¿
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                    
                    cValue[x][j] = 9;
                }
                // ¼­
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                       
                    cValue[x][j] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }                                           
            }else {
                //ºÏ
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[x][j] == 6){
                        continue;
                    }                       
                    cValue[j][y] = 9;
                }
                // ³²
                for(int j= x + 1; j < N; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                      
                    cValue[x][j] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }                                           

            }
        }
    }else if(cameranum == 3){
        for(int i = 1; i <= 4; i++){
            
            if(i == 1){
                //µ¿
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }
                    cValue[x][j] = 9;
                }
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[x][j] == 6){
                        continue;
                    }                    
                    cValue[j][y] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }                  

            }else if(i == 2){ // ºÏ
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[x][j] == 6){
                        continue;
                    }                    
                    cValue[j][y] = 9;
                }
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                        
                    cValue[x][j] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }                                
            }else if(i == 3){ // ¼­
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                        
                    cValue[x][j] = 9;
                }
                for(int j= x + 1; j < N; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                       
                    cValue[x][j] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }                                
            }else if(i == 4){
                for(int j= x + 1; j < N; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                       
                    cValue[x][j] = 9;
                }
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }
                    cValue[x][j] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }                                
            }
        }  

    }else if(cameranum == 4){
        for(int i = 1; i <= 4; i++){
            // µ¿
            if(i == 1){
                //µ¿
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }
                    cValue[x][j] = 9;
                }
                //ºÏ
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[x][j] == 6){
                        continue;
                    }                    
                    cValue[j][y] = 9;
                }
                //¼­
                
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                       
                    cValue[x][j] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }                                      

            }else if(i == 2){ 
                // ºÏ
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[x][j] == 6){
                        continue;
                    }                    
                    cValue[j][y] = 9;
                }
                // ¼­
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                        
                    cValue[x][j] = 9;
                }
                // ³²
                for(int j= x + 1; j < N; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                      
                    cValue[x][j] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }                                          
            }else if(i == 3){ 

                // ¼­
                for(int j= y - 1; j >= 0; j--){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                        
                    cValue[x][j] = 9;
                }
                // ³²
                for(int j= x + 1; j < N; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                       
                    cValue[x][j] = 9;
                }
                //µ¿
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }
                    cValue[x][j] = 9;
                }
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }                

            }else if(i == 4){
                // ³²
                for(int j= x + 1; j < N; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }                       
                    cValue[x][j] = 9;
                }
                // µ¿
                for(int j= y + 1; j < M; j++){
                    if(cValue[x][j] == 9 || cValue[x][j] == 6){
                        continue;
                    }
                    cValue[x][j] = 9;
                }
                // ºÏ
                for(int j= x - 1; j >= 0; j--){
                    if(cValue[j][y] == 9 || cValue[x][j] == 6){
                        continue;
                    }                    
                    cValue[j][y] = 9;
                }                            
                for(int j= x + 1; j<N; j++){
                    for(int k= y + 1; k<M; k++){
                        if(0 < cValue[j][k] && cValue[j][k] < 6){
                            int cameranum = cValue[j][k];
                            run(j, k, cameranum, cValue);
                        }
                    }
                }                
            }
        }  
    }else {
        // ³²
        for(int j= x + 1; j < N; j++){
            if(cValue[x][j] == 9 || cValue[x][j] == 6){
                continue;
            }                       
            cValue[x][j] = 9;
        }
        // µ¿
        for(int j= y + 1; j < M; j++){
            if(cValue[x][j] == 9 || cValue[x][j] == 6){
                continue;
            }
            cValue[x][j] = 9;
        }
        // ºÏ
        for(int j= x - 1; j >= 0; j--){
            if(cValue[j][y] == 9 || cValue[x][j] == 6){
                continue;
            }                    
            cValue[j][y] = 9;
        }
        // ¼­
        for(int j= y - 1; j >= 0; j--){
            if(cValue[x][j] == 9 || cValue[x][j] == 6){
                continue;
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
    }






}
 

int main()
{
    int value[N][M] = {
        {0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 5},
    };


    for(int j=0; j<N; j++){
        for(int k=0; k<M; k++){
            if(0 < value[j][k] && value[j][k] < 6){
                int cameranum = value[j][k];
                run(j, k, cameranum, value);
            }
        }
    }
    
    return 0;
}