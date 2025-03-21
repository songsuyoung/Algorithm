#include <bits/stdc++.h>
using namespace std;

void split(string expression, vector<char> &expOp, vector<long long> &num)
{
    string str = "";
    for(int i=0; i<expression.size(); i++)
    {
        if(expression[i] == '*'||expression[i] == '-' || expression[i]=='+')
        {
            num.push_back(stoi(str));
            expOp.push_back(expression[i]);
            str = "";
        }
        else
        {
            str += expression[i];
        }
    }
     num.push_back(stoi(str));
}

long long solution(string expression) {
    long long answer = 0;
    
    //만들 수 있는 연산자 => 미리 정의
    char op[6][3] = {{'*','+','-'},{'*','-','+'},{'+','*','-'},{'+','-','*'}, {'-','+','*'},{'-','*','+'}};
    
    //split한다.
    vector<long long> numBuffer;
    vector<char> expOpBuffer;
    
    split(expression, expOpBuffer, numBuffer);
    
    for(int i=0; i<6; i++)
    {
        vector<long long> num = numBuffer;
        vector<char> expOp = expOpBuffer;
        for(int k=0; k<3; k++)
        {
            while(find(expOp.begin(), expOp.end(), op[i][k]) != expOp.end())
            {
                int j = find(expOp.begin(), expOp.end(), op[i][k]) - expOp.begin(); //실제 인덱스를 가져올 수 있음
                
                //연산 j - j+1 연산을 수행
                long long res=0;
                switch(op[i][k])
                {
                    case '+':
                        res = num[j] + num[j+1];
                        break;
                    case '*':
                        res = num[j] * num[j+1];
                        break;
                    case '-':
                        res = num[j] - num[j+1];
                        break;
                }

                        //j와 j+1 제거하고 j위치에 삽입
                int num1 = num[j], num2 = num[j+1];
                
                num.erase(num.begin()+j);
                num.erase(num.begin()+j);
                expOp.erase(expOp.begin()+j);
                //remove(num.begin(), num.end(), num1);
                //예를 들어) 200 + 100 => 300 이어야하는데...
                // 100 + 100 + 100 +는 0,1번 idx
                // 200 + 100 =>실제로 idx = 0번이지만.... 1번으로 인식해 1-2랑 계산을 해버림..
                num.insert(num.begin()+j, res);
                //한번만 연산하구나,.?
            }
        }
        answer = max(answer, abs(num[0]));
    }
    
    return answer;
}

/*
IT 라이언
해커톤 대회에 참여한 자는 숫자들과 3가지 연산으로 + - * 만으로 이루어진 연산 수식이 전달
전달받은 수식에 포함된 연산자의 우선순위를 자유롭게 재정의하여 만들 수 있는 큰 숫자를 제출
예)

100-200*300-500+20
+ > - > *
=> 절대값 사용.

100-(200*300)-500+20
=> 100-60000-500+20
=> 100-60000-(500+20)
=> 100-60000-520
=> ..

숫자를 저장
100 200 300 500 20
-*-+

우선 순위를 정한다. * + -/ * - + / + - * ... 6가지

split 한다.
100 200 300 500 20
   +   *   -  +

연산자 배열에서 우선순위 1위를 찾는다. 
* 먼저 : * idx = 1번 num[idx] * num[idx+1]
* num[idx]와 num[idx+1] 뺀다 => 그 자리에 result값을 넣는다.

문제점 : expression은 안없어지는데.. num은 계속 사라짐... => 

100-200*300-500+20
100-60000-500+20
-연산을 수행할 때 
0 1 2

-59900-480 => 이거일 때


+100+100+100
200
*/