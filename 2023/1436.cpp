#include <iostream>

using namespace std;

int main()
{

    int i=666;
    int N;
    cin>>N;
    int num=0;
    while(true){
        string input = to_string(i);
        for(int k=0;k<input.length()-2;k++){
            int cnt=0;
            for(int j=0;j<3;j++){
                if(input[k+j]-'0'==6)
                    cnt++;
            }
            if(cnt>=3){
                num++;
                break;
            }
        }
        if(num==N){
            break;
        }
        i++;
    }
    
    cout<<i<<'\n';

    return 0;
}