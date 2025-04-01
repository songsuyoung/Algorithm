#include <bits/stdc++.h>
using namespace std;

long long solution(string expression) {
    long long answer = LLONG_MIN;
    
    char op[6][3] = {{'*','+','-'},{'*','-','+'},{'+','*','-'},{'+','-','*'},{'-','+','*'},{'-','*','+'}};
    
    vector<long long> num;
    vector<char> expOP;
    
    string numToInt="";
    for(int i=0; i<expression.size(); i++)
    {
        if(expression[i]>='0' && expression[i]<='9')
        {
            numToInt+=expression[i];
        }
        else
        {
            if(numToInt.empty() == false)
            {
                num.push_back(stoll(numToInt));
            }
            numToInt ="";
            expOP.push_back(expression[i]);
        }
    }
    if(numToInt.empty() == false)
    {
        num.push_back(stoll(numToInt));
    }
    
    for(int i=0; i<6; i++)
    {
        vector<long long> numBuf = num;
        vector<char> expOPBuf = expOP;
        for(int j=0; j<3; j++)
        {   
            while(find(expOPBuf.begin(), expOPBuf.end(), op[i][j])!=expOPBuf.end())
            {
               int idx = find(expOPBuf.begin(), expOPBuf.end(), op[i][j]) - expOPBuf.begin();
                
                long long num1 = numBuf[idx];
                long long num2 = numBuf[idx+1];
                
                long long sum = 0;
                switch(op[i][j])
                {
                    case '*':
                        sum = num1 * num2;
                        break;
                    case '-':
                        sum = num1 - num2;
                        break;
                    case '+':
                        sum = num1 + num2;
                        break;
                }
                
                numBuf.erase(numBuf.begin()+idx);
                numBuf.erase(numBuf.begin()+idx);
                
                expOPBuf.erase(expOPBuf.begin()+idx);
                
                numBuf.insert(numBuf.begin() + idx, sum);
            }
        }
        answer= max(answer, abs(numBuf[0]));
    }
    return answer;
}

/*

1. 연산자 우선순위를 정하기 위한 조합
    => 3개밖에 없기때문에 직접 패턴을 만드는게 좋음.
2. expression을 숫자, 연산자 로 나누어서 vector에 저장한다.
2. 우선 순위를 먼저 계산을 수행하는데, 음수는 음수, 덧셈은 덧셈이 더 나올 수 있기 때문에 1개의 결과값이 나올 때까지 반복
*/
