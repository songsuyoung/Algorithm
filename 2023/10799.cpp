/*
    10799 �踷���
    2023.03.05

    **** �˰��� ���� ****
    '('�Ͻ� ���ÿ� ����
    ')'�� ������ ������ '('�� �ִٸ� �������� �߶��� ������, �� ���� �ش� ���ο��� �߶���.
    �׷��� ������, ������ ũ�⸸ŭ �ϳ��� �߻���. 
    ')'�� ������ ������ ')'�� �ִٸ� �Ѱ��� ������ ���� ������ �ν�.
    �׷��� ������ �������� �߶��� ��� 1�� �߻���.

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