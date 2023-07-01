#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
bool isCheck(vector<string> &data,string names){
    //if(data[0] data[2] data[3] data[4]-'0' 사용조건에 해당하지않으면)
    //names에서... data[0] data[2]기준으로 data[4]크기만큼 차이나는지를 확인한다.
    for(int i=0;i<data.size();i++){
        string tmp=data[i];
        
        int a=names.find(tmp[0]);
        int b=names.find(tmp[2]);
        int dis=abs(a-b)-1;
        int thread=tmp[4]-'0';
        
        if(tmp[3]=='=')
        {
            if(dis!=thread)
                return false;
        }else if(tmp[3]=='>'){
            if(dis<=thread)
                return false;
        }else{
            if(dis>=thread)
                return false;
        }
    }
    
    return true;
}
            
int callKakao(vector<string> &data,string names,bool *isVisited,int selectedCnt,string preNames){
    //base
    
    if(selectedCnt>=names.length()){
        if(isCheck(data,preNames))    
            return 1;
        else
            return 0;
    }
    
    int result=0;
    for(int i=0;i<names.length();i++){
        if(!isVisited[i]){
            isVisited[i]=true;
            result+=callKakao(data,names,isVisited,selectedCnt+1,preNames+names[i]);
            isVisited[i]=false;
        }
    }
    
    return result;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    
    string names="ACFJMNRT";
    bool isVisited[8]={false,};
    answer=callKakao(data,names,isVisited,0,"");
    //data를 쪼갠다. 
    return answer;
}