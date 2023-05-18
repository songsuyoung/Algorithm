/*
1) 8x8 연달아 있을 때 MxN 크기를 어떻게 위치할지 
2) BW 패턴과 WB 패턴 각각 수행해, 최소 cnt를 확인
*/
#include <iostream>

using namespace std;

int main()
{
    
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M,N;
    cin>>N>>M;
    
    
    string WBPattern="WBWBWBWB";
    string BWPattern="BWBWBWBW";
    
    string *block=new string[N];
    for(int i=0;i<N;i++){
        cin>>block[i];
    }
    
    int wmin=100;
    int bmin=100;
    
    for(int i=0;i+7<N;i++){
        for(int j=0;j+7<M;j++){
            int wbcount=0;
            int bwcount=0;

            for(int k=0;k<8;k++){
                for(int o=0;o<8;o++){
                    
                    if(k%2==0){
                        if(block[i+k][j+o]!=WBPattern[o]){
                            wbcount++;
                        }
                        if(block[i+k][j+o]!=BWPattern[o]){
                            bwcount++;
                        }
                    }else{
                        if(block[i+k][j+o]!=BWPattern[o]){ //10x10 -> 2 
                            wbcount++;
                        }
                        if(block[i+k][j+o]!=WBPattern[o]){
                            bwcount++;
                        }
                    }
                }
            }
            
            if(wmin>=wbcount){
                wmin=wbcount;
            }
            if(bmin>=bwcount){
                bmin=bwcount;
            }
            
        }
    }
    
    int min=wmin<bmin?wmin:bmin;
    if(wmin==100||bmin==100)
        min=0;
        
    cout<<min;
    return 0;
}