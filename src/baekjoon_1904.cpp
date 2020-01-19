#include<iostream>


using namespace std;

int sum = 0;

int fibonacci(int n){
	if(n == 1){

		return 1;
	}
	if(n == 2){

		return 2;
	}
	sum = fibonacci(n - 1) + fibonacci(n -2);
	return sum;
}
int main(){
	int N = 4;
	int result = fibonacci(N);
	cout << result << endl;
	

	return 0;
}