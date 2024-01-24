#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <regex>
using namespace std;

int main()
{
	string input;
	getline(cin,input);

	for(int i=0;i<input.length();i++)
	{
		char character = input[i];

		if(character>='a'&&character<='z')
		{
			int eng=(character-'a'+13)%26;
			character='a'+eng;
		}
		else if(character>='A'&&character<='Z')
		{
			int eng=(character-'A'+13)%26;
			character='A'+eng;
		}
		
		cout<<character;
	}
	return 0;
}