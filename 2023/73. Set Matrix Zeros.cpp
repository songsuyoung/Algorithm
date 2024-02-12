class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows[4] = {-1,1,0,0};
        int cols[4] = {0,0,-1,1};

        queue<pair<int,int>> q;

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    q.push(make_pair(i,j));
                }
            }
        }

        while(!q.empty())
        {
            pair<int,int> cur = q.front();

            q.pop();
            for(int i=0;i<4;i++)
            {
                int row = cur.first + rows[i];
                int col = cur.second + cols[i];

                while( row>=0 && row < matrix.size()&& col >= 0 && col < matrix[0].size())
                {
                    matrix[row][col] = 0;
                    
                    row += rows[i];
                    col += cols[i];
                }
            }
        }
    }
};