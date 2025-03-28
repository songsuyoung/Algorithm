#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, string term)
{
    int pos=0;
    vector<string> v;
    while((pos = str.find(term))!=string::npos)
    {
        string sub = str.substr(0, pos);
        v.push_back(sub);
        str.erase(0, pos + term.size());
    }
    v.push_back(str);

    return v;
}

struct person
{
    string lang;
    string job;
    string year;
    string food;
    string score;
};

unordered_map<string, vector<int>> score;

void recursive(vector<string>& p, string info, int idx)
{
    if(idx+1>=p.size()) //점수는 그냥 삽입
    {
        score[info].push_back(stoi(p[idx]));
        return;
    }
    //선택한다.
    recursive(p, info+p[idx],idx+1);
    //안한다.
    recursive(p, info+"-",idx+1);
}

int binary_search(vector<int> &sc, int dest)
{
    int left = 0;
    int right = sc.size();
    
    while(left<right)
    {
        int mid = (left+right)/2;
        
        //cout<<mid<<' '<<sc[mid]<<' '<<dest<<'\n';
        if(sc[mid]>=dest)
        {
            right = mid;
        }
        else if(sc[mid]<dest)
        {
            left = mid+1;
        }
    }
    
    return left;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(),0);
    
    vector<person> p;
    
    for(int i=0; i<info.size(); i++)
    {
        vector<string> tmp = split(info[i], " "); //띄어쓰기
        
        recursive(tmp, "", 0);
    }
    
    for(auto &s : score) 
    {
        //내부 정렬
        sort(s.second.begin(), s.second.end());
    }
    for(int i=0; i<query.size(); i++)
    {
        vector<string> tmp = split(query[i], " and ");
        vector<string> tmp1 = split(tmp[3], " ");
        
        string q = tmp[0]+tmp[1]+tmp[2]+tmp1[0];
        
        //이분 탐색 => 맵은 정렬되어있기 때문에 이분탐색
        int idx = binary_search(score[q],stoi(tmp1[1]));
        
        answer[i] = score[q].size()-idx;
    }
    // p에 대해서 가질 수 있는 조합을 만든다.
    // 선택한다. 안한다. (안할 경우 -)
    
    return answer;
}

/*
공채 채용을 진행

- cpp/java/python
- backend/frontend
- junior/senior
- chicken/pizza

=> 질문 주면, 해당 몇 명인지 알 수 있는 도구를 만들기

vector<set<set<set<set<string>>>>
[cpp][backend][junior][chicken].push_back 으로 저장.
[cpp][frontend][junior][chicken]
...만들자

1 for - 언어에 대해서3
2. for - 직종2
3. junior/senior2
4. 2

즉, 정답 3*2*2*2 =>24개의 종류가 나옴.
겹치는 사람이 있기 때문에
*/