#include<iostream>
#include<queue>

using namespace std;

struct XY{
	int x,y;
};

queue<XY> q;
const int N = 7;

int matrix[N][N] = {
	{0, 1, 1, 0, 1, 0, 0},
	{0, 1, 1, 0, 1, 0, 1},
	{1, 1, 1, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 1, 1},
	{0, 1, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 0, 0, 0},
};


int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool checkWay(int x, int y){
	if(x < 0  || x >= N || y < 0 || y >=N){
		return false;
	}
	return true;
}

void DFS(int x, int y, int num){
	matrix[x][y] = num;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!checkWay(nx, ny)){
			continue;
		}
		else if(matrix[nx][ny] == 0 || matrix[nx][ny] == num){
			continue;
		} 

		DFS(nx, ny, num);
	}
}

int main(){
	int num = 1;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(matrix[i][j] == 1){
				cout << matrix[i][j] << endl;
				DFS(i, j, num);
				num ++;
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}		

	return 0;
}