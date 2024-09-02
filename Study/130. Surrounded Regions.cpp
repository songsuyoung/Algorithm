class Solution {
public:

    void bfs(vector<vector<char>> &board,int r,int c)
    {
        int rows[4] = {-1,1,0,0};
        int cols[4] = {0,0,-1,1};

        vector<vector<bool>> isVisited(board.size(),vector<bool>(board[0].size()));

        queue<pair<int,int>> q;

        q.push({r,c});
        while(!q.empty())
        {
            pair<int,int> cur = q.front();

            q.pop();
            if(isVisited[cur.first][cur.second]) continue;
            if(cur.first==0||cur.second==0||cur.first==board.size()-1||cur.second==board[0].size()-1) return;
            isVisited[cur.first][cur.second]= true;
            for(int i=0;i<4;i++)
            {
                int nr=rows[i]+cur.first;
                int nc=cols[i]+cur.second;

                if(nr<0||nc<0||nr>=board.size()||nc>=board[0].size()||board[nr][nc] == 'X') continue;

                q.push({nr,nc});
            }
        }

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(isVisited[i][j])
                {
                    board[i][j]='X';
                }
            }
        }   
        
    }
    void solve(vector<vector<char>>& board) {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='O')
                {
                    bfs(board,i,j);
                }
            }
        }

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                cout<<board[i][j];
            }
            cout<<'\n';
        }
    }
};