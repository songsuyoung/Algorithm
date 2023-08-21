#include <iostream>

using namespace std;

int main()
{
    
    int N,M;
    
    cin>>N>>M;
    
    int matrix[1000][1000];
    int max=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>matrix[i][j];
        }
    }
    
    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++){
            
            if(r<N||r+1<N||r+2<N||r+3<N){
                int sum=matrix[r][c]+matrix[r+1][c]+matrix[r+2][c]+matrix[r+3][c];
                max=max<=sum? sum:max;
            }
            
            if(c<M||c+1<M||c+2<M||c+3<M){
                int sum=matrix[r][c]+matrix[r][c+1]+matrix[r][c+2]+matrix[r][c+3];
                max=max<=sum? sum:max;
            }
            
            if(r<N||r+1<N||c<M||c+1<M){
                int sum=matrix[r][c]+matrix[r+1][c]+matrix[r][c+1]+matrix[r+1][c+1];
                max=max<=sum? sum:max;
                
            }
            
            if(r<N||r+1<N||r+2<N||c-1>=0||c-1<N||c<N){
                int sum=matrix[r][c]+matrix[r+1][c]+matrix[r+2][c]+matrix[r+2][c-1];
                max=max<=sum? sum:max;
            }
            
            if(r<N||r+1<N||r+2<N||c<M||c+1<M){
                int sum1=matrix[r][c]+matrix[r+1][c]+matrix[r+2][c]+matrix[r+2][c+1];
                int sum2=matrix[r][c]+matrix[r][c+1]+matrix[r+1][c+1]+matrix[r+2][c+1];
                int sum3=matrix[r][c]+matrix[r][c+1]+matrix[r+1][c]+matrix[r+2][c];
                
                sum1=sum1>sum2? sum1:sum2;
                sum1=sum1>sum3? sum1:sum3;
                
                max=max<=sum1? sum1:max;
            }
            
            if(r<N||r-1>=0||r<N||c<M||c+1<M||c+2<M){
                int sum=matrix[r][c]+matrix[r][c+1]+matrix[r][c+2]+matrix[r-1][c+2];
                max=max<=sum? sum:max;
            }
            
            if(r<N||r+1<N||c<M||c+1<M||c+2<M){
                int sum1=matrix[r][c]+matrix[r+1][c]+matrix[r+1][c+1]+matrix[r+1][c+2];
                int sum2=matrix[r][c]+matrix[r][c+1]+matrix[r][c+2]+matrix[r+1][c+2];
                int sum3=matrix[r][c]+matrix[r][c+1]+matrix[r][c+2]+matrix[r+1][c];
                
                sum1=sum1>sum2? sum1:sum2;
                sum1=sum1>sum3? sum1:sum3;
                max=max<=sum1? sum1:max;
            }
            
            if(r<N||c<M||c+1<M||c+2<M){
                int sum=matrix[r][c]+matrix[r][c+1]+matrix[r][c+2]+matrix[r+1][c+1];
                max=max<=sum? sum:max;
            }
            
            
            if(r<N||r+1<N||c<M||c-1>=0||c+1<M){
                int sum=matrix[r][c]+matrix[r+1][c-1]+matrix[r+1][c]+matrix[r+1][c+1];
                max=max<=sum? sum:max;
            }
            
            if(r<N||r+1<N||r+2<N||c<M||c+1<M){
                int sum=matrix[r][c]+matrix[r+1][c]+matrix[r+1][c+1]+matrix[r+2][c];
                max=max<=sum? sum:max;
            }
            
            if(r<N||r+1<N||r+2<N||c-1>=0||c<M){
                int sum=matrix[r][c]+matrix[r+1][c]+matrix[r+2][c]+matrix[r+1][c-1];
                max=max<=sum? sum:max;
            }
            
            if(r<N||r+1<N||r+2<N||c+1<M){
                int sum=matrix[r][c]+matrix[r+1][c]+matrix[r+1][c+1]+matrix[r+2][c+1];
                max=max<=sum? sum:max;
            }
            
            if(r<N||r+1<N||r+2<N||c-1>=0||c-1<M){
                int sum=matrix[r][c]+matrix[r+1][c-1]+matrix[r+1][c]+matrix[r+2][c-1];
                max=max<=sum? sum:max;
            }
            
            if(r<N||r+1<N||c<M||c+1<M||c+2<M){
                int sum=matrix[r][c]+matrix[r][c+1]+matrix[r+1][c+1]+matrix[r+1][c+2];
                max=max<=sum? sum:max;
            }
            
            if(r<N||r+1<N||c-1>=0||c-1<M||c+1<M){
               int sum=matrix[r][c]+matrix[r][c+1]+matrix[r+1][c-1]+matrix[r+1][c];
                max=max<=sum? sum:max;
            }
        }
    }
    
    cout<<max<<'\n';
    return 0;
}