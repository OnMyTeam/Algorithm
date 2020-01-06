#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int comSize, edgeSize;
    int fromEdge, toEdge;
    cin >> comSize;
    cin >> edgeSize;
    vector< vector<int> > vertex(comSize);

    for(int i=0; i<comSize; i++){
        vector<int> linkedV(comSize);
        vertex.push_back(linkedV);

    }
    for(int i=0; i<comSize; i++){
        for(int j=0; j<comSize; j++){
            vertex[i].push_back(0);
        }
    }    
    for(int i=0; i<edgeSize; i++){
        cin >> fromEdge >> toEdge;
        cout << "value :" << fromEdge << toEdge << endl;
        vertex[fromEdge][toEdge] = 1;
        vertex[toEdge][fromEdge] = 1;

    }
    for(int i=0; i<comSize; i++){
        cout << "vertex :" << i << endl;
        for(int j=0; j<comSize; j++){
            cout << "value :" << vertex[i][j] << " ";
        }
        cout << endl;
    }   


    
    return 0;
}