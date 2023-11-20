#include <iostream>
#include <queue>
using namespace std;

int main()
{
    bool isVisited[1000001]={};

    int F,S,G,U,D;
    cin>>F>>S>>G>>U>>D;

    queue<pair<int,int>> q;

    q.push(make_pair(S,0));
    int up=0,down=0;
    int cnt=0;

    while(!q.empty())
    {
        int curPos=q.front().first;
        cnt=q.front().second;
        q.pop();


        if(isVisited[curPos])
            continue;

        if(curPos==G)
        {
            cout<<cnt<<'\n';
            return 0;
        }
        isVisited[curPos]=true;

        //U버튼을 누른다
        if(U!=0)
        {
            up=curPos+U;
            if(up<=F)
            {
                q.push(make_pair(up,cnt+1));
            }
        }
        if(D!=0)
        {
            down=curPos-D;
            if(down>=1)
            {   
                //D버튼을 누른다.
                q.push(make_pair(down,cnt+1));   
            }
        }
    }

    if(q.empty()) cout<<"use the stairs\n";

    return 0;
}
