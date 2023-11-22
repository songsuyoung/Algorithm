#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    long long sum=sequence[0];
    pair<int,int> idx=make_pair(0,sequence.size());
    unsigned long left=0,right=0;
    while(left<=right)
    {   
        if(left>=sequence.size()||right>=sequence.size()) break;
        
        if(k<sum)
        {
            sum-=sequence[left++];
        }
        else if(k==sum)
        {
            //cout<<idx.first<<' '<<idx.second<<'\n';
            //left idx,right idx넣기
            //현재 idx.second-idx.first 크기가 큰지 right-left가 작은지를 넣는다.
            if((idx.second-idx.first)>(right-left))
            {
                idx=make_pair(left,right); //변경. 
            }
            sum-=sequence[left++];
        }
        else //k>sum -> right++
        {
            sum+=sequence[++right];
        }
    }
    answer.push_back(idx.first);
    answer.push_back(idx.second);
    return answer;
}