#include<iostream>
#include<queue>

using namespace std;

struct infectTomato {
	int x,y;
};

queue<infectTomato> q;
const int M = 6;
const int N = 4;

int tomatoBox[N][M] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1}
};
// int tomatoBox[N][M] = {
// 	{0, -1, 0, 0, 0, 0},
// 	{-1, 0, 0, 0, 0, 0},
// 	{0, 0, 0, 0, 0, 0},
// 	{0, 0, 0, 0, 0, 1}
// };
// int tomatoBox[N][M] = {
// 	{1, -1, 0, 0, 0, 0},
// 	{0, -1, 0, 0, 0, 0},
// 	{0, 0, 0, 0, -1, 0},
// 	{0, 0, 0, 0, -1, 1}
// };
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool checkWay(int x, int y){
	if(x < 0  || x >= N || y < 0 || y >=M){
		return false;
	}
	return true;
}

void BFS(){
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!checkWay(nx, ny)){
				continue;
			}
			else if(tomatoBox[nx][ny] != 0){
				continue;
			}
			tomatoBox[nx][ny] = tomatoBox[x][y] + 1;
			q.push({nx, ny});
		}
	}
}

int main(){
	int max = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(tomatoBox[i][j] == 1){
				q.push({i, j});
			}
		}
	}
	BFS();
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(tomatoBox[i][j] == 0){
				cout << -1 << endl;
				return 0;
			}
			if(tomatoBox[i][j] > max){
				max = tomatoBox[i][j];
			}
		}
		
	}	
	cout << max - 1 << endl;
	return 0;
}