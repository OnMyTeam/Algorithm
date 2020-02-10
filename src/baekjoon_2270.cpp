#include<iostream>
#include <vector>

using namespace std;

vector< vector<int> > hanoiTop({
    
    vector<int>({2, 1}),
    vector<int>({3}),
    vector<int>({7, 6, 5, 4}),
    
});
int cnt = 0;
void hanoi(int stick, int diskNum){
	for(int i=0; i<hanoiTop.size(); i++){
		for(int j=0; j < hanoiTop[i].size(); j++){
			cout << hanoiTop[i][j] << " ";
		}
		cout << endl;
	}	
	cout << endl;
	if(stick == 0){

		int secondStick = stick + 1;
		int secondLastIndex = hanoiTop[secondStick].size() - 1;
		int thirdStick = stick + 2;
		int thirdLastIndex = hanoiTop[thirdStick].size() - 1;
		// stick1 < stick2
		if(hanoiTop[secondStick][secondLastIndex] > hanoiTop[stick][diskNum]){

			hanoiTop[secondStick].push_back(hanoiTop[stick][diskNum]);	
			hanoiTop[stick].pop_back();
			for(int stick=0; stick<hanoiTop.size(); stick++){
				for(int diskNum=hanoiTop[stick].size() - 1; diskNum <= hanoiTop[stick].size() - 1; diskNum++){
					if(diskNum == -1){
						continue;
					}					
					hanoi(stick, diskNum);

				}

			}
		}
		// stick1 < stick3
		if(hanoiTop[thirdStick][thirdLastIndex] > hanoiTop[stick][diskNum]){
			hanoiTop[thirdStick].push_back(hanoiTop[stick][diskNum]);	
			hanoiTop[stick].pop_back();
			for(int i=0; i<hanoiTop.size(); i++){
				for(int j=hanoiTop[i].size() - 1; j <= hanoiTop[i].size() - 1; j++){
					if(j == -1){
						continue;
					}
					hanoi(thirdStick, thirdLastIndex);

				}

			}			
		}
	}else if(stick == 1){

		int firststick = stick - 1;
		int firstLastIndex = hanoiTop[firststick].size() - 1;
		int thirdStick = stick + 1;
		int thirdLastIndex = hanoiTop[thirdStick].size() - 1;

		// stick1 > stick2
		if(hanoiTop[firststick][firstLastIndex] > hanoiTop[stick][diskNum]){

			hanoiTop[firststick].push_back(hanoiTop[stick][diskNum]);	
			hanoiTop[stick].pop_back();
			for(int stick=0; stick<hanoiTop.size(); stick++){
				for(int diskNum=hanoiTop[stick].size() - 1; diskNum <= hanoiTop[stick].size() - 1; diskNum++){
					hanoi(stick, diskNum);
				}
			}
		}		
		// stick3 > stick2
		if(hanoiTop[thirdStick][thirdLastIndex] > hanoiTop[stick][diskNum]){

			hanoiTop[thirdStick].push_back(hanoiTop[stick][diskNum]);	
			hanoiTop[stick].pop_back();
			for(int stick=0; stick<hanoiTop.size(); stick++){
				for(int diskNum=hanoiTop[stick].size() - 1; diskNum <= hanoiTop[stick].size() - 1; diskNum++){
					hanoi(stick, diskNum);
				}
			}
		}				

	}else{

	}


}

int main(){
	 
	for(int i=0; i<hanoiTop.size(); i++){
		for(int j=hanoiTop[i].size() - 1; j <= hanoiTop[i].size() - 1; j++){
			hanoi(i, j);
			cout << hanoiTop[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}