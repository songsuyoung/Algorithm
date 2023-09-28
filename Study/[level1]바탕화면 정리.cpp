#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer={55,55,0,0}; //S는 최소 행,열 E는 최대 행,열
    
    //가장 왼쪽에 있는 열, 가장 위쪽에 있는 행 -> S(r,c)
    //가장 오른쪽에 있는 열, 가장 밑쪽에 있는 행 -> E(r,c)
    for(int r=0;r<wallpaper.size();r++){
        for(int c=0;c<wallpaper[r].length();c++){
            
            if(wallpaper[r][c]=='#'){
                //가장 왼쪽에 있는가를 확인
                if(answer[0]>r){
                    answer[0]=r;
                }
                if(answer[1]>c){
                    answer[1]=c;
                }
                if(answer[2]<=r){
                    answer[2]=r+1;
                }
                if(answer[3]<=c){
                    answer[3]=c+1;
                }
                
            }
            
        }
    }
    return answer;
}