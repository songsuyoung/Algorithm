/*
base case m<=4 || n<=0 m을 출력후 return
base case m>4 return 

recursive case - 최소이기 때문에 루트 n부터 확인하기
1) 결과=n-(루트 n)^2
2) 결과,n-1,m+1 후 호출

나온 작은 m값을 벡터에 삽입 후 algorithm에서 제공해주는 *min_element를 이용해 출력*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


void func(vector<int> &list,int n,int checkingNum,int m){
    if(m<=4&&n==0){
        list.push_back(m);
        return;
    }
    if(m>=4||n<0)
        return;
    
    for(int i=checkingNum;i>0;i--){
        int newN=n-i*i;
        func(list,newN,i,m+1);
    }
}

int main()
{
    int n;
    int min=100000;
    cin>>n;
    vector<int> list;
    func(list,n,sqrt(n),0);
    cout<<*min_element(list.begin(),list.end());
    return 0;
}