#include <bits/stdc++.h>
using namespace std;
/*
tm 구조체
 int tm_sec; 0
 int tm_min; 0
 int tm_hour; 0
 int tm_mday; b
 int tm_mon; a-1(idx 하나를 줄인다)
 int tm_year; => 1900년 이후의 년 수를 입력해야하기 때문에, 2016-1900년을 해준다.
*/
string solution(int a, int b) {
    vector<string> day = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    tm time_in = {0, 0, 0, b, a-1, 2016 - 1900};  // 2016년 1월 1일

    // mktime을 사용하여 요일 계산
    time_t time_temp = mktime(&time_in);

    // time_in 구조체의 tm_wday 필드에서 요일을 가져옴 (0: 일요일, 6: 토요일)
    int day_of_week = time_in.tm_wday;
    //1월 1일 => 5번 인덱스
    //1월 30일
    //2월 29일
    //금 1, 토 2,
    //31,29,31,30,31,30,31,31,30,31,30,31
    return day[day_of_week];
}