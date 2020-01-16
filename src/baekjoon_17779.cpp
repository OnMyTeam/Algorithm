#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> *people;
vector<int> *area;
void makeArea(int r, int c){
    for(int d1=1; d1 <= 1; d1++){
        for(int d2=1; d2 <= 1; d2++){
            // if(d1 > (N-r-d2) || d2 > N-d2){
            //     continue;
            // }
            int sum1=0, sum2=0, sum3=0, sum4=0, sum5=0;            
            if(r < (r + d1 + d2) && (r + d1 + d2) <= N && (c - d1) < c && c < (c + d2) && (c + d2) <= N ){
                cout << "d1: " << d1 << " d2 :" << d2 << endl;
                cout << "r: " << r << " c :" << c << endl;                
                //5번 선거구
                for(int i=0; i<=d1; i++){
                    int x1,y1,x2,y2;
                    x1 = r + i;
                    y1 = c - i;
                    x2 = r + d2 + i;
                    y2 = c + d2 - i;
                    if(x1>=N || y1>=N || x2>=N || y2>=N){
                        continue;
                    }
                    area[x1][y1] = 5;
                    area[x2][y2] = 5;
                }
                cout <<  endl;
                for(int i=0; i<=d2; i++){
                    int x1,y1,x2,y2;
                    x1 = r + i;
                    y1 = c + i;
                    x2 = r + d1 + i;
                    y2 = c - d1 + i;
                    if(x1>=N || y1>=N || x2>=N || y2>=N){
                        continue;
                    }                    
                    area[x1][y1] = 5;
                    area[x2][y2] = 5;      
                }
                
                for(int i=0; i<N; i++){
                    for(int j=0; j<N; j++){
                        if(area[i][j] != 0){
                            continue; 
                        } 
                        else if(i < r + d1 && j <= c){
                            area[i][j] = 1;
                            sum1 = sum1 + people[i][j];
                        }
                        else if(i <= r + d2 && c < j && j <N){
                            area[i][j] = 2;
                            sum2 = sum2 + people[i][j];
                        }
                        else if(i >= r + d1 && i < N && j < c - d1+d2){
                            area[i][j] = 3;
                            sum3 = sum3 + people[i][j];
                        }
                        else if(i > r + d2 && i <= N && c - d1+d2 <= j){
                            area[i][j] = 4;
                            sum4 = sum4 + people[i][j];
                        }
                        
                        
                    }
                }
                for(int i=0; i<N; i++){
                    for(int j=0; j<N; j++){
                        cout << area[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "sum1 : " << sum1 << endl;
                cout << "sum2 : " << sum2 << endl;
                cout << "sum3 : " << sum3 << endl;
                cout << "sum4 : " << sum4 << endl;

                 for(int i=0; i<N; i++){
                    for(int j=0; j<N; j++){
                        area[i][j] = 0;
                    }
                    cout << endl;
                }                           

            }
        }
    }
        // for(int i=0; i<=2; i++){
        //     area[r+i][c-i] = 5;
        //     area[r+i][c+i] = 5;
        // }
        
        // for(int i=0; i<=2; i++){
        //     area[r + 2 + i][c - 2 + i] = 5;
        //     area[r + 2 + i][c + 2 - i] = 5;      
        // }
        // for(int i=0; i<N; i++){
        //     for(int j=0; j<N; j++){
        //         cout << area[i][j] << " ";
        //     }
        //     cout << endl;
        // }        
}
int main(){
    // cin >> N;
    N = 6;
    people = new vector<int>[N];
    area = new vector<int>[N];
    people[0] = {1, 2, 3, 4, 1, 6};
    people[1] = {7, 8, 9, 1, 4, 2};
    people[2] = {2, 3, 4, 1, 1, 3};
    people[3] = {6, 6, 6, 6, 9, 4};
    people[4] = {9, 1, 9, 1, 9, 5};
    people[5] = {1, 1, 1, 1, 1, 9};

    for(int i=0; i<N; i++){
        area[i].assign(N,0);
    }
    
    // for(int r=0; r<N; r++){
    //     for(int c=0; c<N; c++){
    //         makeArea(r, c);                  
    //     }
    // }
    makeArea(2, 2);
    return 0;
}