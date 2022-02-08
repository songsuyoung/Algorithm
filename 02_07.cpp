/*이 문제는 mod연산과 제곱근의 이해가 필요한것 같다.*/
#include <iostream>
using namespace std;

int main() {
    int input;
    int A, B, result;

    cin >> input;

    while(input){
        input--;
        cin >> A >> B;
        result = 1;

        for (int j = 0; j < B; j++) {
            result = (result * A) % 10;
        }

        result == 0 ? cout << 10 << endl : cout << result << endl;
    }
}