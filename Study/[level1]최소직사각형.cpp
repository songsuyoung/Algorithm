#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 987654321;
    
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    for(int i=0;i<sizes.size();i++)
    {
        int maxVal = max(sizes[i][0],sizes[i][1]);
        int minVal = min(sizes[i][0],sizes[i][1]);
        
        pq1.push(maxVal);
        pq2.push(minVal);
    }
    
    answer= pq1.top()*pq2.top();
    
    return answer;
}