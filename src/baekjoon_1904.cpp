#include<iostream>


using namespace std;

long long sum = 0;
long long *arrValue;
long long fibonacci(long long n){
	cout << n << endl;
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
	sum = (fibonacci(n - 1) + fibonacci(n -2)) % 15746;
	arrValue[n] = sum;
	return sum;
}
int main(){
	long long N = 10;
	arrValue = new long long[N + 1];

	for(int i=0; i<=N; i++){
		arrValue[i] = 0;
	}
	
	long long result = fibonacci(N);
	cout << result << endl;
	

	return 0;
}