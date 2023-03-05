/*이 문제는 조합관련 문제임을 알아야한다.*/
#include <iostream>
using namespace std;

int main() {
    int input;
    int N, R;

    cin >> input;

    for (; input > 0; input--) 
    {
        int fact = 1;
        cin >> R >> N; //nCr

        for (int i = 1; i <= R; i++) {
            fact = fact*(N-i+1)/i;
        }
        cout << fact << endl;
    }
}
