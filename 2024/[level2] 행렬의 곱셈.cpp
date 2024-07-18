#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(),vector<int>(arr2[0].size()));
    //c1 == r2 같은가?
    //row줄, col줄 계산
    int col=0;
    for(int idx=0;idx<arr2[0].size();idx++)
    {
        for(int r=0;r<arr1.size();r++)
        {
            int sum=0;
            for(int c=0;c<arr1[r].size();c++)
            {
                //c에 대해서 arr2[c][idx]
                sum+=arr2[c][idx] * arr1[r][c];
            }
            answer[r][col%arr2[0].size()]=sum;
        }
        col++;
    }

    return answer;
}