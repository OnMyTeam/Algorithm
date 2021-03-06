#include <iostream>

#include <algorithm>

using namespace std;

const int N = 5;
const int M = 12;
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
					r = r + 1;
				}
				else if(r > 0 && ladder[j][r - 1] == 1){
					r = r - 1;
				}
				
			}

			if(i != r){
				success = false;
				break;
			}
		}
		if(success){
			cout << "success!! " << cnt << endl;
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

}

int main(void){
	for(int i=0; i < H; i++){
		for(int j=0; j < N; j++){
			ladder[i][j] = 0;
		}
	}
	ladder[0][0] = 1;
	ladder[1][1] = 1;
	ladder[2][2] = 1;
	ladder[3][3] = 1;
	ladder[2][0] = 1;
	ladder[3][1] = 1;
	ladder[4][2] = 1;
	ladder[5][3] = 1;

	for(int i=0; i<=3; i++){
		stickCnt = i;
		runLadderDFS(0, 0);
	}
	if(!success){
		cout << "fail!! " << -1 << endl;
	}







}