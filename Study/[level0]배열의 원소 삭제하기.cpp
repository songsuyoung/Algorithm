#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {

    for(int i=0;i<delete_list.size();i++){
        arr.erase(remove(arr.begin(),arr.end(),delete_list[i]),arr.end());
        //remove함수는 delete_list에 해당하는 값을 뒤로 보내게되고,
        //erase함수는 뒤에 있는 값을 삭제함으로써 알고리즘 진행
    }
    return arr;
}
