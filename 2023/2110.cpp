#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long maxDis(vector<int> &coordi,int C){
    
    int left=0;//x가 가질 수 있는 가장 작은 값
    int right=coordi[coordi.size()-1]-coordi[0]; //최대 거리로 가질 수 있는 값
    //즉, 10000 ~ 10002 값에서 가질 수 있는 최대 값은 2가 최대임. 마지막 값-처음 값을 빼줌   
    long long mid=0;
    long long midDis=0;
    while(left<=right){
        int cnt=C-1;
        midDis=(right+left)/2; //이진 탐색을 이용해 탐색공간을 줄인다.
        //위 조건을 만족
        int fixed=0;
        for(int i=0;i<coordi.size();i++){
            if(abs(coordi[fixed]-coordi[i])>=midDis){
                cnt--;
                fixed=i;
            }
        }
        if(cnt>0){
            right=midDis-1; //cnt가 0보다 클 경우 길이가 너무 길다는 뜻.
        }else{
            left=midDis+1; //cnt가지 0보다 작을 경우 길이가 너무 짧다는 뜻
            mid=midDis; //같을때 while문을 빠져나오기 때문에 midDis저장
        }
        
    }
    
    return mid;
    
}
int main()
{
    
    int N,C;
    cin>>N>>C;
    vector<int> coordi;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        coordi.push_back(tmp);
    }
    
    stable_sort(coordi.begin(),coordi.end()); //정렬
    
    cout<<maxDis(coordi,C);
    return 0;
}