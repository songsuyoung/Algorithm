#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
bool isOk(string maker)
{
    map<char,bool> m{{'a',true},{'e',true},{'i',true},{'u',true},{'o',true}};
    //최소 Maker.length()-2 만큼 있어도 된다.
    int thresh=maker.length()-2; //왜냐면 자음이 최소 2개는 있어야하기 때문에.
    int cnt=0;
    for(int i=0;i<maker.length();i++)
    {
        if(m[maker[i]])
        {
            cnt++;
        }
    }
            //1개 이상 있고, 모음이 4개중 2개까지는 있어도 된다.
    if(cnt<=thresh&&cnt>0)
        return true;

    return false;
}
void dfs(int L,int C,const char *eng,bool isVisited[],string maker,int idx)
{
    if(idx>=C) return ;
    if(maker.length()==L)
    {
        //4글자 완성
        //모음 최소 1개, 자음 최소 2개인지 확인해야하는데, 모음만 1개 이상 N-2개 있으면, OK
        if(isOk(maker))
        {
            cout<<maker<<'\n';
        }
        return ;
    }

    for(int i=idx;i<C;i++)
    {
        if(isVisited[i]) continue;
        isVisited[i]=true;
        dfs(L,C,eng,isVisited,maker+eng[i],i);
        isVisited[i]=false;
    }

}
int main(){
    int L,C;
    cin>>L>>C;

    char eng[16]={};
    bool isVisited[16]={};
    //모음에 대한 map 생성. bool이면, 바로 cnt하기 위해서 => 함수로 빼기
    //존재하는 문자
    for(int i=0;i<C;i++)
    {
        cin>>eng[i];
    }
    //eng: 0번 idx ~ C-1번 idx까지 정렬 
    sort(eng,eng+C);
   
    dfs(L,C,eng,isVisited,"",0);
}