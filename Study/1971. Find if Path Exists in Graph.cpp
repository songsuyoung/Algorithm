class Solution {
public:

    vector<vector<int>> init(int n,vector<vector<int>>& edges)
    {
        vector<vector<int>> arr(n);
        for(int i=0;i<edges.size();i++)
        {
            arr[edges[i][0]].push_back(edges[i][1]);
            arr[edges[i][1]].push_back(edges[i][0]);
        }
        

        return arr;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<vector<int>> arr = init(n,edges);

        queue<int> q;
        vector<bool> isVisited(n,false);

        q.push(source);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            if(cur == destination) return true;
            if(isVisited[cur]) continue;

            isVisited[cur]=true;
            for(int i = 0; i< arr[cur].size();i++)
            {
                q.push(arr[cur][i]);
            }
        }

        return false;
    }
};