#include <string>
using namespace std;

string solution(string s) {
    string answer = "";
    int arr[27]; //97%97해서 개수를 넣는 바구니로 이용..
    //초기화
    for(int i=0;i<27;i++)
        arr[i]=0;
    
    int max=0;
    for(int i=0;i<s.length();i++){
        int idxMax=(s[i]-'0')%49;
        
        if(idxMax>max){
            max=idxMax; //max idx값 확인
        }
        arr[idxMax]++;
    }
    for(int i=0;i<27;i++){
        if(arr[i]==1){
            answer+=((i+49)+'0');
        }
    }
    
    return answer;
}