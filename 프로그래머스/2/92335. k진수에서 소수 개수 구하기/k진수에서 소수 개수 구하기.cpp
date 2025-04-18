#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long num)
{
    if(num<=1)
    {
        return false;
    }
    
    for(long long i=2; i<=sqrt(num); i++)
    {
        if(num%i == 0)
        {
            return false;
        }
    }
    
    return true;
}

vector<long long> get_number(string changed_num)
{
    vector<long long> v;
    string num="";
    for(int i=0; i<changed_num.size(); i++)
    {
        if(changed_num[i] == '0')
        {
            if(num.empty() == false)
            {
                v.push_back(stoll(num));
                num="";
            }
        }
        else
        {
            num+=changed_num[i];
        }
    }
    
    if(num.empty() == false)
    {
        v.push_back(stoll(num));    
    }
    
    return v;
}
int solution(int n, int k) {
    int answer = 0;
    
    //k진수로 만든다.
    string changed_num = "";
    
    while(n>=1)
    {
        changed_num+=n%k + '0';
        n/=k;
    }
    
    reverse(changed_num.begin(), changed_num.end()); //문자열은 거꾸로
    //cout<<changed_num<<'\n';
    //0이 아닌 수를 모두 vector에 담고, 소수 인지 아닌지 체크
    
    vector<long long> number = get_number(changed_num);
    
    for(int i=0; i<number.size(); i++)
    {
        if(isPrime(number[i]))
        {
            answer++;
        }
    }
    return answer;
}

/*
양의 정수 n, k진수로 바꾸었을 때 변환된 수 안에 아래 조건이 맞는 소수가 몇 개인지 체크

0P0 처럼 소수 양쪽에 0이 있는 경우 
P0
0P
P => 0을 포함하지 않는 수
*/