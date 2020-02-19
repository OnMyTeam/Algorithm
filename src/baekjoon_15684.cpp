#include <iostream>

#include <algorithm>

using namespace std;

const int N = 5;
const int M = 5;
const int H = 6;
int stickCnt;
int ladder[H][N];

bool success;
void runLadderDFS(int row, int cnt){

	if(stickCnt == cnt){
		
		success = true;
		
		for(int i=0; i < N; i++){
			
			int r = i;
			for(int j=0; j < H; j++){

				if(ladder[j][r] == 1){
					// cout << j << " ," << r << endl;
					r = r + 1;
					// cout << j << " ," << r << endl;
				}
				else if(r > 0 && ladder[j][r - 1] == 1){
					// cout << j << " ," << r << endl;
					r = r - 1;
					// cout << j << " ," << r << endl;

				}
				
			}

			if(i != r){
	
				success = false;
				// cout << "fault!! " << r << endl;
				break;
			}
		}
		// cout << "success!! " << success << endl;
		if(success){
			cout << "success!! " << endl;
			for(int i=0; i < H; i++){
				for(int j=0; j < N; j++){
					cout << ladder[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			return;
		}
	}

	for(int i = row; i < H; i++){
		for(int j=0; j < N; j++){
			if(ladder[i][j] != 1 && ladder[i][j - 1] != 1 && ladder[i][j + 1] != 1){
				ladder[i][j] = 1;
				runLadderDFS(i, cnt + 1);
				ladder[i][j] = 0;
			}

		}
	}
	return;

}

int main(void){
	for(int i=0; i < H; i++){
		for(int j=0; j < N; j++){
			ladder[i][j] = 0;
		}
	}
	ladder[0][0] = 1;
	// ladder[0][2] = 1;
	ladder[2][1] = 1;
	// ladder[2][3] = 1;
	ladder[1][2] = 1;
	// ladder[3][1] = 1;
	ladder[4][0] = 1;
	ladder[4][3] = 1;

	stickCnt = 3;
	runLadderDFS(0, 0);






}