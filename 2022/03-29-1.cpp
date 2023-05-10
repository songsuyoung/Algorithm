#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    vector<double> score;

    cin>>N;

    for(int i=0;i<N;i++){
	int temp;
	cin>>temp;
	score.push_back(temp);
    }

    int max_score= *max_element(score.begin(),score.end());

    double result=0.0;
    for(int i=0;i<N;i++){

	result+=(double)score[i]/(double)max_score*100;

    }
    cout.precision(100);
    cout<<result/(double)N<<endl;
    return 0;
}
