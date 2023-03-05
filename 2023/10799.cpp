/*
    10799 쇠막대기
    2023.03.05

    **** 알고리즘 설명 ****
    '('일시 스택에 삽입
    ')'를 만날시 직전에 '('가 있다면 레이저로 잘라진 것으로, 들어간 수는 해당 라인에서 잘라짐.
    그렇기 때문에, 사이즈 크기만큼 하나씩 발생함. 
    ')'를 만날시 직전에 ')'가 있다면 한개의 라인이 끝난 것으로 인식.
    그렇기 때문에 마무리로 잘라진 덩어리 1이 발생함.

*/
#include <iostream>
#include <stack>
using namespace std;

int main() {

    string input;

    cin >> input;
    stack<char> parents;

    int result = 0;
    for (int i = 0; i < input.length(); i++) {
        char tmp = input[i];
        if (tmp != ')') {
            parents.push(tmp);
        }
        else {
            parents.pop();
            if (input[i - 1] == '(')
                result += parents.size();
            else
                result++;
        }
    }
    cout << result << '\n';
}