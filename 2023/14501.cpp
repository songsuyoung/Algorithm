#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Task{
  public:
  int Ti; // Ti만큼 소모
  int Pi; // 가격
 
  Task(int Ti,int Pi){
      this->Ti=Ti;
      this->Pi=Pi;
  }
 
};
//vector 1부터 시작할 수 있게한다.
int leaveDay(int N,int day,vector<Task> tasks){
   
    //base case
    //Ti>=N+1 return;
   
    int maxV=0;
    //cur_day=0+
    if(day>N)
        return 0;
    
    for(int i=day;i<N;i++){
        if((tasks[i].Ti+i)<=N)
            maxV=max(maxV,tasks[i].Pi+leaveDay(N,tasks[i].Ti+i,tasks)); //return price
    }
   
    return maxV;

}
int main()
{
    int N;
    cin>>N;
   
    vector<Task> tasks;
    for(int i=0;i<N;i++){
       
        int ti,pi;
        cin>>ti>>pi;
       
        Task t(ti,pi);
        tasks.push_back(t);
    }

    cout<<leaveDay(N,0,tasks);
    return 0;
}