#include <bits/stdc++.h>
using namespace std;

//같은 숫자인지 확인하는 함수
bool isSame(vector<vector<int>>& arr, int& sameVal, pair<int,int> &min, pair<int,int> &max)
{
    //row - first, col - second;
    int first = arr[min.first][min.second];
    for(int i=min.first; i<=max.first; i++) //first x방향 
    {
        for(int j=min.second; j<=max.second; j++)
        {
            if(arr[i][j] != first)
            {
                sameVal = -1;
                return false;
            }
        }
    }
    
    sameVal = first;
    return true;
}
vector<int> answer(2,0);
void recursive(vector<vector<int>> &arr, pair<int,int> min, pair<int,int> max, int n)
{
    if(n < 1)
    {
        return;
    }
    
    int sameVal = -1;

    if(isSame(arr, sameVal, min, max))
    {
        answer[sameVal]++;
    }
    else
    {
        int half = n/2;
        
        recursive(arr, {min.first, min.second}, {min.first + half - 1,min.second + half-1}, half);
        recursive(arr, {min.first, min.second + n/2}, {min.first + half -1,max.second}, half);
        recursive(arr, {min.first + half,min.second}, {max.first,min.second+half-1}, half);
        recursive(arr, {min.first + half,min.second + half}, {max.first,max.second}, half);
    }
}
vector<int> solution(vector<vector<int>> arr) {
    recursive(arr, {0,0}, {arr.size()-1, arr.size()-1}, arr.size());
    return answer;
}

/*
2^n x 2^n 차원의 2차원 배열 -> 쿼드 트리와 같은 방식으로 압축하려고 한다.

1. 압축하고자 하는 등정 영역을 S
2. 만약 S 내부에 있는 모든 숫자가 같은 값이라면 하나의 수로 압축 => 같은 숫자인지 확인하는 함수와 bool 변수, 파라미터로 어떤 값이 같은지를 전달.
3. 그렇지 않다면, S를 정확히 4개의 균일한 정사각형 영역으로 쪼갠 뒤 다시 압축


예)

8x8

재귀의 멈춤 조건 : 작은 값 == 큰 값 1이기 때문에 return.

상
작은 pos값 (0,0)
큰 pos 값 (4-1,4-1) 즉(n/2-1, n/2 -1);

하
작은 pos값 (4,0) 즉(n/2,0);
칸 pos값 (8-1,4-1) 즉(n-1,0);

좌
작은 pos값 (0,4) 즉 (0, n/2);
큰 pos값 (4-1,7) 즉 (n/2-1, n-1); 

우
작은 pos값 (4,4) 즉 (n/2,n/2)
큰 값 (8-1,8-1) 즉 (n-1, n-1);
*/