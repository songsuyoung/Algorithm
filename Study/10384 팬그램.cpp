#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
using namespace std;

int main()
{
    int N;
    cin>>N;
    
    getchar();
    for(int i=0;i<N;i++){
        map<char,int> englishCnt;
        string input;
        getline(cin,input);
        
        for(int j=0;j<input.length();j++){
            if((input[j]>='A'&&input[j]<='Z')||(input[j]>='a'&&input[j]<='z')){
                input[j]=tolower(input[j]);
                englishCnt[input[j]]++;
            }
        }
        int minCnt=INT_MAX;
        
        for(char c='a';c<='z';c++){
            minCnt=min(minCnt,englishCnt[c]);
        }
        
        cout<<"Case "<<i+1<<": ";
        switch(minCnt){
            case 0:
            cout<<"Not a pangram\n";
            break;
            case 1:
            cout<<"Pangram!\n";
            break;
            case 2:
            cout<<"Double pangram!!\n";
            break;
            default:
            cout<<"Triple pangram!!!\n";
            break;
        }
    }
    return 0;
}