#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int isPressed(bool *isNotPressed,string N,string output,int num){
    
    int ret=INT_MAX;
    if(isNotPressed[num]){
        return ret;
    }
    
    
    output+=to_string(num);
    if(output.length()!=0)
        ret=abs(stoi(N)-stoi(output))+output.length();
    
    if(output.length()>N.length())
        return ret;
    
    for(int i=0;i<10;i++){
        ret=min(ret,isPressed(isNotPressed,N,output,i));
    }
    
    return ret;
}
int main()
{
    
    string N;
    int M;
    bool isNotPressed[10]={false,};
    
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        isNotPressed[tmp]=true;
    }
    
    //가장 작은 수를 찾기 위해서 백트랙킹을 진행...
    int ret=abs(stoi(N)-100);
    for(int i=0;i<10;i++){
        ret=min(ret,isPressed(isNotPressed,N,"",i));
    }
    cout<<ret<<'\n';
    return 0;
}