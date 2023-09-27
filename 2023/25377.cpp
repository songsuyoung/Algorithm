#include <iostream>
#include <climits>
using namespace std;

int main(){

    int N;
    cin>>N;

    int min=INT_MAX;

    for(int i=0;i<N;i++){

        int DurationOfTime;
        int IncommingTime;

        cin>>DurationOfTime>>IncommingTime;

        if(DurationOfTime<=IncommingTime){
            if(min>=IncommingTime){
                min=IncommingTime;
            }
        }
    }

    if(min==INT_MAX)
        cout<<"-1\n";
    else
        cout<<min<<'\n';
    return 0;
}