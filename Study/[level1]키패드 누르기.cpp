#include <string>
#include <vector>
#include <iostream>

using namespace std;


string solution(vector<int> numbers, string hand) {

    string answer="";
    pair<pair<int,int>,pair<int,int>> handsPos=make_pair(make_pair(3,0),make_pair(3,2)); //왼쪽 위치, 오른쪽 위치
    for(int i=0;i<numbers.size();i++){
        //1. 거리를 확인한다.
        pair<int,int> targetPos;
        if(numbers[i]==0){
            numbers[i]=11;  
        }
        targetPos=make_pair((numbers[i]-1)/3,(numbers[i]-1)%3); //목표 위치    
        if(numbers[i]==1||numbers[i]==4||numbers[i]==7){
            //왼손
            answer+="L";
            handsPos.first=targetPos;
        }else if(numbers[i]==3||numbers[i]==6||numbers[i]==9){
            //오른손
            answer+="R";
            handsPos.second=targetPos;
        }else{
            int leftDis=abs(targetPos.first-handsPos.first.first)+abs(targetPos.second-handsPos.first.second);
            int rightDis=abs(targetPos.first-handsPos.second.first)+abs(targetPos.second-handsPos.second.second);
            //거리가 다르다-> 가까운 손으로 누른다.
            //2. 거리가 같다
            if(leftDis>rightDis){
                answer+='R';
                handsPos.second=targetPos;
            }else if(leftDis<rightDis){
                answer+='L';
                handsPos.first=targetPos;
            }else{
                if(hand=="right"){
                    answer+='R';
                    handsPos.second=targetPos;
                }else{
                    answer+='L';
                    handsPos.first=targetPos;
                }
            }
            // 사용자의 이용 손가락으로 누른다.
            
        }
    }
    return answer;
}