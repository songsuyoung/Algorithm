/*
6번 틀린이유. minCnt의 경우에 걸리는 시간을 의미하는 변수임..
minCnt의 초기값 설정이 잘못되었기에 틀렸음. 왜냐하면 시간은
최악의 경우에 256 * 249(500 픽셀 중 절반이 256인경우) 0으로 떨어져야한다면
2초씩만 해도 100,000초는 넘어버림..난 초기에 만번만 확인하였음
얼마나 더 큰값이 나올지 모르니까.. INT_MAX로 설정하여 해결했음!
*/
#include <iostream>
#include <map>
#include <climits>

using namespace std;

int main()
{
    map<int,int> block;
    
    for(int i=0;i<=256;i++){
        block.insert(make_pair(i,0));
    }
    int N,M,B;
    
    cin>>N>>M>>B;
    
    int max=0;
    int min=INT_MAX;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            int tmp;
            cin>>tmp;
            if(max<=tmp){
                max=tmp;
            }
            if(min>=tmp){
                min=tmp;
            }
            block[tmp]++;
        }
    }
    
    int minCnt=INT_MAX;
    int minheight=0;
    int maxheight=0;

    //최대 max
    
    for(int i=min;i<=max;i++){
        int k=i;//기준 k
        int blockCnt=B; //현재 블록개수.  99
        int sec=0;
        for(int j=min;j<=max;j++){
            if(block[j]!=0){
                int b=k-j;
                if(b<0){//0 - 1 제거용 블록이 쌓아짐
                    sec+=(2*block[j]*abs(j-k));
                    blockCnt+=(block[j]*abs(j-k));
                }
                else if(b>0){ //11 <- 12 쌓기용 블록이 제거됨
                    sec+=(1*block[j]*abs(j-k));
                    blockCnt-=(block[j]*abs(j-k));
                }
            }
        }
        
        if(blockCnt>=0&&minCnt>=sec){
            minCnt=sec;
            minheight=k;
        }
    }
    cout<<minCnt<<' '<<minheight<<'\n';
    return 0;
}