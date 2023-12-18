#include <string>
#include <vector>
#include <climits>
using namespace std;

//완전 탐색 
void recursive(vector<int> &picks,vector<string> &minerals,int idx,int selected,int fatigue,int pick,int &answer)
{
    if(idx>=minerals.size())
    {
        answer=min(fatigue,answer);
        return;
    }
    
    int diamond=0,iron=0,stone=0;
    
    //selected가 5를 넘으면 도깽이 고름 
    if(selected==0)
    {
        if(picks[0]>0)
        {
            picks[0]--;
            recursive(picks,minerals,idx,1,fatigue,0,answer);
            picks[0]++;
        }
        if(picks[1]>0)
        {
            picks[1]--;
            recursive(picks,minerals,idx,1,fatigue,1,answer);
            picks[1]++;
        }
        if(picks[2]>0)
        {
            picks[2]--;
            recursive(picks,minerals,idx,1,fatigue,2,answer);
            picks[2]++;
        } 
        
        if(picks[0]==0&&picks[1]==0&&picks[2]==0)
        {
            answer=min(fatigue,answer);
            return;
        }
    }
    else
    {
        //고른 도깽이로 계산하기
        switch(pick)
        {
            case 0:
                recursive(picks,minerals,idx+1,(selected+1)%6,fatigue+1,pick,answer);
                break;
            case 1:
                if(minerals[idx]=="diamond")
                    recursive(picks,minerals,idx+1,(selected+1)%6,fatigue+5,pick,answer);
                else
                    recursive(picks,minerals,idx+1,(selected+1)%6,fatigue+1,pick,answer);
                break;
            case 2:
                 if(minerals[idx]=="diamond")
                    recursive(picks,minerals,idx+1,(selected+1)%6,fatigue+25,pick,answer);
                else if(minerals[idx]=="iron")
                    recursive(picks,minerals,idx+1,(selected+1)%6,fatigue+5,pick,answer);
                else
                    recursive(picks,minerals,idx+1,(selected+1)%6,fatigue+1,pick,answer);
                break;
        }
      
    }
    

}
int solution(vector<int> picks, vector<string> minerals) {
    int answer = INT_MAX;
    
    recursive(picks,minerals,0,0,0,0,answer);
    
    return answer;
}