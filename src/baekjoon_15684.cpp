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
		cout << "start!! " << endl;
		success == true;
		for(int i=0; i < N; i++){
			
			int r = i;
			for(int j=0; j < H; j++){

				if(ladder[j][r] == 1){
					cout << j << " ," << r << endl;
					r = r + 1;
					cout << j << " ," << r << endl;
				}
				else if(r > 0 && ladder[j][r - 1] == 1){
					cout << j << " ," << r << endl;
					r = r - 1;
					cout << j << " ," << r << endl;

				}else{
					cout << j << " ," << r << endl;
				}
				
			}
			if(i == r){
				cout << "correct!! " << r << endl;
				
			}
			else{
				success = false;
				cout << "fault!! " << r << endl;
				break;

			}
			cout  << endl;
		}

		if(success == true){
			cout << "success!! " << endl;
			return;
		}
	}

	for(int i = row; i < H; i++){
		for(int j=0; j < N; j++){
			if(ladder[i][j] != 1 && ladder[i][j - 1] != 1 && ladder[i][j + 1] != 1){
				ladder[i][j] == 1;
				cout << i << " ,,," << j << endl;
				runLadderDFS(i, cnt + 1);
				ladder[i][j] == 0;
			}

		}
	}

}

int main(void){
	for(int i=0; i < N; i++){
		for(int j=0; j < H; j++){
			ladder[i][j] = 0;
		}
	}
	ladder[0][0] = 1;
	ladder[2][1] = 1;
	ladder[1][2] = 1;
	ladder[4][0] = 1;
	ladder[4][3] = 1;

	stickCnt = 3;
	runLadderDFS(0, 0);





}