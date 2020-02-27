#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N[100];

// int jaegwi(int n, int cnt){
//     if(n == 1){
//         return 0;
//     }
//     else if(n == 2 && n == 3){
//         cout << cnt << endl;
//         return 1;
//     }
//     else{

//         if(n % 3 == 0){
//             int a = n / 3;
//             N[n] = cnt + N[a];
//             jaegwi(a, cnt+1);
//         }
//         else if(n % 2 == 0){
//             int a = n / 3;
//             N[n] = cnt + N[a];            
//             jaegwi(a, cnt+1);
//         }
//         else{
//             int a = n - 1;
//             N[n] = cnt + N[a];            
//             jaegwi(a, cnt+1);
//         }
//     }


// }
int main() {
    int inputNum = 9;
    for(int i=1; i<=inputNum; i++){

        if(i == 1){
             N[i] = 0;
        }
        else if(i == 2 && i == 3){
            N[i] = 1;
        }
        else{
            int min2;
            int min1 = 1 + N[i - 1];
            if(i % 3 == 0){
                
                min2 = 1 + N[i / 3];
                
            }
            else if(i % 2 == 0){
                min2 = 1 + N[i / 2];
            }

            if( min1 >= min2){
                N[i] = min2;
            }else{
                N[i] = min1;
            }

        }
        if(i == inputNum){
             cout << N[inputNum] << endl;
        }
    }


 
    return 0;
}