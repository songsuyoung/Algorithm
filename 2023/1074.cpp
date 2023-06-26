//Z
/*
종이 나누기와 비슷한듯...1까지만 가지말고
4등분씩 나눠서 위왼-위오-아왼-아오 순으로 호출하면될거같기듀

*/
#include <iostream>
#include <cmath>

using namespace std;

//4등분씩 자르기
int getArea(int r,int c,pair<long long,long long> start,pair<long long,long long> mid,pair<long long,long long> end){

    if(r<=mid.first&&c<=mid.second){
        return 1;
    }else if(r<=mid.first&&c<=end.second){
        return 2;
    }else if(r<=end.first&&c<=mid.second){
        return 3;
    }else{
        return 4;
    }
}
void Zcount(int r,int c,pair<long long,long long> start,pair<long long,long long> end,int cnt){
       
    if(start==end){
        cout<<cnt<<'\n'; //자기포함
        return;
    }
   
    pair<int,int> mid = make_pair((start.first+end.first)/2,(start.second+end.second)/2);
           
    int area=getArea(r,c,start,mid,end); //구역 나누기
    
    int len=mid.first-start.first+1;
    
    cnt+=(area-1)*(len*len);
    
    if(area==1)
        Zcount(r,c,make_pair(start.first,start.second),make_pair(mid.first,mid.second),cnt);
    else if(area==2)
        Zcount(r,c,make_pair(start.first,mid.second+1),make_pair(mid.first,end.second),cnt);
    else if(area==3)
        Zcount(r,c,make_pair(mid.first+1,start.second),make_pair(end.first,mid.second),cnt);
    else
        Zcount(r,c,make_pair(mid.first+1,mid.second+1),make_pair(end.first,end.second),cnt);
}
int main()
{
    int N,r,c;
    cin>>N>>r>>c;

    pair<long long,long long> end=make_pair(int(pow(2,N))-1,int(pow(2,N))-1);
    pair<long long,long long> start=make_pair(0,0);
    Zcount(r,c,start,end,0);

    return 0;
}