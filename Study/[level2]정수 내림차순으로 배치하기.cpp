#include <string>
#include <algorithm>
using namespace std;

bool compare(char a,char b){
    return a>=b;
}

long long solution(long long n) {
    string input=to_string(n);
    sort(input.begin(),input.end(),compare);
    return stol(input);
}