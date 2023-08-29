/*후위 표기법*/
#include <iostream>
#include <stack>
using namespace std;

int transOperator(char &op){
    if(op=='('||op==')')
        return 0;
    if(op=='-'||op=='+')
        return 1;
    return 2;
    
}

int main()
{
    
    string input;
    cin>>input;
    
    stack<char> s;
    
    for(int i=0;i<input.length();i++){
        
        if(input[i]=='('){
            
            s.push(input[i]);
            
        }else if (input[i] == ')') {
            
            while (s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.pop();

        }else if(input[i]>='A'&&input[i]<='Z'){
            
            cout<<input[i];
            
        }else{
            
            if(s.empty()){
                s.push(input[i]);
            }else{
                while(!s.empty()&&transOperator(s.top())>=transOperator(input[i])){
                    cout<<s.top();
                    s.pop();
                }
                s.push(input[i]);
            }
        }
    }
    
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}