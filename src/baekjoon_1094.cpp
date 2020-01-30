#include<iostream>
#include <vector>

using namespace std;




int main(){
    vector<int> half;
    vector<int> Save;
    int initBar = 64;
	int X = 24;
    int N = 0;
    int bhalf = 0;
    int cnt = 0;
    int sum = 0;
    bool check = true;
    while(check){
        bhalf = initBar/2;
        Save.push_back(bhalf);
        for(int i=0; i<Save.size(); i++){
            sum = sum + Save[i];
            if(sum == X){
                cout << sum << endl;
                break;
            }
        }
        if(sum == X){
            cout << sum << endl;
            break;
        }
        else{
            sum = 0;
        }
        initBar = bhalf;
    }

	return 0;
}