#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;

bool isPrimeNum(long long n){
    
    if(n<=1)
        return false;
    
    for(long long i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    }
    return true;
}

string transform(int n,int k){
    string result="";
    while(n!=0){
        result+=to_string(n%k); //정수는 리틀인디언 -> 거꾸로 나오는 이슈 발생 
        n/=k;// string으로 해야하는 이유는 조건 검사를 위해
    }
    reverse(result.begin(),result.end()); //빅인디언,,
    return result;
}

void splitCondi(string input,int &cnt){
    istringstream s(input);
    string buf;
    vector<string> results;
    
    while(getline(s,buf,'0')){
        if(buf.empty())
            continue;
        results.push_back(buf);
    }
    
    for(long long i=0;i<results.size();i++){
        if(isPrimeNum(stol(results[i]))){
            cnt++;
        }
    }
}

int solution(int n, int k) {
    int answer = 0;
    
    string transResult=transform(n,k);
    splitCondi(transResult,answer); 
    
    return answer;
}