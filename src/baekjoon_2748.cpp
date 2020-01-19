#include<iostream>


using namespace std;

int sum = 0;

int fibonacci(int n){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	sum = fibonacci(n - 1) + fibonacci(n -2);
	return sum;
}
int main(){
	
	int N = 10;
	int result = fibonacci(N);
	cout << result << endl;

	return 0;
}