#include<iostream>
#include <vector>
#include <queue>

using namespace std;
struct hanoi {
	vector<vector<int>> hanoitop;
	int beforesticknum;
	int aftersticknum;
	int cnt;
};
vector< vector<int> > hanoiTop({
    
    vector<int>({2, 1}),
    vector<int>({4, 3}),
    vector<int>({7, 6, 5}),
    
});
queue<hanoi> q;

void start(){

	q.push({hanoiTop, 999, 999, 0});
	while(!q.empty()){
		vector< vector<int> > nhanoiTop = q.front().hanoitop;
		int nbeforesticknum = q.front().beforesticknum;
		int naftersticknum = q.front().aftersticknum;
		int nCnt = q.front().cnt;
		
		
		
		if(nbeforesticknum != 999){
			int diskNum = nhanoiTop[nbeforesticknum].back();
			nhanoiTop[nbeforesticknum].pop_back();
			nhanoiTop[naftersticknum].push_back(diskNum);
			nCnt++;
		}
		q.pop();

		if(nhanoiTop[0].size() == 7 || nhanoiTop[1].size() == 7 || nhanoiTop[2].size() == 7){
			for(int i=0; i<nhanoiTop.size(); i++){
				for(int j=0; j<nhanoiTop[i].size(); j++){
					cout << nhanoiTop[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << nCnt << endl;		
			cout << "end!!" << endl;
			return;
		}
		for(int i=0; i<nhanoiTop.size(); i++){
	
				if(i == 0 && nhanoiTop[i].size() != 0){
					
					if(nhanoiTop[i+1].size() == 0 || nhanoiTop[i][nhanoiTop[i].size() - 1] < nhanoiTop[i+1][nhanoiTop[i+1].size() - 1] ){
						q.push({nhanoiTop, i, i+1, nCnt});
					}
					if(nhanoiTop[i+2].size() == 0 || nhanoiTop[i][nhanoiTop[i].size() - 1] < nhanoiTop[i+2][nhanoiTop[i+2].size() - 1]){
						q.push({nhanoiTop, i, i+2, nCnt});
					}	
				}else if(i == 1 && nhanoiTop[i].size() != 0){

					if(nhanoiTop[i-1].size() == 0 || nhanoiTop[i][nhanoiTop[i].size() - 1] < nhanoiTop[i-1][nhanoiTop[i-1].size() - 1]){
						q.push({nhanoiTop, i, i-1, nCnt});
					}
					if(nhanoiTop[i+1].size() == 0 || nhanoiTop[i][nhanoiTop[i].size() - 1] < nhanoiTop[i+1][nhanoiTop[i+1].size() - 1]){
						q.push({nhanoiTop, i, i+1, nCnt});
					}	
				}else if(i == 2 && nhanoiTop[i].size() != 0){
				
					if(nhanoiTop[i-2].size() == 0 || nhanoiTop[i][nhanoiTop[i].size() - 1] < nhanoiTop[i-2][nhanoiTop[i-2].size() - 1]){
						q.push({nhanoiTop, i, i-2, nCnt});
					}
					if(nhanoiTop[i-1].size() == 0 || nhanoiTop[i][nhanoiTop[i].size() - 1] < nhanoiTop[i-1][nhanoiTop[i-1].size() - 1]){
						q.push({nhanoiTop, i, i-1, nCnt});
					}
				}
		
		}


		
	}


}

int main(){
	 

	start();
	
	return 0;
}