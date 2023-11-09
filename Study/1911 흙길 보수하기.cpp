#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N,L;
    cin>>N>>L;

    vector<pair<int,int>> v;

    for(int i=0;i<N;i++)
    {
        int s,e;
        cin>>s>>e;
        v.push_back(make_pair(s,e));
    }

    sort(v.begin(),v.end(),[](pair<int,int> &a,pair<int,int> &b)-> bool
    {
        return a.first==b.first? a.second>b.second:a.first<b.first;
    });

    //시작은 -1 작게 시작.
    int cnt=0; //이미 한개 선택함
    pair<int,int> pos=make_pair(v[0].first-1,0);
    for(int i=0;i<N;i++)
    {
        if(v[i].second<=pos.second)
            continue;
        if(v[i].first<=pos.second)
        {
            pos.first=pos.second+1;
        }else{
            pos.first=v[i].first;
        }

        int count=ceil((abs((pos.first)-(v[i].second))/(double)L)); //물 웅덩이를 덮을 판지 개수
        
        pos.second=(pos.first-1)+(L*count);

        cnt+=count;
        //1-6 => 물 웅덩이는 5개(1,2,3,4,5)
        //올림 함수를 이용해서 개수 체크 5/2=2 나올 수 있도록 pow 이용
        //시작위치는 1~(1-1)+(3*2) 덮음
        //8-12 => 물 웅덩이는 4개 (8,9,10,11)
        //올림 함수 이용해서 널판지 2개 
        //8~(8-1)+6 =>13   
        //13~17
        //second==first first+1
        //14~17 => 물 웅덩이는 3개 (14,15,16)
        //널판지 1개
        //14~(14-1)+3 =>16
    //    cout<<count<<' '<<pos.first<<' '<<pos.second<<' '<<v[i].first<<' '<<v[i].second<<'\n';
    }
    cout<<cnt<<'\n';
}
