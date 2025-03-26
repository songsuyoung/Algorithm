#include <bits/stdc++.h>
using namespace std;

bool compare(char &a, char& b)
{
    return a>b;
}
string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end(), compare);
    answer = s;
    return answer;
}

/*
문자열 s 큰것부터 작은 순으로 정렬(내림차순)
*/