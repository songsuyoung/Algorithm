/* 좌표 압축 알고리즘
모든 구간이 아니라, 중요한 구간이나 숫자만 들고 있는 기법
값보다 값의 index가 중요해, 임의의 값으로 변경하되 순위는 유지

sort다음에 erase-unique 진행*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> list;
    vector<int> compreList;

    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int tmp;
        cin>>tmp;
        list.push_back(tmp);
        compreList.push_back(tmp);
    }
    
    sort(compreList.begin(),compreList.end());
    compreList.erase(unique(compreList.begin(),compreList.end()),compreList.end());

    map<int,int> output;
    for(int i=0;i<compreList.size();i++){
        output.insert(make_pair(compreList[i],i));
    }
    
    for(int i=0;i<list.size();i++){
        cout<<output[list[i]]<<' ';
    }

    return 0;
}