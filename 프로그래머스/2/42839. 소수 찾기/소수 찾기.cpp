#include <bits/stdc++.h>
using namespace std;

bool NotPrime[10'000'000]; //문자열이 최대 가질 수 있는 길이 7이하 즉, 8개 공간을 선언


//9 999 999 => 10'000'000
void setPrime() //에라테스테네스의 체
{
    NotPrime[0] = true;
    NotPrime[1] = true;
    
    for(long long i=2; i*i<10'000'000; i++)
    {
        for(long long j=i*i; j<=10'000'000; j+=i)
        {
            NotPrime[j]=true;
        }
    }
}

bool isVisited[8]; //인덱스 개수만큼
unordered_set<int> st; //중복을 하지않기 위해 저장한다.
void recursive(const string &numbers, string output, int selected)
{
    if(selected<=output.length())
    {
        int num = stoi(output);
        
        if(NotPrime[num] == false)
        {
            st.insert(num);
        }
        return;
    }
        
    for(int i=0; i<numbers.size(); i++)
    {
        if(isVisited[i]) continue;
        isVisited[i]=true;
        recursive(numbers, output+numbers[i], selected);
        isVisited[i]=false;
    }
}

int solution(string numbers) {
    int answer = 0;
    
    setPrime();
    
    sort(numbers.begin(), numbers.end());
    
    for(int i=1; i<=numbers.size();i++)
    {
        do
        {
            string res = "";
            
            for(int j=0; j<i; j++)
            {
               res += numbers[j]; 
            }
            
            int res2 = stoi(res);

            if(NotPrime[res2] == false)
            {
                st.insert(res2);   
            }
        }while(next_permutation(numbers.begin(), numbers.end()));

    }
    
    answer = st.size();
    
    return answer;
}
/*
종이를 찢어서 소수를 만들것..
예)
1 7 => 2C1 + 2C2 = 2+1 3개
1
17
71

=> 최대 문자열 7개, 7C1+7C2+...7C7 = 5000개밖에 안나오네?
*/