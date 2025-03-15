#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input;
	cin >> input;

	int answer = 1;
	
    string compare = input;
    
    reverse(compare.begin(), compare.end());

    if(compare != input)
    {
        answer = 0;
    }
    
	cout << answer << '\n';
}