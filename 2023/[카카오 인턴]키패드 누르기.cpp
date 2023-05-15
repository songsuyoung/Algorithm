#include <string>
#include <vector>
#include <iostream>

using namespace std;

class coordination{
  private:
    int x,y;
    
  public:
    coordination(int _x,int _y){
        x=_x;
        y=_y;
    }
    
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    
    void setCoordination(int _x,int _y){
        x=_x;
        y=_y;
    }
};

string solution(vector<int> numbers, string hand) {
    
    string answer = "";
    
    coordination left(3,0),right(3,2);
    
    for(int i=0;i<numbers.size();i++){
        int x=(numbers[i]-1)/3;
        int y=(numbers[i]-1)%3;
        
        if(numbers[i]==0){
            x=3;
            y=1;
        }
        
        cout<<x<<' '<<y<<'\n';
        if(numbers[i]==1||numbers[i]==4||numbers[i]==7){
            answer+="L"; 
            left.setCoordination(x,y);
        }
        else if(numbers[i]==3||numbers[i]==6||numbers[i]==9){
            answer+="R";
            right.setCoordination(x,y);
        }else{
            int leftX=abs(left.getX()-x);
            int leftY=abs(left.getY()-y);
            
            int rightX=abs(right.getX()-x);
            int rightY=abs(right.getY()-y);
            
            if((leftX+leftY)==(rightX+rightY)){
                if(hand=="right"){
                    right.setCoordination(x,y);
                    answer+='R';
                }else{
                    left.setCoordination(x,y);
                    answer+='L';
                }
            }
            else if((leftX+leftY)<(rightX+rightY)){
                left.setCoordination(x,y);
                answer+='L';
            }else{
                right.setCoordination(x,y);
                answer+='R';
            }
        }
    }
    return answer;
}