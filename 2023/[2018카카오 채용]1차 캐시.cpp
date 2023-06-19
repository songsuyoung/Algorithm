#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <boost/algorithm/string.hpp>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string> cache;
    
    if(cacheSize==0)
        return 5*cities.size();
    
    for(int i=0;i<cities.size();i++){
        string search=cities[i];
        boost::algorithm::to_upper(search);
        
        vector<string>::iterator it=find(cache.begin(),cache.end(),search);
        if(cache.size()<cacheSize){
            if(it!=cache.end()){
                answer+=1;
                cache.erase(it);
                cache.push_back(search);
                continue;
            }
            answer+=5;
            cache.push_back(search);
        }else{
            if(it!=cache.end()){
                answer+=1;
                cache.erase(it);
                cache.push_back(search);
                continue;
            }
            answer+=5;
            cache.erase(cache.begin());
            cache.push_back(search);
        }
    }
    return answer;
}
