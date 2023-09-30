#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> s; //stack으로 사용 예정
    stack<int> buffer; //임시 buf으로 사용 예정
    //순서 1(항상 첫번째 이기때문에 고려안함) -> 2-> 3-> 1번 순인데, 
    int sort[4]={1,3,2,1};
    for(int i=0;i<ingredient.size();i++){
        
        s.push(ingredient[i]);
        if(s.top()==1){//빵이면 지금까지 stack을 pop해야함.
            int sortIdx=0;
            while(!s.empty()&&sort[sortIdx]==s.top()){
                buffer.push(s.top());
                s.pop();
                if(sortIdx>=3){
                    sortIdx=0;
                    answer++;
                    while(!buffer.empty()){
                        buffer.pop();
                    }
                }
                
                sortIdx++;
            }

            while(!buffer.empty()){
                s.push(buffer.top());
                buffer.pop();
            }
        }
    }
    
    return answer;
}