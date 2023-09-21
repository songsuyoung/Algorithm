#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    /*이 주제는 callings의 순서가 매우 중요하다.*/
    map<string,int> moving; //players와 players 인덱스를 담는 map 변수를 만든다.
    map<int,string> names;
    
    for(int i=0;i<players.size();i++){
        moving[players[i]]=i;
        names[i]=players[i];
    }
    
    for(int i=0;i<callings.size();i++){
        int idx=moving[callings[i]]; //추월한 선수 idx가져오기
        names[idx]=names[idx-1]; //[1] = a
        moving[names[idx]]=idx; //a = 1
        names[idx-1]=callings[i]; //[0]= b
        moving[names[idx-1]]=idx-1; //b =0
    }
    
    for(int i=0;i<players.size();i++){
        players[i]=names[i];
    }

    return players;
}