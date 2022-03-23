#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){


        vector<int> odd;

        for(int i=0;i<7;i++){
                int num;
                cin>>num;

                if(num%2!=0){
                        odd.push_back(num);
                }
        }

        if(odd.size()==0){
                cout<<-1<<endl;
                return 0;
        }
        cout<<accumulate(odd.begin(),odd.end(),0)<<endl;
        cout<<*min_element(odd.begin(),odd.end())<<endl;

        return 0;


}