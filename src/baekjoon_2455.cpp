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

    vector<int>({0, 32}),
    vector<int>({3, 13}),
    vector<int>({28, 25}),
    vector<int>({39, 0}),

    
});


int main(){
	int max=0;
    int cV = 0;
    for(int i=0; i<4; i++){
        if(i == 0){
            max = matrix[i][1];
            cV = matrix[i][1];
        }
        else if(i > 0 && i < 3){
            cV = cV - matrix[i][0] + matrix[i][1];
            
            if(cV > max){
                max = cV;
            }
        }
        else{
            cV = cV - matrix[i][0];
        }

    }
    cout << max << endl;
	return 0;
}