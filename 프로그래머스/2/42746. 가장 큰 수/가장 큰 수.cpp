#include <bits/stdc++.h>
using namespace std;

bool compare(const string& num1,const string& num2)
{
    int minVal = min(num1.size(), num2.size());
    
    for(int i=0; i<minVal; i++)
    {
        if(num1[i] != num2[i])
        {
            return num1[i]>num2[i];
        }
    }
    
    //모두 같을 경우
    //둘이 붙여보자
    return stoi(num1+num2)>stoi(num2+num1);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    //문자열 number를 만든다.
    vector<string> tostr;
    
    for(int i=0; i<numbers.size(); i++)
    {
        tostr.push_back(to_string(numbers[i]));
    }
    
    sort(tostr.begin(), tostr.end(), compare);
    
    int zero=0;
    for(int i=0; i<tostr.size(); i++)
    {
        if(tostr[i] == "0")
        {
            zero++;
        }
        answer+=tostr[i];
    }
    
    if(zero==tostr.size())
    {
        answer="0";
    }
    
    return answer;
}

/*
0 또는 양의 정수, 정수를 이어 붙여 만들 수 있는 가장 큰수

6 10 2

3 30 34 5 9

=> 정렬해서 문자열로 합치면되는 문제인데

*
 두자리 수 검사를 할 때에 큰 수 먼저 
*
 한자리수 두자리수 검사라면, 한자리수를 기준으로 정렬
 즉, min값 
*/