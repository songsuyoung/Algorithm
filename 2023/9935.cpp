/*
    9935 문자열 폭발
    2023.03.06
    
    **** 알고리즘 설명 ****
    문자열을 임시 문자열에 하나씩 추가하다가, 폭발 문자열의 크기보다 크면 가능성 있음으로 for문을 
    이용해 임시문자열의 크기 - 폭발 문자열 크기 + 증분값의 내용물이 같으면 true로 만들어 
    일치하는 문자열을 erase를 이용해 삭제한다.
*/
#include <iostream>
#include <string>

using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    init();
    string input;
    string explline;
    
    cin>>input>>explline;
    
    string tmp;
    
    for(int i=0;i<input.length();i++){
        
        tmp+=input[i];
        bool flag=true;
        if(tmp.length()>=explline.length()){
            for(int i=0;i<explline.length();i++){
                if(tmp[tmp.length()-explline.length()+i]!=explline[i]){
                    flag=false;
                    break;
                }
            }
            
            if(flag){
                tmp.erase(tmp.end() - explline.length(), tmp.end());
            }
        }
        
    }

    if(tmp.length()!=0){
        cout<<tmp<<'\n';
    }else{
        cout<<"FRULA"<<'\n';
    }
    
    return 0;
}
