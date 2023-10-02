
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//true :왼쪽 먼저 등장 false:왼쪽이 나중에 등장
//현재 왼쪽 a 오른쪽 b
//오름 차순 정렬...시
bool compare(const pair<int,int> &a,const pair<int,int> &b){
    return a.second!=b.second ? a.second<b.second:a.first<b.first;
}

int main(){

    int N;
    cin>>N;

    vector<pair<int,int>> meetings;   
    for(int i=0;i<N;i++){
        int start;
        int end;

        cin>>start>>end;
        meetings.push_back(make_pair(start,end));
    }
    sort(meetings.begin(),meetings.end(),compare);

    int cnt=1;
    int end=meetings[0].second;
    for(int i=1;i<N;i++){
        if(end<=meetings[i].first){
            end=meetings[i].second;
            cnt++;
        }
    }
    cout<<cnt<<'\n';
}