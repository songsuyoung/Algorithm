#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    set<int> number;
    for(int i=0; i<numbers.size(); i++)
    {
        for(int j=i+1; j<numbers.size(); j++)
        {
            number.insert(numbers[i]+numbers[j]);
        }
    }
    
    for(const auto& num : number)
    {
        answer.push_back(num);
    }
    return answer;
}

/*
numbers 서로 다른 인덱스에 있는 두개의 수를 더해서 만들 수 있는 모든 수를 배열에 오름 차순으로 담는다.(set 사용) => 중복 없고, 오름차순
*/