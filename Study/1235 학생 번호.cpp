
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){

    int N;
    cin>>N;

    vector<string> input;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        input.push_back(tmp);
    }
    vector<string> compare;
    string tmp="";
    for(int i=0;i<N;i++){
        int len=input[i].length()-1;
        tmp=input[i][len]; //-1은 \n임.
        compare.push_back(tmp);
    }
    int cnt=1;
    for(int i=input[0].length()-2;i>=0;i--,cnt++){ //100
        
        int notCompare=0;
        map<string,int> number;
        
        for(int j=0;j<N;j++){
            //포함되지 않으면 count 센다.
            if(!number.count(compare[j])){
                number[compare[j]]++;
                notCompare++;
            }
            compare[j]+=input[j][i];
        }
        
        if(notCompare>=N){
            break;
        }
        //셋다 포함 안되어 있으면 break -> 최소 k
    }
    cout<<cnt<<'\n';
}