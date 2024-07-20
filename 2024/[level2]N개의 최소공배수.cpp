#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std; 

//미리 원소 100 이하에 대해 에라토스의체를 구해놓는다.

int solution(vector<int> arr) {
    int answer = 1;
    
    bool prime[101]={0,};
    
    prime[0]=1,prime[1]=1;
    
    for(int i=2;i<=100;i++)
    {
        if(!prime[i])
        {
            for(int j=2;j*i<=100;j++)
            {
                prime[i*j]=true; //모든 애들을 이미 방문 처리해놓음.
            }
        }
    }
    
    map<int,int> lcm;
    //소인수 분해를 구하기 위해서는 소수가 필요하다.
    //소수를 구하는 알고리즘은 에라토스테네스의 체를 사용한다.
    //i부터 갈 수 있는 모든 숫자를 방문해서 처리하는 것임.
    for(int i=0;i<arr.size();i++)
    {
        map<int,int> cnts; //가지고 있는 수의 개수 중 가장 큰 개수로 업데이트한 후, 개수만큼 반복문 처리를 사용해서 계산을 수행한다.
        
        for(int j=1;j<=arr[i];j++)
        {
            if(prime[j] == false)
            {
                int num=arr[i];
                while(num%j == 0)
                {
                    lcm[j]=max(lcm[j],++cnts[j]);
                    num/=j;
                }
            }
        }
        cout<<'\n';
    }
    
    for(const auto &num : lcm)
    {
        for(int i=0;i<num.second;i++)
        {
            answer*=num.first;    
        }
    }
    return answer;
}