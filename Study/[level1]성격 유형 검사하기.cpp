#include <string>
#include <map>
#include <vector>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    //순서를 저장
    map<int,char> Indicators={{1,'R'},{2,'T'},{3,'C'},{4,'F'},{5,'J'},{6,'M'},{7,'A'},{8,'N'}};
    map<char,int> types={{'R',0},{'T',0},{'C',0},{'F',0},{'J',0},{'A',0},{'M',0},{'N',0}};
    int scores[7]={3,2,1,0,1,2,3}; //성격 유형 점수표
    
    for(int i=0;i<choices.size();i++){
        //0 idx => 0 1 2으로
        //1 idx => 3 4 5으로
        int idx=choices[i]-1;
       
        switch(idx){
            case 0:
            case 1:
            case 2:
                types[survey[i][0]]+=scores[idx];
                break;
            case 4:
            case 5:
            case 6:
                types[survey[i][1]]+=scores[idx];
                break;
        }
        
    }
    
    for(int i=1;i<Indicators.size();i+=2){
        if(types[Indicators[i]]>types[Indicators[i+1]]){
            answer+=Indicators[i];
        }else if(types[Indicators[i]]==types[Indicators[i+1]]){
            if(Indicators[i]<Indicators[i+1]){
                answer+=Indicators[i];
            }else{
                answer+=Indicators[i+1];
            }
        }else{
            answer+=Indicators[i+1];
        }
    }
    return answer;
}