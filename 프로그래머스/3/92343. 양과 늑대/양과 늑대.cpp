#include <bits/stdc++.h>

using namespace std;

int isVisited[20][20][20];

int answer = 0;
void dfs(vector<int> graph[], vector<int> info, int cur, int sheep, int woolf)
{
    //root일 때 최대 개수를 확인해봄 -> 여러번 방문해야하기 때문에 max값을 root에서 확인해주어야함.
    if(cur==0)
    {
        answer = max(answer, sheep);
    }
    
    for(int i=0; i<graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if(info[next] == 0)
        {
            //다음 위치로 이동했을 때 sheep 개수가 이미 방문 했음 갔다온거임
            if(isVisited[next][sheep + 1][woolf]) continue;
            info[next] = -1; //양 회수
            isVisited[next][sheep+1][woolf] = true;
            //이전으로 돌아가야하기 때문에 방문처리, 현재 위치 - 양의 개수 - 늑대의 개수로 체크해야한다.
            dfs(graph, info, next, sheep + 1, woolf);
            info[next] = 0; //양 회수
            isVisited[next][sheep+1][woolf] = false;
        }
        else if(info[next] == 1)
        {
            //늑대임
            if(sheep > woolf + 1)
            {
                if(isVisited[next][sheep][woolf+1]) continue;
                isVisited[next][sheep][woolf+1] = true;
                info[next] = -1; //늑대 회수
                //이동 가능함.
                dfs(graph,info, next, sheep, woolf + 1);
                info[next] = 1; //늑대 돌려놓음
                isVisited[next][sheep][woolf+1] = false;
            }
        }
        else
        {
            if(isVisited[next][sheep][woolf]) continue;
            //이미 회수하고 다른 늑대나 양을 찾기 위해 지나감
            isVisited[next][sheep][woolf] = true;
            dfs(graph, info, next, sheep, woolf);
            isVisited[next][sheep][woolf] = false;
            
        }
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    // 그래프 생성
    vector<int> graph[20];
    
    //info는 부모의 정보, edgs 는 부모-자식간의 관계
    for(int i=0; i<edges.size(); i++)
    {
        // 양방향 그래프로 성생
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]); 
    }
    
    //root는 항상 양이 존재한다.
    info[0] = -1; //첫번째 양은 항상 회수
    isVisited[0][1][0] = true;
    dfs(graph, info, 0, 1, 0); //양의 개수, 늑대의 개수
    return answer;
}

/*
2진 트리 모양 초원 늑대, 양
루트 노드에서 출발하여 각 노드를 돌아다니며 양을 모으려고 함.
노드에 방문 할 때마다 양과 늑대가 당신을 따라옴.
내가 모은 양의 수 <= 늑대 수 

=> 완전탐색 왜냐하면, 모든 노드를 방문 할 때까지 양과 늑대의 수를 알 수 없음. 즉 모두 방문해 봐야한다.
=> 각 노드의 양의 개수와 늑대의 개수를 적고 양이 max가 되는 노드를 선택한다.

*/