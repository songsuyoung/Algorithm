#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);


    string input;
    cin >> input;


    int answer = 0, tmp =1;
    stack<char> st;
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];

        if (ch == '(')
        {
            st.push(ch);
            tmp *= 2;
        }
        else if (ch == '[')
        {
            st.push(ch);
            tmp *= 3;
        }
        else
        {
            if (st.empty()) 
            {
                answer = 0;
                break;
            }

            char top = st.top();
            st.pop();
            if (top == '(')
            {
                if (ch != ')')
                {
                    answer = 0;
                    break;
                }
                
                //성공
                if (input[i - 1] == '(')
                {
                    answer += tmp;
                }

                tmp /= 2;
            }
            else if (top == '[')
            {
                if (ch != ']')
                {
                    answer = 0;
                    break;
                }

                if (input[i - 1] == '[')
                {
                    answer += tmp;
                }

                tmp /= 3;
                //나는 현재 ')'인데 똑같이 닫혀있는 경우

            }
        }
    }

    if (st.empty() == false)
    {
        answer = 0;
    }

    //성공
    cout << answer << '\n';
}