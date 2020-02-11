#include<iostream>
#include <vector>
#include <queue>

using namespace std;
struct hanoi {
	vector<vector<int>> hanoitop;
	int beforesticknum;
	int aftersticknum;
};
vector< vector<int> > hanoiTop({
    
    vector<int>({2, 1}),
    vector<int>({3}),
    vector<int>({7, 6, 5, 4}),
    
});
queue<hanoi> q;
int cnt = 0;
void BFS(){


	while(!q.empty()){
		vector< vector<int> > nhanoiTop = q.front().hanoitop;
		int nbeforesticknum = q.front().beforesticknum;
		int naftersticknum = q.front().aftersticknum;
		int diskNum = nhanoiTop[nbeforesticknum].back();
		q.pop();
		nhanoiTop[nbeforesticknum].pop_back();
		nhanoiTop[naftersticknum].push_back(diskNum);
		for(int i=0; i<nhanoiTop.size(); i++){
			for(int j=0; j<nhanoiTop[i].size(); j++){
				cout << nhanoiTop[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		if(nhanoiTop[0].size() == 7 || nhanoiTop[1].size() == 7 || nhanoiTop[2].size() == 7){
			cout << "end!!" << endl;
			return;
		}
		for(int i=0; i<nhanoiTop.size(); i++){
			for(int j=nhanoiTop[i].size() - 1; j <= nhanoiTop[i].size() - 1; j++){
				// cout << i << ", " << j << endl;
				if(i == 0){
					if(nhanoiTop[i].size() == 0){
						continue;
					}
					if(nhanoiTop[i][j] < nhanoiTop[i+1][nhanoiTop[i+1].size() - 1]){

						q.push({nhanoiTop, i, i+1});
					}
					if(nhanoiTop[i][j] < nhanoiTop[i+2][nhanoiTop[i+2].size() - 1]){

						q.push({nhanoiTop, i, i+2});
					}	
				}else if(i == 1){
					if(nhanoiTop[i].size() == 0){
						continue;
					}
					if(nhanoiTop[i][j] < nhanoiTop[i-1][nhanoiTop[i-1].size() - 1]){

						q.push({nhanoiTop, i, i-1});
					}
					if(nhanoiTop[i][j] < nhanoiTop[i+1][nhanoiTop[i+1].size() - 1]){

						q.push({nhanoiTop, i, i+1});
					}	
				}else{
					if(nhanoiTop[i].size() == 0){
						continue;
					}					
					if(nhanoiTop[i][j] < nhanoiTop[i-2][nhanoiTop[i-2].size() - 1]){

						q.push({nhanoiTop, i, i-2});
					}
					if(nhanoiTop[i][j] < nhanoiTop[i-1][nhanoiTop[i-1].size() - 1]){

						q.push({nhanoiTop, i, i-1});
					}
				}
			}
		}



		
	}


}

int main(){
	 
	for(int i=0; i<hanoiTop.size(); i++){
		for(int j=hanoiTop[i].size() - 1; j <= hanoiTop[i].size() - 1; j++){
			
			if(i == 0){
				if(hanoiTop[i][j] < hanoiTop[i+1][hanoiTop[i+1].size() - 1]){

					q.push({hanoiTop, i, i+1});
				}
				if(hanoiTop[i][j] < hanoiTop[i+2][hanoiTop[i+2].size() - 1]){

					q.push({hanoiTop, i, i+2});
				}	
			}else if(i == 1){
				if(hanoiTop[i][j] < hanoiTop[i-1][hanoiTop[i-1].size() - 1]){

					q.push({hanoiTop, i, i-1});
				}
				if(hanoiTop[i][j] < hanoiTop[i+1][hanoiTop[i+1].size() - 1]){

					q.push({hanoiTop, i, i+1});
				}	
			}else{
				if(hanoiTop[i][j] < hanoiTop[i-2][hanoiTop[i-2].size() - 1]){

					q.push({hanoiTop, i, i-2});
				}
				if(hanoiTop[i][j] < hanoiTop[i-1][hanoiTop[i-1].size() - 1]){

					q.push({hanoiTop, i, i-1});
				}
			}
		}
	}
	BFS();
	// for(int i = 0; i<q.size(); i++){
	// 	// cout << q.front().sticknum << " ";
	// }
	return 0;
}