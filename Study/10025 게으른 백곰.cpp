#include <iostream>

using namespace std;

int main() {

	int N, K;
	cin >> N >> K;
	int ice[1000015]={0,};
	
    int maxXi=0;
	for (int i = 0; i < N; i++) {
		int gi, xi;
		cin >> gi >> xi;

		ice[xi] = gi; //좌표 = 얼음
        if(maxXi<xi)
            maxXi=xi;
	}

    int sum=0;
    int forwardIdx,idx=0;

    int end=K*2>1000000? 1000000:K*2;
    for(forwardIdx=0;forwardIdx<=end;forwardIdx++){
        sum+=ice[forwardIdx];
    }
    //현재 idx=K
    int maxSum=sum;
    
    while(forwardIdx<=maxXi){
        sum-=ice[idx++];
        sum+=ice[forwardIdx++];
        maxSum=max(maxSum,sum);
    }
    
    cout<<maxSum<<'\n';
}