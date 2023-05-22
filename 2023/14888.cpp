#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;


//base case freqOp - isVisited 빈도수가 같아지면 종료
//isVisited[i]<freqOp[i] 계산 isVisited+=1 recursive 전달
//recursive 순서대로 op를 이용해 경우의 수 계산
// op 5 -> 5!/2 = 60..
pair<int,int> func(vector<int> &sqNum,int *freqOp,int *isVisited,int MaxOpCnt,int freqOpCnt,int i, int sum,pair<int,int> MinToMax){
    //base case - 빈도수 cnt가 최대 operator의 빈도수 개수 보다 크거나 같음 결과를
    //결과를 저장하고 return
    if(freqOpCnt>=MaxOpCnt){
        MinToMax.first=min(MinToMax.first,sum);
        MinToMax.second=max(MinToMax.second,sum);
        //결과 저장
        return MinToMax;
    }
    //recursive
    //현재 연산자 몇개를 이용했는지 freqOpCnt변수를 이용해 확인, +1 시킴
    //반복문은 operator의 개수가 4개지만, 그 내 빈도수 6개.. 모드연산을 이용해 진행.

    //어차피 재귀함수에서 4번을 다 돌예정.
    pair<int,int> results(INT_MAX,INT_MIN);
    pair<int,int> tmp;
   for(int op=0;op<4;op++){
            //isVisited[k]!=freqOp[k] 진행

            if(isVisited[op]!=freqOp[op]){
                //호출
                isVisited[op]++;
                //연산 결과를 저장 하는데, 
                if(op==0){
                    //덧셈 진행
                    tmp=func(sqNum,freqOp,isVisited,MaxOpCnt,freqOpCnt+1,i+1,sum+sqNum[i],MinToMax);
                }else if(op==1){
                    //뺄셈 진행
                    tmp=func(sqNum,freqOp,isVisited,MaxOpCnt,freqOpCnt+1,i+1,sum-sqNum[i],MinToMax);
                }else if(op==2){
                    //곱셈 진행
                    tmp=func(sqNum,freqOp,isVisited,MaxOpCnt,freqOpCnt+1,i+1,sum*sqNum[i],MinToMax);
                }else{
                    //나눗셈 진행
                    tmp=func(sqNum,freqOp,isVisited,MaxOpCnt,freqOpCnt+1,i+1,sum/sqNum[i],MinToMax);
                }
                 //return되면 빈도수 빼기
                isVisited[op]--;
                results.first=min(results.first,tmp.first);
                results.second=max(results.second,tmp.second);
        }
    }
    return results;
}

int main()
{
    
    int N;
    vector<int> sqNum;
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        sqNum.push_back(tmp);
    }
    int MaxOpCnt=0;
    int freqOp[4]={0};
    for(int i=0;i<4;i++){
        cin>>freqOp[i];
        MaxOpCnt+=freqOp[i];
    }
    int isVisited[4]={0};

    pair<int,int> MinToMax=func(sqNum,freqOp,isVisited,MaxOpCnt,0,1,sqNum[0],make_pair(INT_MAX,INT_MIN));
    cout<<MinToMax.second<<' '<<MinToMax.first<<'\n';
    return 0;
}