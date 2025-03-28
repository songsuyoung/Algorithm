#include <bits/stdc++.h>
using namespace std;

string getMenu(const vector<string> &orders)
{
    //1. 조합을 만든다. (1개 이상인 것들을 기준으로)
    unordered_map<char,int> cnts;
    
    for(int i=0; i<orders.size(); i++)
    {
        for(int j=0; j<orders[i].size(); j++)
        {
            cnts[orders[i][j]]++;
        }
    }
    
    string menu = "";
    for(const auto& cnt : cnts)
    {
        if(cnt.second >= 2)
        {
            menu+=cnt.first; //2개 이상인 것들을 모아서 조합하기 위해서 2개 이상인 메뉴를 하나의 스트링으로 묶는다.
        }
    }
    
    return menu;
}
int isCheck(const string& menu,vector<string> &orders)
{
    int cnt=0;
    for(int p=0; p<orders.size(); p++)
    {
        int i=0;
        for(; i<menu.size(); i++)
        {
            if(orders[p].find(menu[i]) == string::npos)
            {
                break;
            }
        }
        
        if(menu.size()<=i)
        {
            cnt++;   
        }
    }
    return cnt;
}
//2. 조합을 만든다.
unordered_map<string,int> m;
bool isVisited[21]; //2~20 이하
void recursive(int N, vector<string> &orders,const string &menu,string comb, int idx)
{
    if(comb.size()>=N)
    {
        //조합을 만들었음.
        //이제 해당 음식의 조합을 각 사람들이 몇번 시켰는지 확인해야한다.
        
        int cnt = isCheck(comb, orders);
        if(cnt>=2)
        {
            //저장한다.
            m[comb] = cnt;
        }
        return;
    }
    for(int i=idx; i<menu.size(); i++)
    {
        if(isVisited[i]) continue;
        isVisited[i]=true;
        recursive(N, orders, menu, comb+menu[i], i+1);
        isVisited[i]=false;
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    string menu = getMenu(orders);
    
    for(int i=0; i<course.size(); i++)
    {
        recursive(course[i], orders, menu, "", 0);
    }
    
    
    // 사이즈가 같은애들끼리 2, 3, 4 큰 값을 찾음. 그리고 그 큰 값이 같으면 answer.push_back
    unordered_map<int,int> size;
    
    for(const auto& possible : m)
    {
        int idx = possible.first.size();
        if(size[idx]<possible.second)
        {
            size[idx] = possible.second;
        }
    }
    
    for(const auto& possible : m)
    {
        int idx = possible.first.size();
        
        if(size[idx] == possible.second)
        {
            string tmp = possible.first;
            
            sort(tmp.begin(), tmp.end());
            
            answer.push_back(tmp);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

/*
스카피 메뉴 새로 구성
단품으로만 제공하던 메뉴를 (조합) => recursive or iterator
가장 많이 함께 주문한 단품메뉴들을 코스메뉴로 구성
2가지 이상의 단품 메뉴로 구성 => 2가지 이상이기 때문에 iterator 불가능
최소 2명 이상의 손님으로부터 주문된 단품 메뉴

예)

A B C D E F G H
4 2 6 3 3 2 2 1

=> 최소 2명 이상이기 때문에 H는 단품 메뉴에서 빠짐.

A B C D E F G 를 조합

A C => 4 (Max값만 살아남음. Max값이 같을 경우에는 코스요리에 같이 추가)
A D => 2
A E => 2
... 조합 진행(2개 이상 ~ 6개 까지 가능)

1. 조합을 만든다.
2. 조합(string), 주문 횟수 체크한다.
    만약 주문 횟수가 2보다 작을 경우에 저장하지 않는다. 
3. 저장된 조합을 주문 횟수에 따라 정렬한다.
4. 각 코스별 Max 값들을 answer에 저장한다.
5. answer을 사전순으로 정렬한다.
*/