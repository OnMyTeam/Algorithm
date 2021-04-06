#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> save;
    int answer = 0;

    for(int i = 0; i < moves.size(); i++){
        int movesNum = moves[i] - 1;

        for(int j = 0; j < board.size(); j++){
            if(board[j][movesNum] != 0){
                int characterNum = board[j][movesNum];
                save.push_back(characterNum);
                board[j][movesNum] = 0;
                
                for(int i = 0; i < save.size() ; i++){
                     cout << save[i] << endl;
                    if(save.size() == 1){
                        break;
                    }else{
                        if(save[i] == save[i+1]){
                            save.pop_back();
                            save.pop_back();
                            answer++;
                            answer++;
                            break;
                        }
                    }
                }                
                break;
            }
            
        }
        
    }
    cout << answer << endl;
    return answer;
}