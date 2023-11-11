#include <iostream>
#include <vector>
using namespace std;
int recursive(int N,vector<int> &v,int dp[][3],int idx,int cnt)
{
    if(cnt>2||N<idx) //마지막 이상은 더하지 않는다.
        return -1;
    
    if(idx==N)
        return v[idx]; //항상 마지막 계단은 밟아야함.
    //한 계단씩
    int oneStep,twoStep;

    if(dp[idx][cnt]!=0) {
        return dp[idx][cnt];
    }
    oneStep=recursive(N,v,dp,idx+1,cnt+1); //자기 선택한 점수 한칸 짜리 못감
    twoStep=recursive(N,v,dp,idx+2,1); //2칸 짜리 선택

    if(oneStep==-1&&twoStep==-1)
    {
        return -1; //둘다 -1이면 둘다 계산되어서는 안돼!!!
    }
    
    dp[idx][cnt]=oneStep>twoStep? oneStep+v[idx]:twoStep+v[idx];
    return dp[idx][cnt];
}

int main()
{
    int N;
    cin>>N;

    vector<int> v(N+1,0);
    int dp[303][3]={0,}; //이유 : 선택했을 때 / 안했을 때 구분해서 1칸 갔을때 1칸 간 정보 / 2칸 간 정보가 다르기 때문입니다. 슨생님.
    //계단을 한칸으로도 갈 수 있고, 두 칸으로도 갈 수 있습니다. 슨생님
    //그래서, 한칸갔을때 정보와 두 칸 갔을 때 정보가 달라지게 됩니다.
    //예를 들어, 25를 기준으로 들겠습니다.
    //25 기준으로 20으로 갈 수 있는경우의 2가지가 있습니다. 1 칸 - 1칸 2칸 그래서 
    //dp도 3칸이 필요합니다.
    //그...그렇쿤.
    for(int i=1;i<=N;i++)
    {
        int tmp;
        cin>>tmp;

        v[i]=tmp;
    }

    int oneStep=recursive(N,v,dp,1,1)+v[0]; //자기 선택한 점수 한칸 짜리 못감
    int twoStep=recursive(N,v,dp,2,1)+v[0]; //2칸 짜리 선택
    
    cout<<(oneStep>twoStep? oneStep:twoStep)<<'\n';
}