#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person{
  
  int weight,height;
  
  public:
    Person(int w,int h){
        this->weight=w;
        this->height=h;
    }
    
    int getWeight(){
        return weight;
    }
    int getHeight(){
        return height;
    }
    
};
int main()
{
    
    int N;
    cin>>N;
    
    vector<Person> p;
    for(int i=0;i<N;i++){
        int w,h;
        cin>>w>>h;
        
        Person tmp(w,h);
        p.push_back(tmp);
        
    }
    
    for(int i=0;i<p.size();i++){
        bool isWeight=true;
        bool isHeight=true;
        int lank=1;
        for(int j=0;j<p.size();j++){
            if(i==j) continue;
            if(p[i].getWeight()>=p[j].getWeight())
                isWeight=true;
            else
                isWeight=false;
            
            if(p[i].getHeight()>=p[j].getHeight())
                isHeight=true;
            else
                isHeight=false;
                
            if(!isWeight&&!isHeight)
                lank++;
        }
        cout<<lank<<' ';
    }

    return 0;
}