#include <bits/stdc++.h>
using namespace std;

bool isVisited[20][20][20];
int answer;
void dfs(vector<vector<int>>& tree, vector<int> info, int idx, int sheep, int woolf)
{
    if(idx == 0)
    {
        //루트일 때마다 회수한 수를 확인한다.
        answer = max(answer, sheep);
    }
    
    for(int i=0; i<tree[idx].size(); i++)
    {
        int node = tree[idx][i]; //현재 노드의 위치
        
        if(info[node] == 1)
        {
            //늑대
            if(sheep > woolf + 1 && isVisited[node][sheep][woolf + 1] == false)
            {
                //sheep의 수는 항상 woolf보다 커야함. 그럴 때 지나갈 수 있음.
                isVisited[node][sheep][woolf + 1] = true;
                info[node] = -1;
                dfs(tree, info, node, sheep, woolf + 1);
                info[node] = 1;
                isVisited[node][sheep][woolf + 1] = false;
            }
        }
        else if(info[node] == 0 && isVisited[node][sheep + 1][woolf] == false)
        {
            //항상 지나감
            isVisited[node][sheep + 1][woolf]  = true;
            info[node] = -1;
            dfs(tree, info, node, sheep + 1, woolf);
            info[node] = 0;
            isVisited[node][sheep + 1][woolf]  = false;
        }
        else
        {
            if(isVisited[node][sheep][woolf] == false)
            {
                isVisited[node][sheep][woolf]  = true;
                //이미 회수해서 그냥 지나갈 수 있음.
                dfs(tree, info, node, sheep, woolf);
                isVisited[node][sheep][woolf]  = false;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> tree(info.size());
    
    for(int i=0; i<edges.size(); i++)
    {
        //회수를 위해서 트리를 양방향으로 만든다.
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }
    
    //항상 루트부터 시작하고, 루트는 항상 양이기 때문에 항상 회수할 수 있다.
   isVisited[0][1][0] = true;
    info[0] = -1;
    dfs(tree, info, 0, 1, 0); //0에서 시작
    return answer;
}

/*
edges 를 연결리스트를 사용해서 트리로 만든다.
양일 경우에 회수/ 늑대일 경우에 양의 수를 확인 후 회수 한다. => 즉 늑대>=양일 경우 회수하지 않는다.
이미 회수한 경우는 지나갈 수 있다. (회수할 때마다 -1로 초기화 해준다.)
가장 큰 수를 찾아준다.
*/