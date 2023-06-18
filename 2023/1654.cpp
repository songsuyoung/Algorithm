#include <iostream>

using namespace std;

int main()
{
    
    int K,N;
    cin>>K>>N;
    long long *arr=new long long[K+1];
    long long max=0;
    for(int i=0;i<K;i++){
        cin>>arr[i];
        if(max<arr[i])
            max=arr[i];
    }
    long long left=1,right=max;
    long long mid=0,key=0;
    
    while(left<=right){
        mid=(left+right)/2; //길이로 인식
        long long cnt=0;
        for(int i=0;i<K;i++){
            cnt+=arr[i]/mid;
        }
        
        if(cnt>=N){
            if(key<mid)
                key=mid;
            left=mid+1;
        }else if(cnt<N){
            right=mid-1;
        }
    }
    cout<<key<<'\n';
    return 0;
}