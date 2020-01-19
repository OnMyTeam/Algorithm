#include<iostream>


using namespace std;

int sum = 0;
int zeroCnt, oneCnt;
int fibonacci(int n){
	if(n == 0){
		zeroCnt++;
		return 0;
	}
	if(n == 1){
		oneCnt++;
		return 1;
	}
	sum = fibonacci(n - 1) + fibonacci(n -2);
	return sum;
}
int main(){
	
	zeroCnt = 0;
	oneCnt = 0;
	int N = 3;
	for(int i=0; i<N;i++){
		int temp;
		cin >> temp;
		fibonacci(temp);
		cout << zeroCnt << " " << oneCnt << endl;
		zeroCnt = 0;
		oneCnt = 0;
	}
	
	

	return 0;
}