#include<iostream>
#include<queue>
#include <vector>
using namespace std;

int main(){
    int classNum = 1000000;
    vector<int> people;
    vector<int> detect;


    for(int i=0; i<1000000; i++){
        people.push_back(1000000);
    }
    detect.push_back(1);
    detect.push_back(1);

    int minCnt = 0;
    for(int i=0; i<people.size(); i++){

        int iNum = people[i];
        iNum = iNum - detect[0];
        minCnt++;
        int iA = iNum / detect[1];
        int iB = iNum % detect[1];
        
        minCnt = iA;
        if(iB != 0){
            minCnt++;
        }

    }
    cout << minCnt << endl;
	return 0;
}