#include <iostream>
#include <vector>

using namespace std;
#define MAX_SIZE 21

int N;
int team[MAX_SIZE];
int value[6][6] = {
		{0, 1, 2, 3, 4, 5},
		{1, 0, 2, 3, 4, 5},
		{1, 2, 0, 3, 4, 5},
		{1, 2, 3, 0, 4, 5},
		{1, 2, 3, 4, 0, 5},
		{1, 2, 3, 4, 5, 0}
	};
int minValue = 99999999;

void DFS(int memberNum, int cnt){

	if(cnt == N/2){

		vector<int> startTeam, linkTeam;
		for(int i = 0; i < N; i++){
			if(team[i] == 1){
				startTeam.push_back(i);

			}else{
				linkTeam.push_back(i);

			}
		}

		int startbalue = 0;
		int linkValue = 0; 
		for(int i = 0; i < startTeam.size(); i++){
			for(int j = 0; j < startTeam.size(); j++){
				int fstartNum = startTeam[i];
				int sstartNum = startTeam[j];
				int flinkNum = linkTeam[i];
				int slinkNum = linkTeam[j];

				startbalue += value[fstartNum][sstartNum];
				linkValue += value[flinkNum][slinkNum];
			}
		}

		minValue = min(minValue, abs(startbalue - linkValue));
		cout << minValue << endl;
		return;

	}

	for(int i = memberNum; i < N; i++){
		team[i] = 1;
		DFS(i,cnt + 1);
		team[i] = 0;
	}

}
int main()
{

	N = 6;
	for(int i=0; i < N; i++){
		team[i] = 0;
	}	

	for(int i = 0; i < N; i++){
		team[i] = 1;
		DFS(i,1);
		team[i] = 0;
	}
    
	cout << minValue << endl;
    return 0;
}