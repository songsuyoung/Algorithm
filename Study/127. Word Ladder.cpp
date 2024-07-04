class Solution {
public:

    int bfs(const string &beginWord,const string &endWord, vector<string>& wordList)
    {
        queue<pair<int,int>> q;

        vector<int> isVisited(wordList.size(),0);

        q.push(make_pair(-1,1));
        while(!q.empty())
        {
            int idx = q.front().first;
            int cnt = q.front().second;
            q.pop();

            string curWord = beginWord;
            if(idx>=0)
            {
                curWord = wordList[idx];
            }

            if(curWord == endWord)
            {
                return cnt;    
            }

            for(int i=0;i<wordList.size();i++)
            {
                if(!isVisited[i])
                {
                    int compareCnt=0;
                    for(int j=0;j<wordList[i].length();j++)
                    {
                        if(curWord[j]==wordList[i][j]) continue;
                        compareCnt++;
                    }

                    if(compareCnt == 1)
                    {
                        q.push(make_pair(i,cnt+1));
                        isVisited[i]=true;
                    }
                }
            }
        }

        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return bfs(beginWord,endWord,wordList);
    }
};