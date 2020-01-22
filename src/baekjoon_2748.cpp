#include<iostream>


using namespace std;

int sum = 0;
int *arrValue;
int fibonacci(int n){
	if(n == 0){
		arrValue[n] = 0;
		return 0;
	}
	if(n == 1){
		arrValue[n] = 1;
		return 1;
	}
	if(arrValue[n] != 0){
		return arrValue[n];
	}
	sum = fibonacci(n - 1) + fibonacci(n - 2);
	arrValue[n] = sum;
	return arrValue[n];
}
int main(){
	
	int N = 50;	
	arrValue = new int[N + 1];
	for(int i=0; i<=N; i++){
		arrValue[i] = 0;
	}
	int result = fibonacci(N);
	cout << result << endl;

	return 0;
}