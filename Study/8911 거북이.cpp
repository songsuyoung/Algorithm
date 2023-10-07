/*
F : 한 눈금 앞으로, 현재 방향을 고려해서 +1
B : 한 눈금 뒤로, 현재 방향 고려해서 -1
L : 왼쪽으로
R : 오른쪽으로 
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int N;
    vector<string> input;
    
    cin>>N;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        
        input.push_back(tmp);
    }
    //북남
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    // 동 북 서 남
    for(int i=0;i<input.size();i++){
        int dir=1;
        int currX=0,currY=0,minX=0,minY=0,maxX=0,maxY=0;
        for(int j=0;j<input[i].length();j++){
            switch(input[i][j]){
                case 'F':
                currX+=x[dir];
                currY+=y[dir];
                break;
                case 'B':
                currX-=x[dir];
                currY-=y[dir];
                break;
                case 'L':
                //처음 dir =0 왼쪽 이동 시 -1
                if(dir==0){
                    dir=3;
                }else dir--;
                break;
                case 'R':
                //오른쪽 이동시 +1
                if(dir==3){
                    dir=0;
                }else dir++;
                break;
            }
            minX=min(minX,currX);
            minY=min(minY,currY);
            maxX=max(maxX,currX);
            maxY=max(maxY,currY);
        }
        cout<<(abs(minX)+abs(maxX))*(abs(maxY)+abs(minY))<<'\n';
    }
    return 0;
}