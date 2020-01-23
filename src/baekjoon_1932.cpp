#include<iostream>
#include <vector>

using namespace std;

int sum = 0;
// vector<int> graph[5];

vector< vector<int> > triangle({
    vector<int>({7}),
    vector<int>({3, 8}),
    vector<int>({8, 1, 0}),
    vector<int>({2, 7, 4, 4}),
    vector<int>({4, 5, 2, 6, 5}),
    
});
int jaegwi(int idx, int v, int sum){
    
    if(idx == 5) {
        cout << sum << endl;
    }

    sum = triangle[idx][i];   
    jaegwi(idx + 1, i, sum);

	return sum;
}
int main(){
	

	int result = jaegwi(0, 0, sum);
    cout << result << endl;
	return 0;
}