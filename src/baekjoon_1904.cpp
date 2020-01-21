#include<iostream>


using namespace std;

int sum = 0;
int *arrValue;
int fibonacci(int n){
	if(n == 1){
		arrValue[n] = 1;
		
		return 1;
	}
	if(n == 2){
		arrValue[n] = 2;
		return 2;
	}
	if(arrValue[n] !=0){
		return arrValue[n];
	}
	sum = fibonacci(n - 1) + fibonacci(n -2) ;
	arrValue[n] = sum % 15746;
	return sum;
}
int main(){
	int N = 1000000;
	arrValue = new int[N + 1];

	for(int i=0; i<=N; i++){
		arrValue[i] = 0;
	}
	
	int result = fibonacci(N % 15746);
	cout << result << endl;
	

	return 0;
}