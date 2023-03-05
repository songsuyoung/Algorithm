/*
 * 	2812 크게 만들기
 * 	2023.03.05
 *
 * 	**** 알고리즘 설명 ****
 *	스택이나 덱에 수를 삽입한 후, 큰수보다 이전수가 작으면 모두 제거하는
 *	방식을 이용함.
 * 	*/
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    int N,K;
    
    cin>>N>>K;
    
    string input;
    
    cin>>input;
    deque<char> maxNums;
    
    for(int i=0;i<N;i++){
        
        while(!maxNums.empty()&&maxNums.back()<input[i]&&K){
            maxNums.pop_back();
            K--;
        }
        maxNums.push_back(input[i]);
    }
    
    for(int i=0;i<maxNums.size()-K;i++){
        cout<<maxNums[i];
    }
    cout<<'\n';
}
