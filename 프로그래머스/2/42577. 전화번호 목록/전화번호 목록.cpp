#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
  sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        //문자열의 순서대로 정렬되기 때문에 이전값을 포함하고 있다면 된다.
        //문자열의 개수는 상관 없고, 해당 인덱스의 문자 크기에 따라서 정렬한다.
        
        //0일때에는 못찾음.
        //1일때에는 찾음.
        if (phone_book[i + 1].find(phone_book[i]) == 0) 
        {
            return false;
        }
    }
    
    return true;
}
/*
전화번호 접두어 (보통 접두어 string prefix)
구조대 119
박준영 97
지영석 11

다른 번호의 접두어 인지를 확인하려고함. => 2개이상 같으면 접두어라고 한다. 2개씩 가장 Min(전호번호의)값만큼 잘라서 비교해서 수를 센다.
접두어인 경우가 있으면 false,
그렇지 않다면 true

N*M => 2'000'000 1억 == 1초 이중 반복문도 가능.

1. 폰번호를 길이 순서대로 정렬한다.
2. 길이가 가장 작은 0번 만큼 패턴을 만든다 2~min(Len)
3. 해당 len까지 잘라서 비교를 한다.
4. 같으면 false
5. 다르면 true

*/