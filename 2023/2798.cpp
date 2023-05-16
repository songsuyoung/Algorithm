/*
 조건 1) sum 합이 M에 가장 가까운 최대값이어야함.
 조건 2) 모든 합을 검사하긴 해야하지만, 같은 idx는 제외해야함. 
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    int M,N;
    /*sum(3개의 합)<=M&&sum<- max여야함...*/
    cin>>N>>M;
    
    vector<int> blackjack;
    for(int i=0;i<N;i++){
        
        int tmp;
        cin>>tmp;
        
        blackjack.push_back(tmp);
    }
    
    int sum=0;
    int max=0;
    for(int i=0;i<N;i++){
        
        for(int j=0;j<N;j++){
            
            if(i==j)
                continue;
                
            for(int k=0;k<N;k++){
                if(k==i||k==j){
                    continue;
                }
                sum=blackjack[i]+blackjack[j]+blackjack[k];
                if(sum<=M&&sum>max){
                    max=sum;
                }
            }
        }
    }
    
    cout<<max<<'\n';
    

    return 0;
}
