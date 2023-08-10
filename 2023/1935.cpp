#include <iostream>
#include <map>
#include <stack>
using namespace std;

double calculate(string &input,map<char,double> &trans){
    
    stack<double> buff;
    
    double total=0.0;
    for(int i=0;i<input.length();i++){
        char tmp=input[i];
        
        if(tmp>='A'&&tmp<='Z'){
            buff.push(trans[tmp]);
        }else{
            if(!buff.empty()){
                double op1=buff.top();
                buff.pop();
                double op2=buff.top();
                buff.pop();

                switch(tmp){
                    case '*':
                    total=op2*op1;
                    break;
                    case '/':
                    total=op2/op1;
                    break;
                    case '-':
                    total=op2-op1;
                    break;
                    case '+':
                    total=op2+op1;
                    break;
                }
                buff.push(total);
            }
        }
    }
    
    return buff.top();
    
}
int main()
{
    
    int N; //피연산자 수
    string input; //입력된 후위연산식
    map<char,double> trans;
    string operand="";
    cin>>N;
    cin>>input;
    
    for(int i=0;i<input.length();i++){
        if(input[i]>='A'&&input[i]<='Z'){
            if(!trans.count(input[i])){
                trans[input[i]]=0;
                operand+=input[i];
            }
        }
    }
    
    for(int i=0;i<N;i++){
        double realNums;
        cin>>realNums;
        
        trans[operand[i]]=realNums;
    }
    cout << fixed; //소수점 고정
	cout.precision(2);
    cout<<calculate(input,trans)<<'\n';
    return 0;
}