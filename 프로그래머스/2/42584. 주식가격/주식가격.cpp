#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    stack<int> stock;
    
    for(int i=0; i<prices.size(); i++)
    {
        while(!stock.empty() && prices[stock.top()] > prices[i])
        {
            int idx = stock.top();
            
            //작을 경우에 빼져야한다.
            answer[idx] = i - idx; //4-3 => 1초간 유지
            stock.pop();
        }
        
        stock.push(i); //idx 저장
    }
    
    //마지막에 도달해서 전부 pop
    
    while(!stock.empty())
    {
        answer[stock.top()] = prices.size() - (stock.top()+1);
        stock.pop();
    }
    
    return answer;
}

/*
주식가격이 담긴 배열 prices 가 매개변수로 주어질 때 가격이 떨어지지 않은 기간은 몇 초인지를 return

예)

 1 2 3 2 3
 4 3 1 1 0
 
 끝은 항상 0 5-5
            5-4 => 1
            5-1 => 4
 1 2 3 -> 2 3  (떨어짐)
     1    1 0
     
스택으로 쌓이는 구조
*/